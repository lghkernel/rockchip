#pragma once

#include <string>

namespace rtsp {

enum class VideoCodec {
    H264,
    H265
};

class RTSPFileStreamer {
public:
    RTSPFileStreamer(const std::string& streamName,
                     const std::string& filePath,
                     VideoCodec codec,
                     unsigned short port = 8554);

    bool start();
    void stop();

private:
    std::string fStreamName;
    std::string fFilePath;
    VideoCodec fCodec;
    unsigned short fPort;

    class Impl;
    Impl* fImpl;
};

} // namespace rtsp
