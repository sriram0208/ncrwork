#include<stdio.h>
void main()
{
	int n, i, j;
	printf("enter a number :9");
	scanf_s("%d", &n);
	for (i = 1;i <= n;i++)
	{
		for (j = i;j < n;j++)
			printf(" ");
		for (j = i;j > 1;j--)
			printf("%d", j);
		for (j = 1;j <= i;j++)
			printf("%d", j);
		printf("\n");
	}
	getch();
}