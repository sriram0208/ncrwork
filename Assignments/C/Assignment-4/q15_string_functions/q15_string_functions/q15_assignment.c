#include<stdio.h>
#include<stdlib.h>
#define SIZE 50

//Function to find length of a string

int str_length(char *str) {
	int count = 0;
	for (;*str != '\0';str++)
		count++;
	return count;
}

//Function to reverse a string

void str_reverse(char *str) {

	char *ptr1, *ptr2;
	char temp;
	for(ptr1 = str, ptr2 = str + str_length(str) - 1 ; ptr1 < ptr2 ; ptr1++, ptr2--) {
		//swap the characters

		temp = *ptr1;
		*ptr1 = *ptr2;
		*ptr2 = temp;
	}
}

//Function to copy a string into another string

void str_copy(char *str1, char *str2) {
	while ((*str1++ = *str2++)!='\0');
}

//Function to concatenate two strings

void str_concat(char *str1, char *str2) {
	
	int i, j;
	for (i = 0;str1[i] !='\0';i++);
	for (j = 0;str2[j] != '\0';i++,j++) {
		str1[i] = str2[j];
	}
	str1[i] = '\0';
}

//Function to compare whether two strings are equal

int str_compare(char *str1, char *str2) {
	while (*str1 == *str2) {
		if (*str1 == '\0')
			return *str1 - *str2;
		str1++;
		str2++;
	}
	return *str1 - *str2;
}
void main() {
	char s1[SIZE], s2[SIZE], choice,proceed;
	int res;

	do {
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
				if ((strlen(s1) + strlen(s2)) > SIZE)
					printf("Cannot concatenate , Array size insufficient");
				str_concat(s1, s2);
				printf("Concatenated string : %s", s1);
				break;

			case '4':printf("Enter 1st string for comparing :");
				gets(s1);
				printf("Enter 2nd string for comparing :");
				gets(s2);

				res = str_compare(s1, s2);
				if (res == 0)
					printf("Both strings are same\n");
				else
					printf("Strings are different\n");
				break;
			}

		printf("Do you want to continue :Y/N\n");
		proceed = getchar();
		getchar();

	} while ('y' == proceed || 'Y' == proceed);
	getch();
}