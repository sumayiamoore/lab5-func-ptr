#include <stdio.h>
#include <stdlib.h>

/* IMPLEMENT ME: Declare your functions here */
int add (int a, int b);
int subtract (int a, int b);
int multiply (int a, int b);
int divide (int a, int b);
int quit (int a, int b);
int invalid (int a, int b);

int main (void)
{
	/* IMPLEMENT ME: Insert your algorithm here */
	int a = 6, b = 3;
	unsigned char choice;

	/* one slot for every possible character, so any input is a safe index */
	int (*operations[256]) (int, int);
	for (int i = 0; i < 256; i++)
		operations[i] = invalid;

	operations['0'] = add;
	operations['1'] = subtract;
	operations['2'] = multiply;
	operations['3'] = divide;
	operations['4'] = quit;

	/* keep asking until the user picks 4 (exit) */
	while (1) {
		printf ("Operand 'a' : %d | Operand 'b' : %d\n", a, b);
		printf ("Specify the operation to perform (0 : add | 1 : subtract | 2 : Multiply | 3 : divide | 4 : exit): ");

		choice = '4';   /* if input runs out, default to exit */
		scanf (" %c", &choice);

		/* the character picks the function, no if or switch needed */
		int x = operations[choice] (a, b);
		printf ("x = %d\n", x);
	}

	return 0;
}

/* IMPLEMENT ME: Define your functions here */
int add (int a, int b) { printf ("Adding 'a' and 'b'\n"); return a + b; }
int subtract (int a, int b) { printf ("Subtracting 'b' from 'a'\n"); return a - b; }
int multiply (int a, int b) { printf ("Multiplying 'a' and 'b'\n"); return a * b; }
int divide (int a, int b) { printf ("Dividing 'a' by 'b'\n"); return a / b; }

/* ends the program; returns int only so it fits in the array */
int quit (int a, int b) { exit (0); }

/* any key that is not 0-4 lands here instead of going out of bounds */
int invalid (int a, int b) { printf ("Invalid operation\n"); return 0; }