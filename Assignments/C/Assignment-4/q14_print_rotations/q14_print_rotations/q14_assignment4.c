#include<stdio.h>
#include<string.h>
#define SIZE 20
void printRotations(char *str) {
	int len = strlen(str),idx1,idx2,cnt;
	for (idx1 = 0;str[idx1] != '\0';idx1++) {
		cnt = 0;
		for (idx2 = idx1;cnt < len;idx2 = (idx2 + 1) % len)
		{
			printf("%c", str[idx2]);
			cnt++;
		}
		printf("\n");
	}
}
void main() {
	char str[SIZE];
	printf("Enter any string :");
	gets(str);
	printRotations(str);
	getch();
}