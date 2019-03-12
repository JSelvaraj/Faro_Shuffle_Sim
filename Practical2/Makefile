all:main.o faro_ll.o files/print_faro_val.o getBinary.o getIntLength.o
	clang -lm main.o getBinary.o faro_ll.o getIntLength.o files/print_faro_val.o  -o faro_shuffle

main.o: main.c headers.h
	clang main.c -c

faro_ll.o: faro_ll.c headers.h
	clang faro_ll.c -c

getBinary.o: getBinary.c headers.h
	clang getBinary.c -c

getIntLength.o: getIntLength.c headers.h
	clang getIntLength.c -c

clean:
	rm *.o faro_shuffle utf
