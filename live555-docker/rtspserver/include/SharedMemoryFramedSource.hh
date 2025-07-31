#pragma once

#include <FramedSource.hh>
#include <mutex>
#include <queue>

class SharedMemoryFramedSource : public FramedSource {
public:
    static SharedMemoryFramedSource* createNew(UsageEnvironment& env);

protected:
    SharedMemoryFramedSource(UsageEnvironment& env);
    virtual ~SharedMemoryFramedSource();

private:
    virtual void doGetNextFrame() override;

    // Gọi khi trigger báo có frame mới
    static void onTrigger(void* clientData);
    void deliverFrame();

private:
    EventTriggerId fEventTriggerId;
    std::mutex fMutex;

    // Giả lập buffer nhận từ shared memory
    std::queue<std::vector<u_int8_t>> fFrameQueue;
};