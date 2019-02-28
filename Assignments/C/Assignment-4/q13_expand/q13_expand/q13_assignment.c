#include<stdio.h>
#define SIZE 20

int checkValidCharRange(char *str, int start, int end) {
	if(str[start-1] )
}
int checkValidShorthandStr(char *str) {
	int idx;
	for (idx = 0;str[idx] != '\0';idx++) {
		if (isUpper(str[idx]) || isLower(str[idx]) || isDigit(str[idx]) || str[idx] == '-')
			continue;
		break;
	}
	if (idx != strlen(str))
		return 0;
	if (str[0] == '-' || str[1] == '-')
		return 0;
	start = 0;
	end = 0;
	for (idx = 1;;idx++) {
		if (str[idx] != '-')
			continue;
		start = idx++;
		while (str[idx] == '-')
			idx++;
		end = idx - 1;
		if(checkValidCharRange(str,start,end)

	}
	return 1;
}
int expand(char *inputStr, char *outputStr) {
	int idx;
	if (checkValidShorthandStr(inputStr)) {
		for (idx = 0;;idx++) {
			if (inputStr[idx + 1] == '-') {

			}
		}
	}
	else
		return 0;
}
void main() {
	char shortStr[SIZE],*expandStr,choice;
	printf("Choose option from menu\n");
	printf("1)Expand a string\n0)Exit");
	scanf("%c", &choice);
	while (choice == '1') {
		printf("Enter shorthand notation of the string :");
		scanf("%s", shortStr);
		expand(shortStr,expandStr);
	} 
	getch();
}