#include<stdio.h>
void main() {
	int x[8] = { 10,20,30,40,50,60,70,80 };

	printf("x gives the base address of the array: %d\n", x);
	printf("(x+2) gives address of element at index 2: %d\n", (x + 2));
	printf("*x gives value of first element of array: %d\n", *x);
	printf("(*x+2) adds 2 to the value of element at x: %d\n", (*x+2));
	printf("*(x+2) gives value of element at index 2: %d\n", *(x+2));
	getch();

}