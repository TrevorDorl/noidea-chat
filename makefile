CFLAGS=-W -Wall -pedantic -std=c99

all:
	gcc -c ./ui/ui.c -o ./objects/ui.o ${CFLAGS}
	gcc -c ./main/main.c `sdl-config --libs --cflags` -o ./objects/main.o ${CFLAGS}
	gcc ./objects/main.o ./objects/ui.o -L ${CFLAGS} -o chat

clean:
	rm chat
	
