#include <liveMedia.hh>
#include <BasicUsageEnvironment.hh>
#include "SharedMemoryMediaSubsession.hh"

int main(int argc, char** argv) {
  // 1. Tạo Task Scheduler và Environment
  TaskScheduler* scheduler = BasicTaskScheduler::createNew();
  UsageEnvironment* env = BasicUsageEnvironment::createNew(*scheduler);

  // 2. Tạo RTSP Server trên cổng 8554
  RTSPServer* rtspServer = RTSPServer::createNew(*env, 8554);
  if (rtspServer == nullptr) {
    *env << "❌ Lỗi: Không thể tạo RTSP server: " << env->getResultMsg() << "\n";
    exit(1);
  }

  // 3. Tạo MediaSession với subsession lấy từ SharedMemory
  char const* streamName = "stream";
  char const* description = "Streaming H264 từ Shared Memory";

  ServerMediaSession* sms = ServerMediaSession::createNew(*env, streamName, streamName, description);
  sms->addSubsession(SharedMemoryMediaSubsession::createNew(*env));
  rtspServer->addServerMediaSession(sms);

  // 4. Log URL để người dùng kết nối
  char* url = rtspServer->rtspURL(sms);
  *env << "✅ RTSP Stream ready tại: " << url << "\n";
  delete[] url;

  // 5. Vòng lặp xử lý sự kiện RTSP
  env->taskScheduler().doEventLoop(); // chạy mãi mãi

  // Không đến đây, nhưng nếu muốn dọn dẹp:
  // Medium::close(rtspServer);
  // delete env;
  // delete scheduler;

  return 0;
}
