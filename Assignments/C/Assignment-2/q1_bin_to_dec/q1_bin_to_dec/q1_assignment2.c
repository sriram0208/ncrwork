#include<stdio.h>
#include<string.h>
#include<math.h>
void binToDec(char bin[]){
	int len,i, num = 0;
	len = strlen(bin);
	for (i = len - 1;i >= 0;i--)
	{
		if (bin[i] == '1')
			num += (int)pow(2, len - (i + 1));
	}
	printf("%d\n", num);
}
void DecToBin(int n){
	int bin[40],i=0,j;
	while (n != 0) {
		bin[i] = n % 2;
		n = n / 2;
		i++;
	}
	for (j = 0;j < i;j++)
		printf("%d", bin[j]);
}
void main(){
	char bin[40];
	int num;
	printf("Enter binary number :");
	gets(bin);
	binToDec(bin);

	printf("Enter decimal number :");
	scanf_s("%d", &num);
	DecToBin(num);
	getch();
}