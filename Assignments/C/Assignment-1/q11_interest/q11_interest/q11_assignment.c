#include<stdio.h>
void main()
{
	int P = 500000, T = 10, R = 5;
	float SI;
	SI = (float)(P*T*R) / 100;
	printf("%f\n", SI);
	getch();
}