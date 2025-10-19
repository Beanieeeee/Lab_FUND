all: app.out

app.out: main.o fucnk.o
	gcc main.o fucnk.o -o app.out -lm

main.o: main.c fucnk.h
	gcc -c main.c -o main.o

fucnk.o: fucnk.c fucnk.h
	gcc -c fucnk.c -o fucnk.o

run: app.out
	./app.out

clean:
	rm -f *.o app.out