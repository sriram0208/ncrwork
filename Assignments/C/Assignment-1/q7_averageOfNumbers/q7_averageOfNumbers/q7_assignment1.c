#include<stdio.h>
#include<stdlib.h>
void main()
{
	int min = INT_MAX, num, max = 0, sum = 0, cnt = 0;
	printf("enter a number :");
	scanf_s("%d", &num);
	while (num > 0)
	{
		if (num < min)
			min = num;
		if (num > max)
			max = num;
		sum = sum + num;
		cnt++;
		printf("enter a number :");
		scanf_s("%d", &num);
	}
	printf("no. of pos values :%d\nmin :%d\nmax :%d\navg :%f\n", cnt, min, max, (float)sum / cnt);
	getch();
}