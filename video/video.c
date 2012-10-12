#include <stdio.h>
#include <SDL.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>
//This file will contain all the functions for getting a video thread and getting it on the screen
//Yes I know that that is dangerous
//example thread for example function
SDL_Thread *example;
//just an example bool for turning off the thread
//just the stuff I need to pass to the example threads
struct exampleThreadData{
				char *string;
				int counter;
				bool stopper;
				SDL_Thread *threader;
			};
//for creating the struct
struct exampleThreadData *threadFiller(char *string, int counter, bool stopper)
{
	struct exampleThreadData *thread = malloc(sizeof(struct exampleThreadData));
	assert(thread != NULL);
	thread->string = strdup(string);
	thread->counter = counter;
	thread->stopper = stopper;
	return thread;	
}

//setting up the example thread
int exampleThread( struct exampleThreadData *crazy)
{
	//while threadstop isn't true
	while ( crazy->stopper == true ){
					printf( "%s\n", crazy->string );
					crazy->counter = (crazy->counter + 1);
				}
	//we have to return a int apparently
	return 76;
}	
//example function for creating the thread
int threadcreate( struct exampleThreadData *woah )
{
	SDL_Thread *example = SDL_CreateThread ( exampleThread , woah );
	return example;
}

int finishThreads( struct exampleThreadData *threadStruc )
{
	threadStruc->stopper = false;
	SDL_WaitThread(threadStruc->threader, NULL );
	printf("\n%d\n", threadStruc->counter);
	return 0;
}


int evilThreads(char *string, int counter, bool stopper)
{
	struct exampleThreadData *trans = threadFiller(string, counter , stopper);
	trans->threader = threadcreate(trans);
	return trans;
}





