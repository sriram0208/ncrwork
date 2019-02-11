#include<stdio.h>
#define SIZE
void expand(char *s1, char *s2) {
	int i, j;
	char k;
	for (i = 0,j=0;s1[i] != '\0';i++) {
		if (s1[i] == '-') {
			for (k = s1[i - 1] + 1;k < s1[i + 1];k++)
			{
				s2[j] = k;
				j++;
			}
		}
		else {
			s2[j] = s1[i];
			j++;
		}
	}
	s2[j] = '\0';
}
void main() {
	char *s1, s2[SIZE];
	s1 = "0123a-e1-4";
	expand(s1, s2);
	printf("%s expansion is : %s\n",s1,s2);

	s1 = "0-9";
	expand(s1, s2);
	printf("%s expansion is : %s\n", s1, s2);

	s1 = "a-z";
	expand(s1, s2);
	printf("%s expansion is : %s\n", s1, s2);
	getch();
}