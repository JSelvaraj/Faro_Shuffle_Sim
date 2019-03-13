all:faro_shuffle.o faro_ll.o files/print_faro_val.o getBinary.o
	clang -lm faro_shuffle.o getBinary.o faro_ll.o files/print_faro_val.o  -o faro_shuffle

faro_shuffle.o: faro_shuffle.c headers.h
	clang faro_shuffle.c -c

faro_ll.o: faro_ll.c headers.h
	clang faro_ll.c -c

getBinary.o: getBinary.c
	clang getBinary.c -c

clean:
	rm *.o faro_shuffle
