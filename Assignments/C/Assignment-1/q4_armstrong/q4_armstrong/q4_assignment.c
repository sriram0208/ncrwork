#include<stdio.h>
void main()
{
	int n,temp,d,sum=0;
	printf("Enter the number :");
	scanf_s("%d",&n);
	temp=n;
	while(n!=0)
	{
		d=n%10;
		sum+=d*d*d;
		n=n/10;
	}
	if(sum==temp)
		printf("%d is armstrong number",temp);
	else
		printf("%d is not armstrong number",temp);
	getch();
}