
DEPS=main.o dziekanat.o studenci.o


p7_3: $(DEPS)
	cc $(DEPS) -o $@ -Wall --pedantic

%.o:%.c
	cc -c $^ -o $@


clean:
	rm -f main
	rm -f *.o

test: main
	./main 1 2 3