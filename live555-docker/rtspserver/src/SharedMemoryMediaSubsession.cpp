#include "SharedMemoryMediaSubsession.hh"
#include "SharedMemoryFramedSource.hh"
#include <H264VideoRTPSink.hh>
#include <H264VideoStreamFramer.hh>

SharedMemoryMediaSubsession* SharedMemoryMediaSubsession::createNew(UsageEnvironment& env) {
  return new SharedMemoryMediaSubsession(env);
}

SharedMemoryMediaSubsession::SharedMemoryMediaSubsession(UsageEnvironment& env)
  : OnDemandServerMediaSubsession(env, True) {}

SharedMemoryMediaSubsession::~SharedMemoryMediaSubsession() {}

FramedSource* SharedMemoryMediaSubsession::createNewStreamSource(unsigned, unsigned& estBitrate) {
  estBitrate = 500; // kbps, tùy bạn
  FramedSource* shmSource = SharedMemoryFramedSource::createNew(envir());
  return H264VideoStreamFramer::createNew(envir(), shmSource);
}

RTPSink* SharedMemoryMediaSubsession::createNewRTPSink(Groupsock* rtpGroupsock,
                                                       unsigned char rtpPayloadTypeIfDynamic,
                                                       FramedSource*) {
  return H264VideoRTPSink::createNew(envir(), rtpGroupsock, rtpPayloadTypeIfDynamic);
}
