// #include <liveMedia.hh>
// #include <BasicUsageEnvironment.hh>
// #include "SharedMemoryFramedSource.hh"
// #include <thread>
// #include <chrono>

// // Subclass để gắn source vào RTSP Server
// class SharedMemoryH264Subsession : public OnDemandServerMediaSubsession {
// public:
//     static SharedMemoryH264Subsession* createNew(UsageEnvironment& env) {
//         return new SharedMemoryH264Subsession(env);
//     }

// protected:
//     SharedMemoryH264Subsession(UsageEnvironment& env)
//         : OnDemandServerMediaSubsession(env, True /*reuse*/) {}

//     virtual FramedSource* createNewStreamSource(unsigned /*clientSessionId*/, unsigned& estBitrate) override {
//         estBitrate = 500; // kbps, giả lập
//         return SharedMemoryFramedSource::createNew(envir());
//     }

//     virtual RTPSink* createNewRTPSink(Groupsock* rtpGroupsock,
//                                       unsigned char rtpPayloadTypeIfDynamic,
//                                       FramedSource* inputSource) override {
//         return H264VideoRTPSink::createNew(envir(), rtpGroupsock, rtpPayloadTypeIfDynamic);
//     }
// };

// int main(int argc, char** argv) {
//     // Bước 1: Init môi trường
//     TaskScheduler* scheduler = BasicTaskScheduler::createNew();
//     UsageEnvironment* env = BasicUsageEnvironment::createNew(*scheduler);

//     // Bước 2: Tạo RTSP Server
//     RTSPServer* rtspServer = RTSPServer::createNew(*env, 8554);
//     if (!rtspServer) {
//         *env << "❌ Lỗi tạo RTSP Server: " << env->getResultMsg() << "\n";
//         exit(1);
//     }

//     // Bước 3: Tạo media session /stream
//     ServerMediaSession* sms = ServerMediaSession::createNew(*env, "stream", "SharedMemStream",
//         "Stream truyền từ SharedMemory", True /*SSM*/);
//     sms->addSubsession(SharedMemoryH264Subsession::createNew(*env));
//     rtspServer->addServerMediaSession(sms);

//     char* url = rtspServer->rtspURL(sms);
//     *env << "✅ RTSP stream đang chạy tại: " << url << "\n";
//     delete[] url;

//     // Bước 4: Giả lập producer đẩy frame vào shm (test)
//     auto* shmSource = SharedMemoryFramedSource::createNew(*env);

//     std::thread fakeProducer([env, shmSource]() {
//         while (true) {
//             // NAL unit giả lập (IDR frame: 0x65)
//             std::vector<u_int8_t> fakeNAL = {0x00, 0x00, 0x00, 0x01, 0x65, 0x88, 0x84, 0x21, 0x43};
//             {
//                 std::lock_guard<std::mutex> lock(shmSource->fMutex);
//                 shmSource->fFrameQueue.push(fakeNAL);
//             }
//             env->taskScheduler().triggerEvent(shmSource->fEventTriggerId, shmSource);
//             std::this_thread::sleep_for(std::chrono::milliseconds(40)); // ~25fps
//         }
//     });
//     fakeProducer.detach();

//     // Bước 5: Vòng lặp RTSP
//     env->taskScheduler().doEventLoop();

//     return 0;
// }
#include <rtspshm/RTSPFileStreamer.hh>
#include <chrono>
#include <thread>
#include <iostream>

int main() {
    std::cout << "Starting RTSP file streamer...\n";

    // Stream từ file .h264 đã có sẵn
    rtsp::RTSPFileStreamer streamer("stream264", "/root/videos/sample.h264", rtsp::VideoCodec::H264, 8554);
    
    if (!streamer.start()) {
        std::cerr << "Failed to start RTSP streamer.\n";
        return 1;
    }

    std::cout << "Streaming ready on rtsp://<your-ip>:8554/stream264\n";
    std::cout << "Press Ctrl+C to stop...\n";

    // Giữ chương trình sống
    std::this_thread::sleep_for(std::chrono::hours(1));
    return 0;
}
