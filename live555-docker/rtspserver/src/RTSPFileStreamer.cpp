
#include "RTSPFileStreamer.hh"
#include <liveMedia.hh>
#include <BasicUsageEnvironment.hh>
#include <thread>

namespace rtsp {

class RTSPFileStreamer::Impl {
public:
    Impl(const std::string& name, const std::string& file, VideoCodec codec, unsigned short port)
        : streamName(name), filePath(file), codec(codec), port(port) {}

    bool start() {
        scheduler = BasicTaskScheduler::createNew();
        env = BasicUsageEnvironment::createNew(*scheduler);

        RTSPServer* server = RTSPServer::createNew(*env, port);
        if (!server) {
            *env << "Failed to create RTSP Server: " << env->getResultMsg() << "\n";
            return false;
        }

        ServerMediaSession* sms = ServerMediaSession::createNew(*env, streamName.c_str(), streamName.c_str(), "RTSP File Stream");
        sms->addSubsession(new FileSubsession(*env, filePath, codec));
        server->addServerMediaSession(sms);

        std::string url = server->rtspURL(sms);
        *env << "Stream ready at: " << url.c_str() << "\n";

        loopThread = std::thread([this]() {
            env->taskScheduler().doEventLoop(); // blocking
        });

        return true;
    }

    void stop() {
        if (env) env->reclaim();
        if (scheduler) delete scheduler;
        if (loopThread.joinable()) loopThread.detach();
    }

private:
    class FileSubsession : public OnDemandServerMediaSubsession {
    public:
        FileSubsession(UsageEnvironment& env, const std::string& path, VideoCodec codec)
            : OnDemandServerMediaSubsession(env, False), filePath(path), codec(codec) {}

    protected:
        FramedSource* createNewStreamSource(unsigned, unsigned& estBitrate) override {
            estBitrate = 5000;
            FramedSource* source = ByteStreamFileSource::createNew(envir(), filePath.c_str());
            if (!source) return nullptr;

            if (codec == VideoCodec::H264) {
                return H264VideoStreamFramer::createNew(envir(), source);
            } else {
                return H265VideoStreamFramer::createNew(envir(), source);
            }
        }

        RTPSink* createNewRTPSink(Groupsock* rtpGroupsock, unsigned char payloadType, FramedSource* input) override {
            if (codec == VideoCodec::H264) {
                return H264VideoRTPSink::createNew(envir(), rtpGroupsock, payloadType);
            } else {
                return H265VideoRTPSink::createNew(envir(), rtpGroupsock, payloadType);
            }
        }

    private:
        std::string filePath;
        VideoCodec codec;
    };

    std::string streamName;
    std::string filePath;
    VideoCodec codec;
    unsigned short port;

    TaskScheduler* scheduler = nullptr;
    UsageEnvironment* env = nullptr;
    std::thread loopThread;
};

// ====== Wrapper Public API ======

RTSPFileStreamer::RTSPFileStreamer(const std::string& streamName,
                                   const std::string& filePath,
                                   VideoCodec codec,
                                   unsigned short port)
    : fStreamName(streamName), fFilePath(filePath), fCodec(codec), fPort(port) {
    fImpl = new Impl(streamName, filePath, codec, port);
}

bool RTSPFileStreamer::start() {
    return fImpl->start();
}

void RTSPFileStreamer::stop() {
    fImpl->stop();
    delete fImpl;
    fImpl = nullptr;
}

} // namespace rtsp
