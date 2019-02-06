#include<stdio.h>
long int fact(int n) {
	if (n == 0)
		return 1;
	return n * fact(n - 1);
}
void main() {
	int n;
	printf("Enter a number :");
	scanf_s("%d", &n);
	printf("%ld", fact(n));
	getch();
}