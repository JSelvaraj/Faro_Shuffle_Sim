all: main.o getInput.o print_ll.o files/print_faro_val.o
	clang main.o getInput.o print_ll.o files/print_faro_val.o -o test

main.o: main.c headers.h
	clang main.c -c

getInput.o: getInput.c headers.h
	clang getInput.c -c

print_ll.o: print_ll.c headers.h
	clang print_ll.c -c

clean:
	rm *.o
