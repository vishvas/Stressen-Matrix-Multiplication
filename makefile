all: run

run:  
	gcc -o stressen.o stressen.c -lm
	
clean: 
	rm stressen.o
