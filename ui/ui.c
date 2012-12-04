#include <stdio.h>
#include "SDL.h"
#include "../headers/ui.h"
#include "../headers/main.h"
int UI_Initialize(){
	//initializing SDL and returning -1 if it fails
	int i = SDL_Init(SDL_INIT_VIDEO);
		if(i < 0){
			return -1;
		};
		if(mainData->verbose == 1){
			printf("SDL Initialized\n");
		};

		mainData->UI_window = SDL_SetVideoMode(640, 480, 24, SDL_HWSURFACE|SDL_RESIZABLE);
		if(mainData->UI_window == NULL){
			mainData->UI_window = SDL_SetVideoMode(640, 480, 24, SDL_SWSURFACE|SDL_RESIZABLE);
			if(mainData->UI_window == NULL){
				return -1;
			};
			};
		
		if(mainData->verbose == 1){
			printf("Got a surface\n");
		};
		
				



		//event handling
		//has to be done on the same thread that set the video mode
		SDL_Event event;
		//we run forever until we get a SDL_QUIT one way or another
		while(SDL_WaitEvent(&event) != 0){
			printf("%i\n",event.type);
			switch(event.type) {
				case SDL_VIDEORESIZE: //User resized window
					mainData->UI_window = SDL_SetVideoMode(event.resize.w, event.resize.h, 24, mainData->UI_window->flags);
					break;
				case SDL_QUIT: 
					printf("Quiting\n");
					return 0;


			};
		
		};


		
		return 0;
}

		

int UI_thread(){
	SDL_SemWait(mainData->UI_renderhold);
	
	return 0;
}





		

