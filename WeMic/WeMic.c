
#include <stdio.h>
#include <libavformat/avformat.h>
#include <libavcodec/avcodec.h>
#include <libavdevice/avdevice.h>
#include <libswscale/swscale.h>
#include "libavformat/avformat.h"
#include "SDL.h"
#include "../headers/WeMic.h"
#include "../headers/main.h"

struct VIDEO_webcamdata *VIDEO_webcamload(char *device){
	//Register everything. Should probably change this eventually.
	avcodec_register_all();
	avdevice_register_all();
	av_register_all();

	//BLARG SO MANY VARIABLES
	//WHY VIDEO STREAMS WHY?
	AVFormatContext *MyFormatContext = NULL;
	AVInputFormat *MyInputFormat;
	AVCodecContext *MyCodecContext = NULL;
	AVCodec *MyCodec = NULL;
	AVDictionary *videoOptionsDict = NULL;
	struct VIDEO_webcamdata *webcamdata;
	AVFrame *MyFrame = NULL;
	int i;
	//The webcam codec, going to have to ifdef this out and replace it for windows and other platforms
	MyInputFormat = av_find_input_format("video4linux2");

	MyFormatContext = avformat_alloc_context();
	//open our device and make sure it's open
	i =
		avformat_open_input(&MyFormatContext, device, MyInputFormat, NULL);

	if(i < 0){
		return NULL;
	};

	
	//find stream info, make sure we got it
	i = 
		avformat_find_stream_info(MyFormatContext, NULL);

	
	
	if(i < 0){
		return NULL;
	};


	//dump stream information to stdout
	if(mainData->verbose == 1){
	av_dump_format(MyFormatContext, 0, device, 0);};
	
	//find the stream
	unsigned int a;
	for (a = 0; a < MyFormatContext->nb_streams; a++){
		MyFormatContext->streams[a]->discard = AVDISCARD_ALL;};
	
	i = av_find_best_stream(MyFormatContext, AVMEDIA_TYPE_VIDEO, -1, -1, NULL, 0);

	//setting up codec context and finding and opening the decoder
	MyCodecContext = MyFormatContext->streams[i]->codec;

	MyCodec = avcodec_find_decoder(MyCodecContext->codec_id);

	avcodec_open2(MyCodecContext, MyCodec, &videoOptionsDict);

	MyFrame = avcodec_alloc_frame();

	//Finally, wrap it all up in the struct and return it
	webcamdata = malloc(sizeof(struct VIDEO_webcamdata));
	webcamdata->FormatContext = MyFormatContext;
	webcamdata->CodecContext = MyCodecContext;
	webcamdata->Frame = MyFrame;
	webcamdata->Packet = NULL;
	webcamdata->FrameFinished = 0;

	return webcamdata;

}

	
