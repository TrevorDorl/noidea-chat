struct VIDEO_webcamdata
{
	AVFormatContext *FormatContext;
	AVCodecContext *CodecContext;
	AVFrame *Frame;
	AVPacket *Packet;
	int FrameFinished;
};

struct VIDEO_webcamdata *VIDEO_webcamload(char *device);
