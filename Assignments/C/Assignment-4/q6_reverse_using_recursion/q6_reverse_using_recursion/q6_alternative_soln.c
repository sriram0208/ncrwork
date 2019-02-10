#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void reverse(char *p, int i, int j) {

	int temp;
	if (i >= j)
		return;
	reverse(p, i + 1, j - 1);
	temp = p[i];
	p[i] = p[j];
	p[j] = temp;

}
void main() {
	char *str = "sriram";
	char *p = (char *)malloc(strlen(str) + 1 * sizeof(char));
	strcpy_s(p, strlen(str) + 1, str);
	reverse(p, 0, strlen(str) - 1);
	printf("reverse of %s is %s", str, p);
	getch();
}