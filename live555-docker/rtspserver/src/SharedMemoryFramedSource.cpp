#include "SharedMemoryFramedSource.hh"
#include <cstring>
#include <unistd.h>

SharedMemoryFramedSource* SharedMemoryFramedSource::createNew(UsageEnvironment& env) {
  return new SharedMemoryFramedSource(env);
}

SharedMemoryFramedSource::SharedMemoryFramedSource(UsageEnvironment& env)
  : FramedSource(env), shm_(nullptr) {
  shm_ = shm_create_or_open(/*create=*/false);
  if (!shm_) {
    env << "Failed to open shared memory.\n";
  }
}

SharedMemoryFramedSource::~SharedMemoryFramedSource() {
  shm_cleanup(false);
}

void SharedMemoryFramedSource::doStopGettingFrames() {
  // no-op
}

void SharedMemoryFramedSource::doGetNextFrame() {
  if (!shm_) {
    handleClosure();
    return;
  }

  size_t naluSize = 0;
  static uint8_t buffer[MAX_NALU_SIZE];

  if (!read_nalu_from_shm(shm_, buffer, &naluSize)) {
    envir().taskScheduler().scheduleDelayedTask(1000, (TaskFunc*)FramedSource::afterGetting, this);
    return;
  }

  // Remove 00 00 00 01 start code (assumed 4 bytes)
  const unsigned startCodeSize = 4;
  if (naluSize <= startCodeSize) {
    handleClosure();
    return;
  }

  unsigned payloadSize = naluSize - startCodeSize;
  if (payloadSize > fMaxSize) {
    fFrameSize = fMaxSize;
    fNumTruncatedBytes = payloadSize - fMaxSize;
  } else {
    fFrameSize = payloadSize;
    fNumTruncatedBytes = 0;
  }

  gettimeofday(&fPresentationTime, nullptr);
  std::memcpy(fTo, buffer + startCodeSize, fFrameSize);

  FramedSource::afterGetting(this);
}