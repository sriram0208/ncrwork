#include<stdio.h>
long int invertponwards(long int num, int pos,int bits)
{
	long int temp = (((1 << (bits)) - 1) << (pos - bits));
	temp = num ^ temp;
	return temp;
}
void main()
{
	long int num;
	int position, no_bits;
	char proceed;
	do {

		printf("Enter a number--position--no. of bits to be inverted :");
		scanf_s("%ld%d%d", &num, &position, &no_bits);
		printf("Result : %ld\n", invertponwards(num, position, no_bits));
		printf("Do you want to continue ? Y/N\n");
		getchar();
		proceed=getchar();
	} while ('Y'== proceed);
	getchar();
}