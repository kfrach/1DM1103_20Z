DEPS=main.o obsluga_pliku.o operacje_matematyczne.o


zad6: $(DEPS)
	cc $(DEPS) -o $@ -Wall --pedantic

%.o:%.c
	cc -c $^ -o $@


clean:
	rm -f main
	rm -f *.o

test: main
	./main 1 2 3