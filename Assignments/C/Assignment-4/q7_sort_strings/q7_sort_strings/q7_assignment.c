#include<stdio.h>
#include<string.h>
#define ROWS 20
#define COLUMNS 50
void main() {
	char s[ROWS][COLUMNS],temp[COLUMNS];
	int n, i,j;
	printf("Enter no. of strings :");
	scanf_s("%d", &n);
	getchar();
	printf("Enter %d no. of strings :\n",n);
	for (i = 0;i < n;i++)
		gets(s[i]);
	for (i = 0;i < n;i++) {
		for(j=i+1;j<n;j++)
			if (strcmp(s[i], s[j]) > 0) {
				strcpy_s(temp,strlen(s[i])+1, s[i]);
				strcpy_s(s[i], strlen(s[j]) + 1, s[j]);
				strcpy_s(s[j], strlen(temp) + 1, temp);
			}
	}
	printf("Sorted list of strings :\n");
	for (i = 0;i < n;i++)
		printf("%s\n",s[i]);
	getch();
}