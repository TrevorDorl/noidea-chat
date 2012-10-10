#include <stdio.h>
#include <SDL.h>
#include <assert.h>
//This file will contains all the functions for getting a video thread and getting it on the screen
//Yes I know that that is dangerous
//example thread for example function
SDL_Thread *example;
//just an example bool for turning off the thread
int threadStop = 5;
int a;
//just the stuff I need to pass to the example threads
struct exampleThreadData{
				char *string;
				int counter;
			};
//for creating the struct
struct exampleThreadData *threadFiller(char *string, int counter)
{
	struct exampleThreadData *thread = malloc(sizeof(struct exampleThreadData));
	assert(thread != NULL);
	thread->string = malloc(sizeof((string)));
	thread->string = string;
	thread->counter = counter;
	return thread;	
}

//setting up the example thread
int exampleThread( struct exampleThreadData *crazy)
{
	//while threadstop isn't true
	while (threadStop == 5){
					printf( "%s\n", crazy->string );
					crazy->counter = (crazy->counter + 1);
					printf( "%d" , crazy->counter );
				}
	//we have to return a int apparently
	return crazy->counter;
}	
//example function for creating the thread
int threadcreate( char *woah )
{
	example = SDL_CreateThread ( exampleThread , woah );
	return 0;
}

/*int finishThreads()
{
	a = 1;
	return 1;
}
*/	
