#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void delete(char *s, char ch) {

	char  *p;
	int i,j,cnt=0;
	for (i = 0;s[i] != '\0';i++)
		if (s[i] != ch)
			cnt++;
	p = (char *)malloc((cnt + 1) * sizeof(char));
	for (i = 0, j = 0;s[i] != '\0';i++)
		if (s[i] != ch)
		{
			p[j] = s[i];
			j++;
		}
	p[j] = '\0';
	strcpy_s(s,strlen(s)+1, p);
	printf("Modified string :%s\n", s);
	free(p);
}
void main() {
	char s[20],ch;
	int i, j, cnt = 0;
	printf("Enter any string :");
	gets(s);
	printf("\nEnter character to be deleted :");
	ch = getchar();
	delete(s, ch);
	
	getch();
}