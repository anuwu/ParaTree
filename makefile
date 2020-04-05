output : data.h create.h util.h print.h insert.h dll.h breadth.h manual_traverse.h main.o create.o util.o print.o insert.o dll.o breadth.o manual_traverse.o
	gcc -o final.exe main.o create.o util.o print.o insert.o dll.o breadth.o manual_traverse.o
	./final.exe
	make clean

main.o : main.c
	gcc -c main.c

create.o : create.c
	gcc -c create.c


util.o : util.c
	gcc -c util.c

print.o : print.c
	gcc -c print.c


manual_traverse.o : manual_traverse.c
	gcc -c manual_traverse.c

insert.o : insert.c
	gcc -c insert.c

dll.o : dll.c
	gcc -c dll.c

breadth.o : breadth.c
	gcc -c breadth.c

clean :
	rm *.o
	rm *.exe
