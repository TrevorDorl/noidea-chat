CFLAGS=-W -Wall -pedantic -std=c99
SDLFLAGS=`sdl-config --libs --cflags`
LIBAVFLAGS=`pkg-config --libs libavformat libavcodec libswscale libavutil libavdevice` -lm


all:
	gcc -c ./ui/ui.c -o ./objects/ui.o ${CFLAGS} ${SDLFLAGS}
	gcc -c ./main/main.c -o ./objects/main.o ${CFLAGS} ${SDLFLAGS}
	gcc -c ./WeMic/WeMic.c -o ./objects/WeMic.o ${CFLAGS} ${SDLFLAGS} ${LIBAVFLAGS}
	gcc ./objects/* -o ./noidea-chat ${CFLAGS} ${SDLFLAGS} ${LIBAVFLAGS}

clean:
	rm noidea-chat
	rm objects/*
	
