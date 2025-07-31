#include "SharedMemoryFramedSource.hh"
#include <GroupsockHelper.hh> // for gettimeofday
#include <cstring>

SharedMemoryFramedSource* SharedMemoryFramedSource::createNew(UsageEnvironment& env) {
    return new SharedMemoryFramedSource(env);
}

SharedMemoryFramedSource::SharedMemoryFramedSource(UsageEnvironment& env)
    : FramedSource(env) {
    fEventTriggerId = envir().taskScheduler().createEventTrigger(onTrigger);
}

SharedMemoryFramedSource::~SharedMemoryFramedSource() {
    envir().taskScheduler().deleteEventTrigger(fEventTriggerId);
}

void SharedMemoryFramedSource::doGetNextFrame() {
    std::lock_guard<std::mutex> lock(fMutex);

    if (!fFrameQueue.empty()) {
        deliverFrame();
    } else {
        // Không có frame → chờ trigger
    }
}

// Hàm được gọi bởi triggerEvent()
void SharedMemoryFramedSource::onTrigger(void* clientData) {
    ((SharedMemoryFramedSource*)clientData)->deliverFrame();
}

void SharedMemoryFramedSource::deliverFrame() {
    std::lock_guard<std::mutex> lock(fMutex);

    if (fFrameQueue.empty() || fNumTruncatedBytes != 0 || fTo == nullptr) return;

    std::vector<u_int8_t> frame = std::move(fFrameQueue.front());
    fFrameQueue.pop();

    // Copy dữ liệu vào buffer mà live555 cấp phát
    unsigned int frameSize = frame.size();
    if (frameSize > fMaxSize) {
        fNumTruncatedBytes = frameSize - fMaxSize;
        frameSize = fMaxSize;
    } else {
        fNumTruncatedBytes = 0;
    }

    std::memcpy(fTo, frame.data(), frameSize);
    fFrameSize = frameSize;
    gettimeofday(&fPresentationTime, nullptr);

    // Báo live555 là đã xong 1 frame
    FramedSource::afterGetting(this);
}