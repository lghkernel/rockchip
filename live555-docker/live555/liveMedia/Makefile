INCLUDES = -Iinclude -I../UsageEnvironment/include -I../groupsock/include
PREFIX = /usr/local
LIBDIR = $(PREFIX)/lib
##### Change the following for your environment:
COMPILE_OPTS =		$(INCLUDES) -I/usr/local/include -I. -O2 -DSOCKLEN_T=socklen_t -D_LARGEFILE_SOURCE=1 -D_FILE_OFFSET_BITS=64
C =			c
C_COMPILER =		cc
C_FLAGS =		$(COMPILE_OPTS) $(CPPFLAGS) $(CFLAGS)
CPP =			cpp
CPLUSPLUS_COMPILER =	c++
CPLUSPLUS_FLAGS =	$(COMPILE_OPTS) -Wall -DBSD=1 $(CPPFLAGS) $(CXXFLAGS)
OBJ =			o
LINK =			c++ -o
LINK_OPTS =		-L. $(LDFLAGS)
CONSOLE_LINK_OPTS =	$(LINK_OPTS)
LIBRARY_LINK =		ar cr 
LIBRARY_LINK_OPTS =	
LIB_SUFFIX =			a
LIBS_FOR_CONSOLE_APPLICATION = -lssl -lcrypto
LIBS_FOR_GUI_APPLICATION =
EXE =
##### End of variables to change

NAME = libliveMedia
LIVEMEDIA_LIB = $(NAME).$(LIB_SUFFIX)
ALL = $(LIVEMEDIA_LIB)
all:	$(ALL)

.$(C).$(OBJ):
	$(C_COMPILER) -c $(C_FLAGS) $<
.$(CPP).$(OBJ):
	$(CPLUSPLUS_COMPILER) -c $(CPLUSPLUS_FLAGS) $<

MP3_SOURCE_OBJS = MP3FileSource.$(OBJ) MP3Transcoder.$(OBJ) MP3ADU.$(OBJ) MP3ADUdescriptor.$(OBJ) MP3ADUinterleaving.$(OBJ) MP3ADUTranscoder.$(OBJ) MP3StreamState.$(OBJ) MP3Internals.$(OBJ) MP3InternalsHuffman.$(OBJ) MP3InternalsHuffmanTable.$(OBJ) MP3ADURTPSource.$(OBJ)
MPEG_SOURCE_OBJS = MPEG1or2Demux.$(OBJ) MPEG1or2DemuxedElementaryStream.$(OBJ) MPEGVideoStreamFramer.$(OBJ) MPEG1or2VideoStreamFramer.$(OBJ) MPEG1or2VideoStreamDiscreteFramer.$(OBJ) MPEG4VideoStreamFramer.$(OBJ) MPEG4VideoStreamDiscreteFramer.$(OBJ) H264or5VideoStreamFramer.$(OBJ) H264or5VideoStreamDiscreteFramer.$(OBJ) H264VideoStreamFramer.$(OBJ) H264VideoStreamDiscreteFramer.$(OBJ) H265VideoStreamFramer.$(OBJ) H265VideoStreamDiscreteFramer.$(OBJ) MPEGVideoStreamParser.$(OBJ) MPEG1or2AudioStreamFramer.$(OBJ) MPEG1or2AudioRTPSource.$(OBJ) MPEG4LATMAudioRTPSource.$(OBJ) MPEG4ESVideoRTPSource.$(OBJ) MPEG4GenericRTPSource.$(OBJ) $(MP3_SOURCE_OBJS) MPEG1or2VideoRTPSource.$(OBJ) MPEG2TransportStreamMultiplexor.$(OBJ) MPEG2TransportStreamFromPESSource.$(OBJ) MPEG2TransportStreamFromESSource.$(OBJ) MPEG2TransportStreamFramer.$(OBJ) MPEG2TransportStreamAccumulator.$(OBJ) ADTSAudioFileSource.$(OBJ) ADTSAudioStreamDiscreteFramer.$(OBJ)
#JPEG_SOURCE_OBJS = JPEGVideoSource.$(OBJ) JPEGVideoRTPSource.$(OBJ) JPEG2000VideoStreamFramer.$(OBJ) JPEG2000VideoStreamParser.$(OBJ) JPEG2000VideoRTPSource.$(OBJ)
JPEG_SOURCE_OBJS = JPEGVideoSource.$(OBJ) JPEGVideoRTPSource.$(OBJ) JPEG2000VideoRTPSource.$(OBJ)
H263_SOURCE_OBJS = H263plusVideoRTPSource.$(OBJ) H263plusVideoStreamFramer.$(OBJ) H263plusVideoStreamParser.$(OBJ)
AC3_SOURCE_OBJS = AC3AudioStreamFramer.$(OBJ) AC3AudioRTPSource.$(OBJ)
DV_SOURCE_OBJS = DVVideoStreamFramer.$(OBJ) DVVideoRTPSource.$(OBJ)
MP3_SINK_OBJS = MP3ADURTPSink.$(OBJ)
MPEG_SINK_OBJS = MPEG1or2AudioRTPSink.$(OBJ) $(MP3_SINK_OBJS) MPEG1or2VideoRTPSink.$(OBJ) MPEG4LATMAudioRTPSink.$(OBJ) MPEG4GenericRTPSink.$(OBJ) MPEG4ESVideoRTPSink.$(OBJ)
JPEG_SINK_OBJS = JPEGVideoRTPSink.$(OBJ) JPEG2000VideoRTPSink.$(OBJ)
H263_SINK_OBJS = H263plusVideoRTPSink.$(OBJ)
H264_OR_5_SINK_OBJS = H264or5VideoRTPSink.$(OBJ) H264VideoRTPSink.$(OBJ) H265VideoRTPSink.$(OBJ)
DV_SINK_OBJS = DVVideoRTPSink.$(OBJ)
AC3_SINK_OBJS = AC3AudioRTPSink.$(OBJ)

MISC_SOURCE_OBJS = MediaSource.$(OBJ) FramedSource.$(OBJ) FramedFileSource.$(OBJ) FramedFilter.$(OBJ) ByteStreamFileSource.$(OBJ) ByteStreamMultiFileSource.$(OBJ) ByteStreamMemoryBufferSource.$(OBJ) BasicUDPSource.$(OBJ) DeviceSource.$(OBJ) AudioInputDevice.$(OBJ) WAVAudioFileSource.$(OBJ) $(MPEG_SOURCE_OBJS) $(JPEG_SOURCE_OBJS) $(H263_SOURCE_OBJS) $(AC3_SOURCE_OBJS) $(DV_SOURCE_OBJS) AMRAudioSource.$(OBJ) AMRAudioFileSource.$(OBJ) InputFile.$(OBJ) StreamReplicator.$(OBJ)
MISC_SINK_OBJS = MediaSink.$(OBJ) FileSink.$(OBJ) BasicUDPSink.$(OBJ) AMRAudioFileSink.$(OBJ) H264or5VideoFileSink.$(OBJ) H264VideoFileSink.$(OBJ) H265VideoFileSink.$(OBJ) OggFileSink.$(OBJ) $(MPEG_SINK_OBJS) $(JPEG_SINK_OBJS) $(H263_SINK_OBJS) $(H264_OR_5_SINK_OBJS) $(DV_SINK_OBJS) $(AC3_SINK_OBJS) VorbisAudioRTPSink.$(OBJ) TheoraVideoRTPSink.$(OBJ) VP8VideoRTPSink.$(OBJ) VP9VideoRTPSink.$(OBJ) GSMAudioRTPSink.$(OBJ) SimpleRTPSink.$(OBJ) AMRAudioRTPSink.$(OBJ) T140TextRTPSink.$(OBJ) OutputFile.$(OBJ) RawVideoRTPSink.$(OBJ)
MISC_FILTER_OBJS = uLawAudioFilter.$(OBJ)
TRANSPORT_STREAM_TRICK_PLAY_OBJS = MPEG2IndexFromTransportStream.$(OBJ) MPEG2TransportStreamIndexFile.$(OBJ) MPEG2TransportStreamTrickModeFilter.$(OBJ)

RTP_SOURCE_OBJS = RTPSource.$(OBJ) MultiFramedRTPSource.$(OBJ) SimpleRTPSource.$(OBJ) H261VideoRTPSource.$(OBJ) H264VideoRTPSource.$(OBJ) H265VideoRTPSource.$(OBJ) QCELPAudioRTPSource.$(OBJ) AMRAudioRTPSource.$(OBJ) VorbisAudioRTPSource.$(OBJ) TheoraVideoRTPSource.$(OBJ) VP8VideoRTPSource.$(OBJ) VP9VideoRTPSource.$(OBJ) RawVideoRTPSource.$(OBJ)
RTP_SINK_OBJS = RTPSink.$(OBJ) MultiFramedRTPSink.$(OBJ) AudioRTPSink.$(OBJ) VideoRTPSink.$(OBJ) TextRTPSink.$(OBJ)
RTP_INTERFACE_OBJS = RTPInterface.$(OBJ)
RTP_OBJS = $(RTP_SOURCE_OBJS) $(RTP_SINK_OBJS) $(RTP_INTERFACE_OBJS)

RTCP_OBJS = RTCP.$(OBJ) rtcp_from_spec.$(OBJ)
GENERIC_MEDIA_SERVER_OBJS = GenericMediaServer.$(OBJ)
RTSP_OBJS = RTSPServer.$(OBJ) RTSPServerRegister.$(OBJ) RTSPClient.$(OBJ) RTSPCommon.$(OBJ) RTSPRegisterSender.$(OBJ)
SIP_OBJS = SIPClient.$(OBJ)

SESSION_OBJS = MediaSession.$(OBJ) ServerMediaSession.$(OBJ) PassiveServerMediaSubsession.$(OBJ) OnDemandServerMediaSubsession.$(OBJ) FileServerMediaSubsession.$(OBJ) MPEG4VideoFileServerMediaSubsession.$(OBJ) H264VideoFileServerMediaSubsession.$(OBJ) H265VideoFileServerMediaSubsession.$(OBJ) H263plusVideoFileServerMediaSubsession.$(OBJ) WAVAudioFileServerMediaSubsession.$(OBJ) AMRAudioFileServerMediaSubsession.$(OBJ) MP3AudioFileServerMediaSubsession.$(OBJ) MPEG1or2VideoFileServerMediaSubsession.$(OBJ) MPEG1or2FileServerDemux.$(OBJ) MPEG1or2DemuxedServerMediaSubsession.$(OBJ) MPEG2TransportFileServerMediaSubsession.$(OBJ) ADTSAudioFileServerMediaSubsession.$(OBJ) DVVideoFileServerMediaSubsession.$(OBJ) AC3AudioFileServerMediaSubsession.$(OBJ) MPEG2TransportUDPServerMediaSubsession.$(OBJ) ProxyServerMediaSession.$(OBJ)

QUICKTIME_OBJS = QuickTimeFileSink.$(OBJ) QuickTimeGenericRTPSource.$(OBJ)
AVI_OBJS = AVIFileSink.$(OBJ)

MATROSKA_FILE_OBJS = MatroskaFile.$(OBJ) MatroskaFileParser.$(OBJ) EBMLNumber.$(OBJ) MatroskaDemuxedTrack.$(OBJ)
MATROSKA_SERVER_MEDIA_SUBSESSION_OBJS = MatroskaFileServerMediaSubsession.$(OBJ) MP3AudioMatroskaFileServerMediaSubsession.$(OBJ)
MATROSKA_RTSP_SERVER_OBJS = MatroskaFileServerDemux.$(OBJ) $(MATROSKA_SERVER_MEDIA_SUBSESSION_OBJS)
MATROSKA_OBJS = $(MATROSKA_FILE_OBJS) $(MATROSKA_RTSP_SERVER_OBJS)

OGG_FILE_OBJS = OggFile.$(OBJ) OggFileParser.$(OBJ) OggDemuxedTrack.$(OBJ)
OGG_SERVER_MEDIA_SUBSESSION_OBJS = OggFileServerMediaSubsession.$(OBJ)
OGG_RTSP_SERVER_OBJS = OggFileServerDemux.$(OBJ) $(OGG_SERVER_MEDIA_SUBSESSION_OBJS)
OGG_OBJS = $(OGG_FILE_OBJS) $(OGG_RTSP_SERVER_OBJS)

TRANSPORT_STREAM_DEMUX_OBJS = MPEG2TransportStreamDemux.$(OBJ) MPEG2TransportStreamDemuxedTrack.$(OBJ) MPEG2TransportStreamParser.$(OBJ) MPEG2TransportStreamParser_PAT.$(OBJ) MPEG2TransportStreamParser_PMT.$(OBJ) MPEG2TransportStreamParser_STREAM.$(OBJ)

HLS_OBJS = HLSSegmenter.$(OBJ)

SECURITY_OBJS = TLSState.$(OBJ) MIKEY.$(OBJ) SRTPCryptographicContext.$(OBJ) HMAC_SHA1.$(OBJ)

MISC_OBJS = BitVector.$(OBJ) StreamParser.$(OBJ) DigestAuthentication.$(OBJ) ourMD5.$(OBJ) Base64.$(OBJ) Locale.$(OBJ)

LIVEMEDIA_LIB_OBJS = Media.$(OBJ) $(MISC_SOURCE_OBJS) $(MISC_SINK_OBJS) $(MISC_FILTER_OBJS) $(RTP_OBJS) $(RTCP_OBJS) $(GENERIC_MEDIA_SERVER_OBJS) $(RTSP_OBJS) $(SIP_OBJS) $(SESSION_OBJS) $(QUICKTIME_OBJS) $(AVI_OBJS) $(TRANSPORT_STREAM_TRICK_PLAY_OBJS) $(MATROSKA_OBJS) $(OGG_OBJS) $(TRANSPORT_STREAM_DEMUX_OBJS) $(HLS_OBJS) $(SECURITY_OBJS) $(MISC_OBJS)

$(LIVEMEDIA_LIB): $(LIVEMEDIA_LIB_OBJS) \
    $(PLATFORM_SPECIFIC_LIB_OBJS)
	$(LIBRARY_LINK)$@ $(LIBRARY_LINK_OPTS) \
		$(LIVEMEDIA_LIB_OBJS) $(LIBS_FOR_LIVEMEDIA_LIB)

Media.$(CPP):		include/Media.hh
include/Media.hh:	include/liveMedia_version.hh
MediaSource.$(CPP):	include/MediaSource.hh
include/MediaSource.hh:		include/Media.hh
FramedSource.$(CPP):	include/FramedSource.hh
include/FramedSource.hh:	include/MediaSource.hh
FramedFileSource.$(CPP): include/FramedFileSource.hh
include/FramedFileSource.hh:	include/FramedSource.hh
FramedFilter.$(CPP):	include/FramedFilter.hh
include/FramedFilter.hh:	include/FramedSource.hh
RTPSource.$(CPP):	include/RTPSource.hh
include/RTPSource.hh:		include/FramedSource.hh include/RTPInterface.hh include/SRTPCryptographicContext.hh
include/RTPInterface.hh:	include/Media.hh include/TLSState.hh
MultiFramedRTPSource.$(CPP):	include/MultiFramedRTPSource.hh include/RTCP.hh
include/MultiFramedRTPSource.hh:	include/RTPSource.hh
SimpleRTPSource.$(CPP):	include/SimpleRTPSource.hh
include/SimpleRTPSource.hh:	include/MultiFramedRTPSource.hh
H261VideoRTPSource.$(CPP):	include/H261VideoRTPSource.hh
include/H261VideoRTPSource.hh:	include/MultiFramedRTPSource.hh
H264VideoRTPSource.$(CPP):      include/H264VideoRTPSource.hh include/Base64.hh
include/H264VideoRTPSource.hh:  include/MultiFramedRTPSource.hh
H265VideoRTPSource.$(CPP):      include/H265VideoRTPSource.hh
include/H265VideoRTPSource.hh:  include/MultiFramedRTPSource.hh
QCELPAudioRTPSource.$(CPP):	include/QCELPAudioRTPSource.hh include/MultiFramedRTPSource.hh include/FramedFilter.hh
include/QCELPAudioRTPSource.hh:		include/RTPSource.hh
AMRAudioRTPSource.$(CPP):	include/AMRAudioRTPSource.hh include/MultiFramedRTPSource.hh
include/AMRAudioRTPSource.hh:		include/RTPSource.hh include/AMRAudioSource.hh
VorbisAudioRTPSource.$(CPP):	include/VorbisAudioRTPSource.hh include/Base64.hh
include/VorbisAudioRTPSource.hh:	include/MultiFramedRTPSource.hh
TheoraVideoRTPSource.$(CPP):	include/TheoraVideoRTPSource.hh
include/TheoraVideoRTPSource.hh:	include/MultiFramedRTPSource.hh
VP8VideoRTPSource.$(CPP):	include/VP8VideoRTPSource.hh
include/VP8VideoRTPSource.hh:	include/MultiFramedRTPSource.hh
VP9VideoRTPSource.$(CPP):	include/VP9VideoRTPSource.hh
include/VP9VideoRTPSource.hh:	include/MultiFramedRTPSource.hh
RawVideoRTPSource.$(CPP):	include/RawVideoRTPSource.hh
include/RawVideoRTPSource.hh:	include/MultiFramedRTPSource.hh
ByteStreamFileSource.$(CPP):	include/ByteStreamFileSource.hh include/InputFile.hh
include/ByteStreamFileSource.hh:	include/FramedFileSource.hh
ByteStreamMultiFileSource.$(CPP):	include/ByteStreamMultiFileSource.hh
include/ByteStreamMultiFileSource.hh:	include/ByteStreamFileSource.hh
ByteStreamMemoryBufferSource.$(CPP):	include/ByteStreamMemoryBufferSource.hh
include/ByteStreamMemoryBufferSource.hh:	include/FramedSource.hh
BasicUDPSource.$(CPP):		include/BasicUDPSource.hh
include/BasicUDPSource.hh:	include/FramedSource.hh
DeviceSource.$(CPP):	include/DeviceSource.hh
include/DeviceSource.hh:	include/FramedSource.hh
AudioInputDevice.$(CPP):	include/AudioInputDevice.hh
include/AudioInputDevice.hh:	include/FramedSource.hh
WAVAudioFileSource.$(CPP):	include/WAVAudioFileSource.hh include/InputFile.hh
include/WAVAudioFileSource.hh:	include/AudioInputDevice.hh
MPEG1or2Demux.$(CPP):	include/MPEG1or2Demux.hh include/MPEG1or2DemuxedElementaryStream.hh StreamParser.hh
include/MPEG1or2Demux.hh:		include/FramedSource.hh
include/MPEG1or2DemuxedElementaryStream.hh:	include/MPEG1or2Demux.hh
StreamParser.hh:	include/FramedSource.hh
MPEG1or2DemuxedElementaryStream.$(CPP):	include/MPEG1or2DemuxedElementaryStream.hh
MPEGVideoStreamFramer.$(CPP):	MPEGVideoStreamParser.hh
MPEGVideoStreamParser.hh:	StreamParser.hh include/MPEGVideoStreamFramer.hh
include/MPEGVideoStreamFramer.hh:	include/FramedFilter.hh
MPEG1or2VideoStreamFramer.$(CPP):	include/MPEG1or2VideoStreamFramer.hh MPEGVideoStreamParser.hh
include/MPEG1or2VideoStreamFramer.hh:	include/MPEGVideoStreamFramer.hh
MPEG1or2VideoStreamDiscreteFramer.$(CPP):	include/MPEG1or2VideoStreamDiscreteFramer.hh
include/MPEG1or2VideoStreamDiscreteFramer.hh:	include/MPEG1or2VideoStreamFramer.hh
MPEG4VideoStreamFramer.$(CPP):	include/MPEG4VideoStreamFramer.hh MPEGVideoStreamParser.hh include/MPEG4LATMAudioRTPSource.hh
include/MPEG4VideoStreamFramer.hh:	include/MPEGVideoStreamFramer.hh
MPEG4VideoStreamDiscreteFramer.$(CPP):	include/MPEG4VideoStreamDiscreteFramer.hh
include/MPEG4VideoStreamDiscreteFramer.hh:	include/MPEG4VideoStreamFramer.hh
H264or5VideoStreamFramer.$(CPP):	include/H264or5VideoStreamFramer.hh MPEGVideoStreamParser.hh include/BitVector.hh
include/H264or5VideoStreamFramer.hh:	include/MPEGVideoStreamFramer.hh
H264or5VideoStreamDiscreteFramer.$(CPP):	include/H264or5VideoStreamDiscreteFramer.hh
include/H264or5VideoStreamDiscreteFramer.hh:	include/H264or5VideoStreamFramer.hh
H264VideoStreamFramer.$(CPP):	include/H264VideoStreamFramer.hh
include/H264VideoStreamFramer.hh:	include/H264or5VideoStreamFramer.hh
H264VideoStreamDiscreteFramer.$(CPP):	include/H264VideoStreamDiscreteFramer.hh
include/H264VideoStreamDiscreteFramer.hh:	include/H264VideoStreamFramer.hh
H265VideoStreamFramer.$(CPP):	include/H265VideoStreamFramer.hh
include/H265VideoStreamFramer.hh:	include/H264or5VideoStreamFramer.hh
H265VideoStreamDiscreteFramer.$(CPP):	include/H265VideoStreamDiscreteFramer.hh
include/H265VideoStreamDiscreteFramer.hh:	include/H265VideoStreamFramer.hh
MPEGVideoStreamParser.$(CPP):	MPEGVideoStreamParser.hh
MPEG1or2AudioStreamFramer.$(CPP):	include/MPEG1or2AudioStreamFramer.hh StreamParser.hh MP3Internals.hh
include/MPEG1or2AudioStreamFramer.hh:	include/FramedFilter.hh
MPEG1or2AudioRTPSource.$(CPP):	include/MPEG1or2AudioRTPSource.hh
include/MPEG1or2AudioRTPSource.hh:	include/MultiFramedRTPSource.hh
MPEG4LATMAudioRTPSource.$(CPP):	include/MPEG4LATMAudioRTPSource.hh
include/MPEG4LATMAudioRTPSource.hh:	include/MultiFramedRTPSource.hh
MPEG4ESVideoRTPSource.$(CPP):	include/MPEG4ESVideoRTPSource.hh
include/MPEG4ESVideoRTPSource.hh:	include/MultiFramedRTPSource.hh
MPEG4GenericRTPSource.$(CPP):	include/MPEG4GenericRTPSource.hh include/BitVector.hh include/MPEG4LATMAudioRTPSource.hh
include/MPEG4GenericRTPSource.hh:	include/MultiFramedRTPSource.hh
MP3FileSource.$(CPP):	include/MP3FileSource.hh MP3StreamState.hh include/InputFile.hh
include/MP3FileSource.hh:	include/FramedFileSource.hh
MP3StreamState.hh:	MP3Internals.hh
MP3Internals.hh:	include/BitVector.hh
MP3Transcoder.$(CPP):	include/MP3ADU.hh include/MP3Transcoder.hh
include/MP3ADU.hh:		include/FramedFilter.hh
include/MP3Transcoder.hh:	include/MP3ADU.hh include/MP3ADUTranscoder.hh
include/MP3ADUTranscoder.hh:	include/FramedFilter.hh
MP3ADU.$(CPP):		include/MP3ADU.hh MP3ADUdescriptor.hh MP3Internals.hh
MP3ADUdescriptor.$(CPP):	MP3ADUdescriptor.hh
MP3ADUinterleaving.$(CPP):	include/MP3ADUinterleaving.hh MP3ADUdescriptor.hh
include/MP3ADUinterleaving.hh:	include/FramedFilter.hh
MP3ADUTranscoder.$(CPP):	include/MP3ADUTranscoder.hh MP3Internals.hh
MP3StreamState.$(CPP):	MP3StreamState.hh include/InputFile.hh
MP3Internals.$(CPP):	MP3InternalsHuffman.hh
MP3InternalsHuffman.hh:	MP3Internals.hh
MP3InternalsHuffman.$(CPP):	MP3InternalsHuffman.hh
MP3InternalsHuffmanTable.$(CPP):	MP3InternalsHuffman.hh
MP3ADURTPSource.$(CPP):	include/MP3ADURTPSource.hh MP3ADUdescriptor.hh
include/MP3ADURTPSource.hh:	include/MultiFramedRTPSource.hh
MPEG1or2VideoRTPSource.$(CPP):	include/MPEG1or2VideoRTPSource.hh
include/MPEG1or2VideoRTPSource.hh:	include/MultiFramedRTPSource.hh
MPEG2TransportStreamMultiplexor.$(CPP):	include/MPEG2TransportStreamMultiplexor.hh
include/MPEG2TransportStreamMultiplexor.hh:	include/FramedSource.hh include/MPEG1or2Demux.hh
MPEG2TransportStreamFromPESSource.$(CPP):	include/MPEG2TransportStreamFromPESSource.hh
include/MPEG2TransportStreamFromPESSource.hh:	include/MPEG2TransportStreamMultiplexor.hh include/MPEG1or2DemuxedElementaryStream.hh
MPEG2TransportStreamFromESSource.$(CPP):	include/MPEG2TransportStreamFromESSource.hh
include/MPEG2TransportStreamFromESSource.hh:	include/MPEG2TransportStreamMultiplexor.hh
MPEG2TransportStreamFramer.$(CPP):	include/MPEG2TransportStreamFramer.hh
include/MPEG2TransportStreamFramer.hh:	include/FramedFilter.hh include/MPEG2TransportStreamIndexFile.hh
MPEG2TransportStreamAccumulator.$(CPP):	include/MPEG2TransportStreamAccumulator.hh
include/MPEG2TransportStreamAccumulator.hh:	include/FramedFilter.hh
ADTSAudioFileSource.$(CPP):	include/ADTSAudioFileSource.hh include/InputFile.hh
ADTSAudioStreamDiscreteFramer.$(CPP):	include/ADTSAudioStreamDiscreteFramer.hh
include/ADTSAudioStreamDiscreteFramer.hh:	include/FramedFilter.hh
JPEGVideoSource.$(CPP):		include/JPEGVideoSource.hh
include/JPEGVideoSource.hh:	include/FramedSource.hh
JPEGVideoRTPSource.$(CPP):	include/JPEGVideoRTPSource.hh
include/JPEGVideoRTPSource.hh:	include/MultiFramedRTPSource.hh
#JPEG2000VideoStreamFramer.$(CPP):	include/JPEG2000VideoStreamFramer.hh JPEG2000VideoStreamParser.hh
#include/JPEG2000VideoStreamFramer.hh:	include/MPEGVideoStreamFramer.hh
#JPEG2000VideoStreamParser.hh:		StreamParser.hh include/MPEGVideoStreamFramer.hh
#JPEG2000VideoStreamParser.$(CPP):	JPEG2000VideoStreamParser.hh
JPEG2000VideoRTPSource.$(CPP):		include/JPEG2000VideoRTPSource.hh
include/JPEG2000VideoRTPSource.hh:	include/MultiFramedRTPSource.hh
include/ADTSAudioFileSource.hh:	include/FramedFileSource.hh
H263plusVideoRTPSource.$(CPP):	include/H263plusVideoRTPSource.hh
include/H263plusVideoRTPSource.hh:	include/MultiFramedRTPSource.hh
H263plusVideoStreamFramer.$(CPP):	include/H263plusVideoStreamFramer.hh H263plusVideoStreamParser.hh
include/H263plusVideoStreamFramer.hh:	include/FramedFilter.hh
H263plusVideoStreamParser.hh:	StreamParser.hh
H263plusVideoStreamParser.$(CPP):	H263plusVideoStreamParser.hh include/H263plusVideoStreamFramer.hh
AC3AudioStreamFramer.$(CPP):	include/AC3AudioStreamFramer.hh StreamParser.hh
include/AC3AudioStreamFramer.hh:	include/FramedFilter.hh
AC3AudioRTPSource.$(CPP):	include/AC3AudioRTPSource.hh
include/AC3AudioRTPSource.hh:	include/MultiFramedRTPSource.hh
DVVideoRTPSource.$(CPP):	include/DVVideoRTPSource.hh
include/DVVideoRTPSource.hh:	include/MultiFramedRTPSource.hh
AMRAudioSource.$(CPP):	include/AMRAudioSource.hh
include/AMRAudioSource.hh:	include/FramedSource.hh
AMRAudioFileSource.$(CPP):	include/AMRAudioFileSource.hh include/InputFile.hh
include/AMRAudioFileSource.hh:	include/AMRAudioSource.hh
InputFile.$(CPP):		include/InputFile.hh
StreamReplicator.$(CPP):	include/StreamReplicator.hh
include/StreamReplicator.hh:	include/FramedSource.hh
MediaSink.$(CPP):	include/MediaSink.hh
include/MediaSink.hh:		include/FramedSource.hh
FileSink.$(CPP):	include/FileSink.hh include/OutputFile.hh
include/FileSink.hh:		include/MediaSink.hh
BasicUDPSink.$(CPP):	include/BasicUDPSink.hh
include/BasicUDPSink.hh:	include/MediaSink.hh
AMRAudioFileSink.$(CPP):	include/AMRAudioFileSink.hh include/AMRAudioSource.hh include/OutputFile.hh
include/AMRAudioFileSink.hh:	include/FileSink.hh
H264or5VideoFileSink.$(CPP):	include/H264or5VideoFileSink.hh include/H264VideoRTPSource.hh
include/H264or5VideoFileSink.hh:   include/FileSink.hh
H264VideoFileSink.$(CPP):       include/H264VideoFileSink.hh include/OutputFile.hh
include/H264VideoFileSink.hh:   include/H264or5VideoFileSink.hh
H265VideoFileSink.$(CPP):       include/H265VideoFileSink.hh include/OutputFile.hh
include/H265VideoFileSink.hh:   include/H264or5VideoFileSink.hh
OggFileSink.$(CPP):		include/OggFileSink.hh include/OutputFile.hh include/VorbisAudioRTPSource.hh include/MPEG2TransportStreamMultiplexor.hh include/FramedSource.hh
include/OggFileSink.hh:		include/FileSink.hh
RTPSink.$(CPP):			include/RTPSink.hh include/Base64.hh
include/RTPSink.hh:		include/MediaSink.hh include/RTPInterface.hh include/SRTPCryptographicContext.hh
MultiFramedRTPSink.$(CPP):	include/MultiFramedRTPSink.hh
include/MultiFramedRTPSink.hh:		include/RTPSink.hh
AudioRTPSink.$(CPP):		include/AudioRTPSink.hh
include/AudioRTPSink.hh:	include/MultiFramedRTPSink.hh
VideoRTPSink.$(CPP):		include/VideoRTPSink.hh
include/VideoRTPSink.hh:	include/MultiFramedRTPSink.hh
TextRTPSink.$(CPP):		include/TextRTPSink.hh
include/TextRTPSink.hh:		include/MultiFramedRTPSink.hh
RTPInterface.$(CPP):		include/RTPInterface.hh
MPEG1or2AudioRTPSink.$(CPP):	include/MPEG1or2AudioRTPSink.hh
include/MPEG1or2AudioRTPSink.hh:	include/AudioRTPSink.hh
MP3ADURTPSink.$(CPP):	include/MP3ADURTPSink.hh
include/MP3ADURTPSink.hh:	include/AudioRTPSink.hh
MPEG1or2VideoRTPSink.$(CPP):	include/MPEG1or2VideoRTPSink.hh include/MPEG1or2VideoStreamFramer.hh
include/MPEG1or2VideoRTPSink.hh:	include/VideoRTPSink.hh
MPEG4LATMAudioRTPSink.$(CPP):	include/MPEG4LATMAudioRTPSink.hh
include/MPEG4LATMAudioRTPSink.hh:	include/AudioRTPSink.hh
MPEG4GenericRTPSink.$(CPP):	include/MPEG4GenericRTPSink.hh include/Locale.hh
include/MPEG4GenericRTPSink.hh:	include/MultiFramedRTPSink.hh
MPEG4ESVideoRTPSink.$(CPP):	include/MPEG4ESVideoRTPSink.hh include/MPEG4VideoStreamFramer.hh include/MPEG4LATMAudioRTPSource.hh
include/MPEG4ESVideoRTPSink.hh: include/VideoRTPSink.hh
JPEGVideoRTPSink.$(CPP):	include/JPEGVideoRTPSink.hh include/JPEGVideoSource.hh
include/JPEGVideoRTPSink.hh:	include/VideoRTPSink.hh
JPEG2000VideoRTPSink.$(CPP):	include/JPEG2000VideoRTPSink.hh
include/JPEG2000VideoRTPSink.hh:	include/VideoRTPSink.hh
H263plusVideoRTPSink.$(CPP):	include/H263plusVideoRTPSink.hh
include/H263plusVideoRTPSink.hh:	include/VideoRTPSink.hh
H264or5VideoRTPSink.$(CPP):	include/H264or5VideoRTPSink.hh include/H264or5VideoStreamFramer.hh
include/H264or5VideoRTPSink.hh:	include/VideoRTPSink.hh include/FramedFilter.hh
H264VideoRTPSink.$(CPP):	include/H264VideoRTPSink.hh include/H264VideoStreamFramer.hh include/Base64.hh include/H264VideoRTPSource.hh
include/H264VideoRTPSink.hh:	include/H264or5VideoRTPSink.hh
H265VideoRTPSink.$(CPP):	include/H265VideoRTPSink.hh include/H265VideoStreamFramer.hh include/Base64.hh include/BitVector.hh include/H264VideoRTPSource.hh
include/H265VideoRTPSink.hh:	include/H264or5VideoRTPSink.hh
DVVideoRTPSink.$(CPP):	include/DVVideoRTPSink.hh
include/DVVideoRTPSink.hh:	include/VideoRTPSink.hh include/DVVideoStreamFramer.hh
include/DVVideoStreamFramer.hh:	include/FramedFilter.hh
AC3AudioRTPSink.$(CPP):		include/AC3AudioRTPSink.hh
include/AC3AudioRTPSink.hh:	include/AudioRTPSink.hh
VorbisAudioRTPSink.$(CPP):	include/VorbisAudioRTPSink.hh include/Base64.hh include/VorbisAudioRTPSource.hh
include/VorbisAudioRTPSink.hh:	include/AudioRTPSink.hh
TheoraVideoRTPSink.$(CPP):	include/TheoraVideoRTPSink.hh include/Base64.hh include/VorbisAudioRTPSource.hh include/VorbisAudioRTPSink.hh
include/TheoraVideoRTPSink.hh:	include/VideoRTPSink.hh
RawVideoRTPSink.$(CPP):	include/RawVideoRTPSink.hh
include/RawVideoRTPSink.hh:	include/VideoRTPSink.hh include/RawVideoFrameParameters.hh
VP8VideoRTPSink.$(CPP):		include/VP8VideoRTPSink.hh
include/VP8VideoRTPSink.hh:	include/VideoRTPSink.hh
VP9VideoRTPSink.$(CPP):		include/VP9VideoRTPSink.hh
include/VP9VideoRTPSink.hh:	include/VideoRTPSink.hh
GSMAudioRTPSink.$(CPP):		include/GSMAudioRTPSink.hh
include/GSMAudioRTPSink.hh:	include/AudioRTPSink.hh
SimpleRTPSink.$(CPP):		include/SimpleRTPSink.hh
include/SimpleRTPSink.hh:	include/MultiFramedRTPSink.hh
AMRAudioRTPSink.$(CPP):		include/AMRAudioRTPSink.hh include/AMRAudioSource.hh
include/AMRAudioRTPSink.hh:	include/AudioRTPSink.hh
T140TextRTPSink.$(CPP):		include/T140TextRTPSink.hh
include/T140TextRTPSink.hh:	include/TextRTPSink.hh include/FramedFilter.hh
OutputFile.$(CPP):		include/OutputFile.hh
uLawAudioFilter.$(CPP):		include/uLawAudioFilter.hh
include/uLawAudioFilter.hh:	include/FramedFilter.hh
MPEG2IndexFromTransportStream.$(CPP):	include/MPEG2IndexFromTransportStream.hh
include/MPEG2IndexFromTransportStream.hh:	include/FramedFilter.hh
MPEG2TransportStreamIndexFile.$(CPP):	include/MPEG2TransportStreamIndexFile.hh include/InputFile.hh
include/MPEG2TransportStreamIndexFile.hh:	include/Media.hh
MPEG2TransportStreamTrickModeFilter.$(CPP):	include/MPEG2TransportStreamTrickModeFilter.hh include/ByteStreamFileSource.hh
include/MPEG2TransportStreamTrickModeFilter.hh:	include/FramedFilter.hh include/MPEG2TransportStreamIndexFile.hh
RTCP.$(CPP):		include/RTCP.hh rtcp_from_spec.h
include/RTCP.hh:		include/RTPSink.hh include/RTPSource.hh include/SRTPCryptographicContext.hh
rtcp_from_spec.$(C):	rtcp_from_spec.h
GenericMediaServer.$(CPP):	include/GenericMediaServer.hh
include/GenericMediaServer.hh:	include/ServerMediaSession.hh
RTSPServer.$(CPP):	include/RTSPServer.hh include/RTSPCommon.hh include/RTSPRegisterSender.hh include/ProxyServerMediaSession.hh include/Base64.hh
include/RTSPServer.hh:		include/GenericMediaServer.hh include/DigestAuthentication.hh
RTSPServerRegister.$(CPP):	include/RTSPServer.hh
include/ServerMediaSession.hh:	include/RTCP.hh
RTSPClient.$(CPP):	include/RTSPClient.hh  include/RTSPCommon.hh include/Base64.hh include/Locale.hh include/ourMD5.hh
include/RTSPClient.hh:		include/MediaSession.hh include/DigestAuthentication.hh
RTSPCommon.$(CPP):	include/RTSPCommon.hh include/Locale.hh
RTSPRegisterSender.$(CPP):	include/RTSPRegisterSender.hh
include/RTSPRegisterSender.hh:	include/RTSPClient.hh
SIPClient.$(CPP):	include/SIPClient.hh
include/SIPClient.hh:		include/MediaSession.hh include/DigestAuthentication.hh
MediaSession.$(CPP):	include/liveMedia.hh include/Locale.hh include/Base64.hh
include/MediaSession.hh:	include/RTCP.hh include/FramedFilter.hh include/SRTPCryptographicContext.hh
ServerMediaSession.$(CPP):	include/ServerMediaSession.hh
PassiveServerMediaSubsession.$(CPP):	include/PassiveServerMediaSubsession.hh
include/PassiveServerMediaSubsession.hh:	include/ServerMediaSession.hh include/RTPSink.hh include/RTCP.hh
OnDemandServerMediaSubsession.$(CPP):	include/OnDemandServerMediaSubsession.hh
include/OnDemandServerMediaSubsession.hh:	include/ServerMediaSession.hh include/RTPSink.hh include/BasicUDPSink.hh include/RTCP.hh
FileServerMediaSubsession.$(CPP):	include/FileServerMediaSubsession.hh
include/FileServerMediaSubsession.hh:	include/OnDemandServerMediaSubsession.hh
MPEG4VideoFileServerMediaSubsession.$(CPP):	include/MPEG4VideoFileServerMediaSubsession.hh include/MPEG4ESVideoRTPSink.hh include/ByteStreamFileSource.hh include/MPEG4VideoStreamFramer.hh
include/MPEG4VideoFileServerMediaSubsession.hh:	include/FileServerMediaSubsession.hh
H264VideoFileServerMediaSubsession.$(CPP):	include/H264VideoFileServerMediaSubsession.hh include/H264VideoRTPSink.hh include/ByteStreamFileSource.hh include/H264VideoStreamFramer.hh
include/H264VideoFileServerMediaSubsession.hh:	include/FileServerMediaSubsession.hh
H265VideoFileServerMediaSubsession.$(CPP):	include/H265VideoFileServerMediaSubsession.hh include/H265VideoRTPSink.hh include/ByteStreamFileSource.hh include/H265VideoStreamFramer.hh
include/H265VideoFileServerMediaSubsession.hh:	include/FileServerMediaSubsession.hh
H263plusVideoFileServerMediaSubsession.$(CPP):	include/H263plusVideoFileServerMediaSubsession.hh include/H263plusVideoRTPSink.hh include/ByteStreamFileSource.hh include/H263plusVideoStreamFramer.hh
include/H263plusVideoFileServerMediaSubsession.hh:	include/FileServerMediaSubsession.hh
WAVAudioFileServerMediaSubsession.$(CPP):	include/WAVAudioFileServerMediaSubsession.hh include/WAVAudioFileSource.hh include/uLawAudioFilter.hh include/SimpleRTPSink.hh
include/WAVAudioFileServerMediaSubsession.hh:	include/FileServerMediaSubsession.hh
AMRAudioFileServerMediaSubsession.$(CPP):	include/AMRAudioFileServerMediaSubsession.hh include/AMRAudioRTPSink.hh include/AMRAudioFileSource.hh
include/AMRAudioFileServerMediaSubsession.hh:	include/FileServerMediaSubsession.hh
MP3AudioFileServerMediaSubsession.$(CPP):	include/MP3AudioFileServerMediaSubsession.hh include/MPEG1or2AudioRTPSink.hh include/MP3ADURTPSink.hh include/MP3FileSource.hh include/MP3ADU.hh
include/MP3AudioFileServerMediaSubsession.hh:	include/FileServerMediaSubsession.hh include/MP3ADUinterleaving.hh
MPEG1or2VideoFileServerMediaSubsession.$(CPP):	include/MPEG1or2VideoFileServerMediaSubsession.hh include/MPEG1or2VideoRTPSink.hh include/ByteStreamFileSource.hh include/MPEG1or2VideoStreamFramer.hh
include/MPEG1or2VideoFileServerMediaSubsession.hh:	include/FileServerMediaSubsession.hh
MPEG1or2FileServerDemux.$(CPP):	include/MPEG1or2FileServerDemux.hh include/MPEG1or2DemuxedServerMediaSubsession.hh include/ByteStreamFileSource.hh
include/MPEG1or2FileServerDemux.hh:	include/ServerMediaSession.hh include/MPEG1or2DemuxedElementaryStream.hh
MPEG1or2DemuxedServerMediaSubsession.$(CPP): include/MPEG1or2DemuxedServerMediaSubsession.hh include/MPEG1or2AudioStreamFramer.hh include/MPEG1or2AudioRTPSink.hh include/MPEG1or2VideoStreamFramer.hh include/MPEG1or2VideoRTPSink.hh include/AC3AudioStreamFramer.hh include/AC3AudioRTPSink.hh include/ByteStreamFileSource.hh
include/MPEG1or2DemuxedServerMediaSubsession.hh: include/OnDemandServerMediaSubsession.hh include/MPEG1or2FileServerDemux.hh
MPEG2TransportFileServerMediaSubsession.$(CPP):	include/MPEG2TransportFileServerMediaSubsession.hh include/SimpleRTPSink.hh
include/MPEG2TransportFileServerMediaSubsession.hh:	include/FileServerMediaSubsession.hh include/MPEG2TransportStreamFramer.hh include/ByteStreamFileSource.hh include/MPEG2TransportStreamTrickModeFilter.hh include/MPEG2TransportStreamFromESSource.hh
ADTSAudioFileServerMediaSubsession.$(CPP):	include/ADTSAudioFileServerMediaSubsession.hh include/ADTSAudioFileSource.hh include/MPEG4GenericRTPSink.hh
include/ADTSAudioFileServerMediaSubsession.hh:	include/FileServerMediaSubsession.hh
DVVideoFileServerMediaSubsession.$(CPP):	include/DVVideoFileServerMediaSubsession.hh include/DVVideoRTPSink.hh include/ByteStreamFileSource.hh include/DVVideoStreamFramer.hh
include/DVVideoFileServerMediaSubsession.hh:	include/FileServerMediaSubsession.hh
AC3AudioFileServerMediaSubsession.$(CPP):	include/AC3AudioFileServerMediaSubsession.hh include/AC3AudioRTPSink.hh include/ByteStreamFileSource.hh include/AC3AudioStreamFramer.hh
include/AC3AudioFileServerMediaSubsession.hh:	include/FileServerMediaSubsession.hh
#JPEG2000VideoFileServerMediaSubsession.$(CPP):	include/JPEG2000VideoFileServerMediaSubsession.hh
#include/JPEG2000VideoFileServerMediaSubsession.hh:	include/FileServerMediaSubsession.hh
MPEG2TransportUDPServerMediaSubsession.$(CPP):	include/MPEG2TransportUDPServerMediaSubsession.hh include/BasicUDPSource.hh include/SimpleRTPSource.hh include/MPEG2TransportStreamFramer.hh include/SimpleRTPSink.hh
include/MPEG2TransportUDPServerMediaSubsession.hh:	include/OnDemandServerMediaSubsession.hh
ProxyServerMediaSession.$(CPP):		include/liveMedia.hh include/RTSPCommon.hh
include/ProxyServerMediaSession.hh:	include/ServerMediaSession.hh include/MediaSession.hh include/RTSPClient.hh include/MediaTranscodingTable.hh
include/MediaTranscodingTable.hh:	include/FramedFilter.hh include/MediaSession.hh
QuickTimeFileSink.$(CPP):	include/QuickTimeFileSink.hh include/InputFile.hh include/OutputFile.hh include/QuickTimeGenericRTPSource.hh include/H263plusVideoRTPSource.hh include/MPEG4GenericRTPSource.hh include/MPEG4LATMAudioRTPSource.hh
include/QuickTimeFileSink.hh:	include/MediaSession.hh
QuickTimeGenericRTPSource.$(CPP):	include/QuickTimeGenericRTPSource.hh
include/QuickTimeGenericRTPSource.hh:	include/MultiFramedRTPSource.hh
AVIFileSink.$(CPP):	include/AVIFileSink.hh include/InputFile.hh include/OutputFile.hh
include/AVIFileSink.hh:	include/MediaSession.hh
MatroskaFile.$(CPP): MatroskaFileParser.hh MatroskaDemuxedTrack.hh include/ByteStreamFileSource.hh include/H264VideoStreamDiscreteFramer.hh include/H265VideoStreamDiscreteFramer.hh include/MPEG1or2AudioRTPSink.hh include/MPEG4GenericRTPSink.hh include/AC3AudioRTPSink.hh include/SimpleRTPSink.hh include/VorbisAudioRTPSink.hh include/H264VideoRTPSink.hh include/H265VideoRTPSink.hh include/VP8VideoRTPSink.hh include/VP9VideoRTPSink.hh include/T140TextRTPSink.hh include/Base64.hh include/H264VideoFileSink.hh include/H265VideoFileSink.hh include/AMRAudioFileSink.hh include/OggFileSink.hh
MatroskaFileParser.hh:	StreamParser.hh include/MatroskaFile.hh EBMLNumber.hh
include/MatroskaFile.hh: include/RTPSink.hh include/FileSink.hh
MatroskaDemuxedTrack.hh:	include/FramedSource.hh
MatroskaFileParser.$(CPP): MatroskaFileParser.hh MatroskaDemuxedTrack.hh include/ByteStreamFileSource.hh
EBMLNumber.$(CPP): EBMLNumber.hh
MatroskaDemuxedTrack.$(CPP): MatroskaDemuxedTrack.hh include/MatroskaFile.hh
MatroskaFileServerMediaSubsession.$(CPP): MatroskaFileServerMediaSubsession.hh MatroskaDemuxedTrack.hh include/FramedFilter.hh
MatroskaFileServerMediaSubsession.hh: include/FileServerMediaSubsession.hh include/MatroskaFileServerDemux.hh
MP3AudioMatroskaFileServerMediaSubsession.$(CPP): MP3AudioMatroskaFileServerMediaSubsession.hh MatroskaDemuxedTrack.hh
MP3AudioMatroskaFileServerMediaSubsession.hh: include/MP3AudioFileServerMediaSubsession.hh include/MatroskaFileServerDemux.hh
MatroskaFileServerDemux.$(CPP): include/MatroskaFileServerDemux.hh MP3AudioMatroskaFileServerMediaSubsession.hh MatroskaFileServerMediaSubsession.hh
include/MatroskaFileServerDemux.hh: include/ServerMediaSession.hh include/MatroskaFile.hh
OggFile.$(CPP): OggFileParser.hh OggDemuxedTrack.hh include/ByteStreamFileSource.hh include/VorbisAudioRTPSink.hh include/SimpleRTPSink.hh include/TheoraVideoRTPSink.hh
OggFileParser.hh:	StreamParser.hh include/OggFile.hh
include/OggFile.hh: include/RTPSink.hh
OggDemuxedTrack.hh:	include/FramedSource.hh
OggFileParser.$(CPP): OggFileParser.hh OggDemuxedTrack.hh
OggDemuxedTrack.$(CPP): OggDemuxedTrack.hh include/OggFile.hh
OggFileServerMediaSubsession.$(CPP): OggFileServerMediaSubsession.hh OggDemuxedTrack.hh include/FramedFilter.hh
OggFileServerMediaSubsession.hh: include/FileServerMediaSubsession.hh include/OggFileServerDemux.hh
OggFileServerDemux.$(CPP): include/OggFileServerDemux.hh OggFileServerMediaSubsession.hh
include/OggFileServerDemux.hh: include/ServerMediaSession.hh include/OggFile.hh
MPEG2TransportStreamDemux.$(CPP): include/MPEG2TransportStreamDemux.hh MPEG2TransportStreamParser.hh
include/MPEG2TransportStreamDemux.hh: include/FramedSource.hh
MPEG2TransportStreamParser.hh: StreamParser.hh MPEG2TransportStreamDemuxedTrack.hh include/MediaSink.hh
MPEG2TransportStreamDemuxedTrack.hh: include/MPEG2TransportStreamDemux.hh
MPEG2TransportStreamDemuxedTrack.$(CPP): MPEG2TransportStreamParser.hh
MPEG2TransportStreamParser.$(CPP): MPEG2TransportStreamParser.hh
MPEG2TransportStreamParser_PAT.$(CPP): MPEG2TransportStreamParser.hh
MPEG2TransportStreamParser_PMT.$(CPP): MPEG2TransportStreamParser.hh
MPEG2TransportStreamParser_STREAM.$(CPP): MPEG2TransportStreamParser.hh include/FileSink.hh
HLSSegmenter.$(CPP): include/HLSSegmenter.hh include/OutputFile.hh include/MPEG2TransportStreamMultiplexor.hh
include/HLSSegmenter.hh: include/MediaSink.hh
TLSState.$(CPP):		include/TLSState.hh include/RTSPClient.hh
MIKEY.$(CPP):		 include/MIKEY.hh
HMAC_SHA1.$(CPP):	include/HMAC_SHA1.hh
include/SRTPCryptographicContext.hh:	include/MIKEY.hh
SRTPCryptographicContext.$(CPP):	include/SRTPCryptographicContext.hh include/HMAC_SHA1.hh
include/HMAC_SHA1.hh:	include/HMAC_hash.hh
BitVector.$(CPP):	include/BitVector.hh
StreamParser.$(CPP):	StreamParser.hh
DigestAuthentication.$(CPP):	include/DigestAuthentication.hh include/ourMD5.hh
ourMD5.$(CPP):	include/ourMD5.hh
Base64.$(CPP):	include/Base64.hh
Locale.$(CPP):	include/Locale.hh

include/liveMedia.hh:: include/JPEG2000VideoRTPSource.hh include/JPEG2000VideoRTPSink.hh
#include/liveMedia.hh:: include/JPEG2000VideoStreamFramer.hh include/JPEG2000VideoFileServerMediaSubsession.hh

include/liveMedia.hh:: include/MPEG1or2AudioRTPSink.hh include/MP3ADURTPSink.hh include/MPEG1or2VideoRTPSink.hh include/MPEG4ESVideoRTPSink.hh include/BasicUDPSink.hh include/AMRAudioFileSink.hh include/H264VideoFileSink.hh include/H265VideoFileSink.hh include/OggFileSink.hh include/GSMAudioRTPSink.hh include/H263plusVideoRTPSink.hh include/H264VideoRTPSink.hh include/H265VideoRTPSink.hh include/DVVideoRTPSource.hh include/DVVideoRTPSink.hh include/DVVideoStreamFramer.hh include/H264VideoStreamFramer.hh include/H265VideoStreamFramer.hh include/H264VideoStreamDiscreteFramer.hh include/H265VideoStreamDiscreteFramer.hh include/JPEGVideoRTPSink.hh include/SimpleRTPSink.hh include/uLawAudioFilter.hh include/MPEG2IndexFromTransportStream.hh include/MPEG2TransportStreamTrickModeFilter.hh include/ByteStreamMultiFileSource.hh include/ByteStreamMemoryBufferSource.hh include/BasicUDPSource.hh include/SimpleRTPSource.hh include/MPEG1or2AudioRTPSource.hh include/MPEG4LATMAudioRTPSource.hh include/MPEG4LATMAudioRTPSink.hh include/MPEG4ESVideoRTPSource.hh include/MPEG4GenericRTPSource.hh include/MP3ADURTPSource.hh include/QCELPAudioRTPSource.hh include/AMRAudioRTPSource.hh include/JPEGVideoRTPSource.hh include/JPEGVideoSource.hh include/MPEG1or2VideoRTPSource.hh include/VorbisAudioRTPSource.hh include/TheoraVideoRTPSource.hh include/VP8VideoRTPSource.hh include/VP9VideoRTPSource.hh include/RawVideoRTPSource.hh

include/liveMedia.hh::	include/MPEG2TransportStreamFromPESSource.hh include/MPEG2TransportStreamFromESSource.hh include/MPEG2TransportStreamFramer.hh include/ADTSAudioFileSource.hh include/ADTSAudioStreamDiscreteFramer.hh include/H261VideoRTPSource.hh include/H263plusVideoRTPSource.hh include/H264VideoRTPSource.hh include/H265VideoRTPSource.hh include/MP3FileSource.hh include/MP3ADU.hh include/MP3ADUinterleaving.hh include/MP3Transcoder.hh include/MPEG1or2DemuxedElementaryStream.hh include/MPEG1or2AudioStreamFramer.hh include/MPEG1or2VideoStreamDiscreteFramer.hh include/MPEG4VideoStreamDiscreteFramer.hh include/H263plusVideoStreamFramer.hh include/AC3AudioStreamFramer.hh include/AC3AudioRTPSource.hh include/AC3AudioRTPSink.hh include/VorbisAudioRTPSink.hh include/TheoraVideoRTPSink.hh include/VP8VideoRTPSink.hh include/VP9VideoRTPSink.hh include/MPEG4GenericRTPSink.hh include/DeviceSource.hh include/AudioInputDevice.hh include/WAVAudioFileSource.hh include/StreamReplicator.hh include/RTSPRegisterSender.hh

include/liveMedia.hh:: include/RTSPClient.hh include/SIPClient.hh include/QuickTimeFileSink.hh include/QuickTimeGenericRTPSource.hh include/AVIFileSink.hh include/PassiveServerMediaSubsession.hh include/MPEG4VideoFileServerMediaSubsession.hh include/H264VideoFileServerMediaSubsession.hh include/H265VideoFileServerMediaSubsession.hh include/WAVAudioFileServerMediaSubsession.hh include/AMRAudioFileServerMediaSubsession.hh include/AMRAudioFileSource.hh include/AMRAudioRTPSink.hh include/T140TextRTPSink.hh include/MP3AudioFileServerMediaSubsession.hh include/MPEG1or2VideoFileServerMediaSubsession.hh include/MPEG1or2FileServerDemux.hh include/MPEG2TransportFileServerMediaSubsession.hh include/H263plusVideoFileServerMediaSubsession.hh include/ADTSAudioFileServerMediaSubsession.hh include/DVVideoFileServerMediaSubsession.hh include/AC3AudioFileServerMediaSubsession.hh include/MPEG2TransportUDPServerMediaSubsession.hh include/MatroskaFileServerDemux.hh include/OggFileServerDemux.hh include/ProxyServerMediaSession.hh include/HLSSegmenter.hh include/MPEG2TransportStreamAccumulator.hh

clean:
	-rm -rf *.$(OBJ) $(ALL) core *.core *~ include/*~

install: install1 $(INSTALL2)
install1: $(LIVEMEDIA_LIB)
	 install -d $(DESTDIR)$(PREFIX)/include/liveMedia $(DESTDIR)$(LIBDIR)
	 install -m 644 include/*.hh $(DESTDIR)$(PREFIX)/include/liveMedia
	 install -m 644 $(LIVEMEDIA_LIB) $(DESTDIR)$(LIBDIR)
install_shared_libraries: install1
	 ln -fs $(NAME).$(LIB_SUFFIX) $(DESTDIR)$(LIBDIR)/$(NAME).$(SHORT_LIB_SUFFIX)
	 ln -fs $(NAME).$(LIB_SUFFIX) $(DESTDIR)$(LIBDIR)/$(NAME).so

##### Any additional, platform-specific rules come here:
