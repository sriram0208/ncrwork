#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int replace(char s[]) {
	int i,cnt=0;
	for (i = 0;s[i] != '\0';i++) {
		if (s[i] == ' ') {
			s[i] = '-';
			cnt++;
		}
	}
	return cnt;
}
void main() {
	char *cat = "The cat sat";
	char *p = (char *)malloc((strlen(cat)+1) * sizeof(char));
	strcpy_s(p,strlen(cat)+1, cat);
	int n = replace(p);
	printf("Modified string : %s\n No of spaces replaced : %d", p, n);
	getch();
}