all: app.out

app.out: main.o func.o
	gcc main.o func.o -o app.out

main.o: main.c func.h
	gcc -c main.c -o main.o

func.o: func.c func.h
	gcc -c func.c -o func.o

run: app.out
	./app.out

clean:
	rm -f *.o app.out