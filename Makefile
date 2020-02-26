double_conv:
	gcc double_conv.c -o convert
MMM : MMM_computation.c
	gcc -Ofast -o MMM_computation MMM_computation.c -lm -std=c99
clean :
	rm MMM_computation linpack convert
