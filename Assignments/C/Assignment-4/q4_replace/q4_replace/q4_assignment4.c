#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define SIZE 50

//Function to replace spaces in a given string

int replace(char str[]) {
	int i,cnt=0;
	for (i = 0;str[i] != '\0';i++) {
		if (str[i] == ' ') {
			str[i] = '-';
			cnt++;
		}
	}
	return cnt;
}
void main() {
	char str[SIZE],*str_ptr=NULL,proceed;
	int no_spaces;
	do {
		printf("Enter the sentence :");
		gets(str);
		str_ptr = (char *)malloc((strlen(str) + 1) * sizeof(char));
		strcpy_s(str_ptr, strlen(str) + 1, str);
		no_spaces = replace(str_ptr);
		printf("Modified string : %s\n No of spaces replaced : %d\n", str_ptr, no_spaces);

		printf("Do you want to continue :Y/N\n");
		proceed = getchar();
		getchar();

	} while ('y' == proceed || 'Y' == proceed);
	free(str_ptr);
}