#include<stdio.h>
#include<stdlib.h>
#define SIZE 50
int str_length(char *p) {
	int count = 0;
	for (;*p != '\0';p++)
		count++;
	return count;
}
void str_reverse(char *str) {

	char *p1, *p2;
	char temp;
	for(p1 = str, p2 = str + str_length(str) - 1;p1 < p2;p1++, p2--) {
		temp = *p1;
		*p1 = *p2;
		*p2 = temp;
	}
}
void str_copy(char *s1, char *s2) {
	while ((*s1++ = *s2++)!='\0');
}
void str_concat(char *s1, char *s2) {
	
	int i, j;
	for (i = 0;s1[i] !='\0';i++);
	for (j = 0;s2[j] != '\0';i++,j++) {
		s1[i] = s2[j];
	}
	s1[i] = '\0';
}
int str_compare(char *s1, char *s2) {
	while (*s1 == *s2) {
		if (*s1 == '\0')
			return *s1 - *s2;
		s1++;
		s2++;
	}
	return *s1 - *s2;
}
void main() {
	char s1[SIZE], s2[SIZE], choice;
	int res;
	printf("Choose the option \n1)string reverse\n2)string copy\n3)string concatenate\n4)string compare\n");
	choice = getchar();
	getchar();
	switch (choice) {
		case '1':printf("Enter the string to reverse\n");
			gets(s1);
			str_reverse(s1);
			printf("Reverse of the string is : %s", s1);
			break;
		case '2':printf("Enter the string to copy\n");
			gets(s1);
			str_copy(s2, s1);
			printf("Copied string to second string : %s", s2);
			break;
		case '3':printf("Enter the first string :\n");
			gets(s1);
			printf("Enter the second string :\n");
			gets(s2);
			str_concat(s1, s2);
			printf("Concatenated string : %s", s1);
			break;
		case '4':printf("Enter 1st string for comparing :");
			gets(s1);
			printf("Enter 2nd string for comparing :");
			gets(s2);

			res=str_compare(s1, s2);
			if (res == 0)
				printf("Both strings are same\n");
			else
				printf("Strings are different\n");
			break;
		}
	getch();
}