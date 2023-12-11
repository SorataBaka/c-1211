all: seq sum
seq:	seq.c
	gcc seq.c -o seq
sum: 	sum.c
	gcc sum.c -o sum
clean:
	-rm sum seq
dist: clean
	( cd ..; tar zcvf proj-1.tgz proj-1/ )



.PHONY: all clean dist