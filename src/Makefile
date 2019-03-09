all:main.o faro.o files/print_faro_val.o
	clang main.o faro.o files/print_faro_val.o -o test

all2: main.o getInput.o print_ll.o files/print_faro_val.o shuffle_ll.o
	clang main.o getInput.o print_ll.o files/print_faro_val.o shuffle_ll.o -o test

main.o: main.c headers.h
	clang main.c -c

getInput.o: getInput.c headers.h
	clang getInput.c -c

print_ll.o: print_ll.c headers.h
	clang print_ll.c -c
shuffle_ll.o: shuffle_ll.c headers.h
	clang shuffle_ll.c -c

faro.o: faro.c headers.h
	clang faro.c -c

clean:
	rm *.o
