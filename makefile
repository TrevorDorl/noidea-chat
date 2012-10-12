CFLAGS=-Wall -g

all:
	gcc main.c ui.c `sdl-config --libs --cflags` -o chat	

clean:
	rm chat
	
