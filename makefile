CFLAGS=-Wall -g

all:
	gcc main.c video.c `sdl-config --libs --cflags` -o chat	

clean:
	rm chat
	
