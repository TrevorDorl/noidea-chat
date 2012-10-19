#include <stdio.h>
#include "SDL.h"
#include "../headers/ui.h"
#include "../headers/main.h"
//just a struct used to pass the thread and the window from UI_Initialize()
struct WindowAndThread
{
	SDL_Surface *window;
	SDL_Thread *thread;
};
int UI_Initialize()
{
	//initializing SDL and returning -1 if it fails
	int i = SDL_Init(SDL_INIT_VIDEO);
		if(i < 0){
			printf("SDL Initialization failed: %s.\n",SDL_GetError());
			return -1;
		}

		printf("SDL initialized.\n");
		mainData = malloc(sizeof(struct main_ProgramData));
		//creating a window
		return UI_Windowroutine();

		

}

int UI_Windowroutine()
{
	//try to get a hardware surface, if that fails, print the error and try to get a software surface, if that fails print the error and return -1
	mainData->UI_Window = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE|SDL_RESIZABLE);
	if(mainData->UI_Window == NULL)
	{
		printf("%s\n",SDL_GetError());
		mainData->UI_Window = SDL_SetVideoMode(640, 480, 32, SDL_SWSURFACE|SDL_RESIZABLE);
		if(mainData->UI_Window == NULL)
		{
			printf("%s\n",SDL_GetError());
			return -1;
		}
	}
	int i = 0;
	for(i = 0; i != 7000;i++)
	{
		printf("um");
	}
	return 0;
}
