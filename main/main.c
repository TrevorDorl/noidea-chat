#include <stdio.h>
#include <libavformat/avformat.h>
#include <libavcodec/avcodec.h>
#include <libavdevice/avdevice.h>
#include <libswscale/swscale.h>
#include "libavformat/avformat.h"
#include "SDL.h"
#include "SDL_thread.h"
#include "../headers/ui.h"
#include "../headers/main.h"
#include "../headers/WeMic.h"

//#include "../headers/video.h"
void *destroyMainProgramData(struct main_ProgramData *i)
{
	//free(i->UI_Window);
	free(i);
	return NULL;
}

//Basically used to control the flow of the entire program
struct main_ProgramData *mainData = NULL;

int main(){

	mainData = malloc(sizeof(struct main_ProgramData));
		//initialze the webcam
	mainData->LocalWebcamData = VIDEO_webcamload("/dev/video0");
	//So we can know to print debug shit
	mainData->verbose = 1;
	//Right now we don't want the render thread to do anything until we SemPost this
	mainData->UI_renderhold = SDL_CreateSemaphore(0);
	//This is the thread that sets up the video surface and handles events
	mainData->UI_initandeventthread = SDL_CreateThread(UI_Initialize, NULL);
	//Thread where the rendering happens
	mainData->UI_renderthread = SDL_CreateThread( UI_thread, NULL);
	
	SDL_WaitThread(mainData->UI_initandeventthread, NULL);
	return 0;

}

void main_cleanup()
{
	
	SDL_FreeSurface(mainData->UI_window);
	//destroyMainProgramData(mainData);
	//SDL_Delay(10);
	//SDL_Quit();
	//SDL_Quit itself seems to have memory leaks, so as of now it is useless.
}



