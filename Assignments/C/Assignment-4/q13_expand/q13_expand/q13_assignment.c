#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define SIZE 20

//character range is valid only if it can be expanded
//eg. a-g is valid   g-a is invalid

int checkValidCharRange(char *str, int start, int end) {

	if ((isupper(str[start]) && isupper(str[end])) && (str[start] < str[end]))
		return 1;
	else if ((islower(str[start]) && islower(str[end])) && (str[start] < str[end]))
		return 1;
	else if ((isdigit(str[start]) && isdigit(str[end])) && (str[start] < str[end]))
		return 1;
	else
		return 0;
}

//checking whether the string is valid or invalid

int checkValidShorthandStr(char *str) {
	int idx,start,end;

	//valid digits are alphabet , digit, -
	for (idx = 0;str[idx] != '\0';idx++) {
		if (isupper(str[idx]) || islower(str[idx]) || isdigit(str[idx]) || str[idx] == '-')
			continue;
		break;
	}
	if (idx != strlen(str))
		return 0;
	if (str[0] == '-' || str[strlen(str)-1] == '-')
		return 0;

	//check for continuous hiphens eg. a----r should be same as a-r

	start = 0;
	end = 0;
	for (idx = 1;idx<strlen(str)-1;idx++) {
		if (str[idx] != '-')
			continue;
		start = idx-1;
		while (str[idx] == '-')
			idx++;
		end = idx;
		if (!checkValidCharRange(str, start, end))
			return 0;
	}
	return 1;
}

//Finding length of expected string to allocate memory

int getExpandedLen(char *str) {
	int start, end, idx, expLen;
	expLen = strlen(str);
	for (idx = 1;idx < strlen(str) - 1;idx++) {
		if (str[idx] != '-')
			continue;
		start = idx - 1;
		while (str[idx] == '-')
			idx++;
		end = idx;
		expLen += (str[end] - str[start] - 2);
	}
	return expLen;
}

//function to expand the string

void expand(char *inputStr, char *outputStr) {
	int id1 = 0, id2 = 0, start, end;
	char temp;
	while(id1<strlen(inputStr)) {
		if (inputStr[id1] != '-') {
			outputStr[id2++] = inputStr[id1++];
		}
		else {
			start = id1-1;
			while (inputStr[id1] == '-')
				id1++;
			end = id1;
			temp = inputStr[start]+1;
			while (temp < inputStr[end]) {
				outputStr[id2] = temp;
				temp = temp + 1;
				id2++;
			}
		}
	}
	outputStr[id2] = '\0';
}
void main() {
	char shortStr[SIZE],*expandStr=NULL,proceed;
	printf("Choose option from menu\n");
	do {
		printf("Expand the shorthand notation of the string (ex : a-dhbd0-3) : ");
		gets(shortStr) ;

		//check for valid string

		if (checkValidShorthandStr(shortStr)) {

			//Allocate memory for resultant string

			expandStr = (char *)malloc((getExpandedLen(shortStr) + 1) * sizeof(char));
			expand(shortStr, expandStr);
			printf("Expanded string : %s\n", expandStr);
			free(expandStr);
		}
		else
			printf("Enter valid string\n");

		printf("Do you want to continue :Y/N\n");
		proceed = getchar();
		getchar();
	} while ('Y' == proceed || 'y' == proceed);
	getch();
}