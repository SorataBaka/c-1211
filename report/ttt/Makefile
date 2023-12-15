FLAGS = -lncurses

all: ttt

ttt: main.o board.o game.o
	gcc main.o board.o game.o -o ttt ${FLAGS}

main.o: main.c game.h

board.o: board.c board.h

game.o: game.c game.h

.c.o:
	cc -c $< $(FLAGS)

clean:
	-rm *.o

distclean: clean
	-rm ./ttt

dist:	distclean
	( cd ..; tar zcvf ttt.tgz ttt/* )

.SUFFIXES: .c .o

.PHONE: all clean distclean dist