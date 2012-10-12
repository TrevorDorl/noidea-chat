CFLAGS=-W -Wall -pedantic -std=c99

all:
	gcc main.c ui.c `sdl-config --libs --cflags` -o chat ${CFLAGS}

clean:
	rm chat
	
