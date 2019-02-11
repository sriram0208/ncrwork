#include<stdio.h>
#define SIZE 20
void main() {
	char(*s)[SIZE];
	int n,i;
	printf("Enter no. of strings :");
	scanf_s("%d", &n);
	getchar();
	s = (char(*)[SIZE])malloc(n * SIZE);
	for (i = 0;i < n;i++)
		gets(s[i]);
	printf("The strings entered are :\n\n");
	for (i = 0;i < n;i++)
		printf("%s\n", s[i]);
	getchar();
}