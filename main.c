#include <stdio.h>
#include <SDL.h>

int main(){
	fprint("WOWSA\n");
	threadcreate(threadFiller("okay" , 0));
	SDL_Delay( 5000 );
	return 0;
}
