exec    = ./bin/a.out
sources = $(wildcard src/*.c)
objects = $(sources:.c=.o)
flags   = -g -Wall -lm -ldl -fPIC -rdynamic

$(exec) : $(objects)
	gcc $(objects) $(flags) -o $(exec)

%.o: %.c include/%.h
	gcc -c $(flags) $< -o $@

run:
	-./bin/a.out ./examples/main.kol

clean:
	-rm ./bin/*.out
	-rm *.o
	-rm *.a
	-rm src/*.o