#include<stdio.h>
#include<string.h>
#define SIZE 20
void main() {
	char str[SIZE];
	int len,cnt=0,i,j;
	printf("Enter any string :");
	gets(str);
	len = strlen(str);
	for (i = 0;str[i] != '\0';i++) {
		cnt = 0;
		for (j = i;cnt < len;j = (j + 1) % len)
		{
			printf("%c", str[j]);
			cnt++;
		}
		printf("\n");
	}
	getch();
}