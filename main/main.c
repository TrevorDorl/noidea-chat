#include <stdio.h>
#include "SDL.h"
#include <stdbool.h>
#include "../headers/ui.h"
#include "../headers/main.h"
struct main_ProgramData *createMainProgramData()
{
	struct main_ProgramData *i = malloc(sizeof(struct main_ProgramData));
	return i;
}
void *destroyMainProgramData(struct main_ProgramData *i)
{
	free(i->UI_Window);
	free(i->UI_Thread);
	free(i);
}

struct main_ProgramData *mainData = NULL;

int main()


{
	//struct exampleThreadData *thread1 = evilThreads("This is terrible.", 0 , true);
        //struct exampleThreadData *thread2 = evilThreads("lololololol", 0 , true);
        //struct exampleThreadData *thread3 = evilThreads("Death to the queen", 0 , true);
        //struct exampleThreadData *thread4 = evilThreads("I'm a duck", 0 , true);
        //struct exampleThreadData *thread5 = evilThreads("IMASTRUCTSANDSTUFF", 0 , true);
	//SDL_WaitThread(thread2,NULL);
	//getting();

	//initilaizes SDL and sets up the window, stores everything in mainData
	UI_Initialize();
	SDL_WaitThread(mainData->UI_Thread, NULL);
}






