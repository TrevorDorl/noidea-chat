#include <stdio.h>
#include <SDL.h>
//This file contains all the functions for getting a video thread and getting it on the screen
//example thread for example function
SDL_Thread *example;
//just an example bool for turning off the thread
int threadStop = 5;
//setting up the example thread
int exampleThread( int woah )
{
	//while threadstop isn't true
	while (threadStop == 5){
					printf("%s",woah);
				}
	//we have to return a int apparently
	return 0;
	SDL_Delay(250);
}	
//example function for creating the thread
int threadcreate( char *woah )
{
	example = SDL_CreateThread ( exampleThread , woah );
	return 0;
}

	
