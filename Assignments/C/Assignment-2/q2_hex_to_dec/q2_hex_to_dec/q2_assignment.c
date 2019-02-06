#include<stdio.h>
#include<string.h>
#include<math.h>
int binToDec(char bin[]) {
	int len, i, num = 0;
	len = strlen(bin);
	for (i = len - 1;i >= 0;i--)
	{
		if (bin[i] == '1')
			num += (int)pow(2, len - (i + 1));
	}
	return num;
}
void hexToBin(char hex[]) {
	int i;
	for (i = 0;hex[i] != '\0';i++) {
		switch (hex[i]) {
		case '0':	printf("0000");
					break;
		case '1':	printf("0001");
					break;
		case '2':	printf("0010");
					break;
		case '3':	printf("0011");
					break;
		case '4':	printf("0100");
					break;
		case '5':	printf("0101");
					break;
		case '6':	printf("0110");
					break;
		case '7':	printf("0111");
					break;
		case '8':	printf("1000");
					break;
		case '9':	printf("1001");
					break;
					
		case 'A':	printf("1010");
					break;
		case 'B':	printf("1011");
					break;
		case 'C':	printf("1100");
					break;
		case 'D':	printf("1101");
					break;
		case 'E':	printf("1110");
					break;
		case 'F':	printf("1111");
					break;
		}
	}
	printf("\n");
}
void main() {
	char bin[40],hex[10];
	int num;
	printf("Enter binary number :");
	gets(bin);
	printf("%x\n",binToDec(bin));

	printf("Enter hexa-decimal number (in capitals) :");
	gets(hex);
	hexToBin(hex);
	getch();
}