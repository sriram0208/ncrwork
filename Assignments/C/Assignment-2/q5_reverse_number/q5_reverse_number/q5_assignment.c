#include<stdio.h>
void main() {
	int n,rw = 0, d;
	printf("Enter the number :");
	scanf_s("%d", &n);
	while (n != 0) {
		d = n % 10;
		rw = rw * 10 + d;
		n = n / 10;
	}
	printf("%d", rw);
	getch();
}