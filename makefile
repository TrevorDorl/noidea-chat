iCFLAGS=-W -Wall -pedantic -std=c99

all:
	gcc -c ./ui/ui.c -o ./objects/ui.o ${CFLAGS} `sdl-config --libs --cflags`
	gcc -c ./main/main.c `sdl-config --libs --cflags` -o ./objects/main.o ${CFLAGS}
	gcc ./objects/main.o ./objects/ui.o ${CFLAGS} -o chat `sdl-config --libs --cflags`

clean:
	rm chat
	rm objects/*
	
