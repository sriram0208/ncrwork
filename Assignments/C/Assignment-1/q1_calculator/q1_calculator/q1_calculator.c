#include<stdio.h>
int res=-1;
long int res1=-1;
float res2=-1;

int add(int,int);
int sub(int,int);
long int mul(int,int);
float div(int,int);

void main()
{
	int a=10,b=20;
	res=add(a,b);
	printf("%d\n",res);

	res=sub(a,b);
	printf("%d\n",res);

	res1=mul(a,b);
	printf("%ld\n",res1);

	res2=div(a,b);
	printf("%f\n",res2);

	getch();
}