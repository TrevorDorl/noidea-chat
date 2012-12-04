struct main_ProgramData
{
	//our video surface
	SDL_Surface *UI_window;
	SDL_Thread *UI_renderthread;
	SDL_Thread *UI_initandeventthread;

	//used to make the render thread wait until it's needed.
	SDL_sem *UI_renderhold;
	struct VIDEO_webcamdata *LocalWebcamData;
	int verbose;
};

struct main_ProgramData *mainData;
void main_cleanup();
