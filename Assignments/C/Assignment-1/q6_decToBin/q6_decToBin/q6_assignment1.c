#include<stdio.h>
void main()
{
	unsigned int num;
	int arr[4], i,j;
	printf("Enter a number :");
	scanf_s("%d", &num);
	if (num < 32)
	{
		for (i = 0;i < 5;i++)
		{
			arr[i] = num % 2;
			num = num/2;
		}
		i = 4;
		while (arr[i] == 0)
			i--;
		for (j = i;j >= 0;j--)
		{
			printf("%d", arr[j]);
		}

	}
	else
		printf("Number is greater than 31");
	getch();
}