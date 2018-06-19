all: learn
	
learn:
	gcc -Wall -Werror -fsanitize=address -o learn learn.c setup.c guass.c matrixMethods.c
clean:
	rm -rf learn
