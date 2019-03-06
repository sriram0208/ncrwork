#include<stdio.h>
int countLetters(char *strs[],int no_strs,char letter) {
	char *ptr;
	int i, j, cnt = 0;
	for (i = 0;i < no_strs;i++) {
		ptr = *(strs + i);
		for (j = 0;*(ptr + j) != '\0';j++)
		{
			if ((*(ptr + j) == letter))
				cnt++;
		}
	}
	return cnt;
}
void main() {
	char * strs[] = { "we will teach you how to ",
					"Move a mountain ",
					"Level a building ",
					"Erase the past ",
					"Make a million " };
	char letter,proceed;
	do {
		printf("Enter the letter to count its frequency in the string : ");
		scanf_s("%c",&letter);
		printf("No. of letters %c :%d\n", letter, countLetters(strs, 5, letter));
		getchar();
		printf("Do you want to continue? Y/N\n");
		proceed = getchar();
		getchar();

	} while ('Y' == proceed || 'y' == proceed);
	getch();
}