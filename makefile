all: bin/brute_force_example

bin/brute_force_example: obj/brute_force_example.o obj/brute_force.o
	mkdir bin -p && gcc obj/brute_force_example.o obj/brute_force.o -o bin/brute_force_example

obj/brute_force_example.o: src/brute_force_example.c
	mkdir obj -p && gcc -c src/brute_force_example.c -o obj/brute_force_example.o

obj/brute_force.o: src/brute_force.c
	mkdir obj -p && gcc -c src/brute_force.c -o obj/brute_force.o

clean:
	rm -f obj/* bin/*
