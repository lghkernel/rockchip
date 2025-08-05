#ifndef SHARED_MEMORY_FRAMED_SOURCE_HH
#define SHARED_MEMORY_FRAMED_SOURCE_HH

#include <FramedSource.hh>
#include "shared_mem.hh"

class SharedMemoryFramedSource : public FramedSource {
public:
  static SharedMemoryFramedSource* createNew(UsageEnvironment& env);

protected:
  SharedMemoryFramedSource(UsageEnvironment& env);
  virtual ~SharedMemoryFramedSource();

private:
  virtual void doGetNextFrame();
  virtual void doStopGettingFrames();

  SharedMemory* shm_;
};
#endif