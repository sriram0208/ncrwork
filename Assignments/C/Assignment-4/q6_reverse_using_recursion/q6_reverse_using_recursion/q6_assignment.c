#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void reverse(char *p) {
	char ch;
	//if (strlen(p) == 1)
	if(*p=='\0')
		return;
	reverse(p + 1);
	ch = *p;
	strcpy_s(p,strlen(p+1)+1, p + 1);
	*(p + strlen(p)) = ch;
	printf("%s\n", p);
	
}
void main() {
	char *str = "sriram";
	char *p = (char *)malloc(strlen(str) + 1 * sizeof(char));
	strcpy_s(p,strlen(str)+1 ,str);
	reverse(p);
	printf("reverse of %s is %s", str, p);
	getch();
}