#include<stdio.h>
#include<string.h>
#include<math.h>
#define SIZE 50
//This function converts integer to binary
void itob(int n,char *s) {
	int i = 0;
	while (n != 0) {
		s[i] = '0'+(n % 2);
		n = n / 2;
		i++;
	}
	s[i] = '\0';
	_strrev(s);
}
void itoh(int n, char *s) {
	int i = 0,d;
	while (n != 0) {
		d = n % 16;
		switch (d) {
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:
			s[i] = '0' + d;
			break;
		case 10:s[i] = 'A';
			break;
		case 11:s[i] = 'B';
			break;
		case 12:s[i] = 'C';
			break;
		case 13:s[i] = 'D';
			break;
		case 14:s[i] = 'E';
			break;
		case 15:s[i] = 'F';
			break;
		}
		n = n / 16;
		i++;
	}
	s[i] = '\0';
	_strrev(s);
}
void main() {
	char s[SIZE];
	int num;
	printf("Enter decimal number :");
	scanf_s("%d", &num);
	itob(num,s);
	printf("Binary of %d is : %s\n", num,s);
	itoh(num, s);
	printf("Hexadecimal of %d is : %s", num, s);
	getch();
}