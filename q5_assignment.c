#include<stdio.h>
void main()
{
	int n,temp,rw=0,d;
	printf("Enter the number:");
	scanf("%d",&n);
	temp=n;
	while(n!=0)
	{
		d=n%10;
		rw=rw*10+d;
		n=n/10;
	}
	if(rw==temp)
		printf("%d is palindrome",temp);
	else
		printf("%d is not palindrome",temp);
}