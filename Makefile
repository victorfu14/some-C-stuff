MMM : MMM_computation.c
	gcc -Ofast -o MMM_computation MMM_computation.c -lm -std=c99
clean :
	rm MMM_computation linpack
