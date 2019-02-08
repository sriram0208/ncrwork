#include<stdio.h>
void main() {
	int num,d,sum=0;
	printf("Enter a number less than 128 :");
	scanf_s("%d", &num);
	if (num > 127)
		printf("Number has more than 8 bits");
	else {
		while (num != 0) {
			d = num % 2;
			sum += d;
			num = num / 2;
		}
		printf("No. of bits as 1 : %d\n", sum);
	}
	getch();
}