#ifndef SHM_MEDIA_SUBSESSION_HH
#define SHM_MEDIA_SUBSESSION_HH

#include <OnDemandServerMediaSubsession.hh>

class SharedMemoryMediaSubsession : public OnDemandServerMediaSubsession {
public:
  static SharedMemoryMediaSubsession* createNew(UsageEnvironment& env);

protected:
  SharedMemoryMediaSubsession(UsageEnvironment& env);
  virtual ~SharedMemoryMediaSubsession();

protected:
  virtual FramedSource* createNewStreamSource(unsigned clientSessionId, unsigned& estBitrate);
  virtual RTPSink* createNewRTPSink(Groupsock* rtpGroupsock, unsigned char rtpPayloadTypeIfDynamic,
                                    FramedSource* inputSource);
};

#endif
