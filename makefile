all: shell.c
	gcc -o shell shell.c
clean:
	rm a.out
	rm *~
run: all
	./shell
