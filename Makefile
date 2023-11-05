all: *.c *.h
	gcc -c *.c -std=c89
	ar rcs chredenc.a *.o

clean:
	rm -rf *.o

clear:
	clear
	make all
