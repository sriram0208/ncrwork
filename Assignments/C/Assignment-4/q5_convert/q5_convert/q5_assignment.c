#include<stdio.h>
#include<string.h>
void lowerToUpper(char *s) {
	for (;*s != '\0';s++) {
		if (*s >= 'a' &&*s <= 'z')
			*s = *s + ('A' - 'a');
	}
}
void upperToLower(char *s) {
	for (;*s != '\0';s++) {
		if (*s >= 'A' && *s <= 'Z')
			*s = *s + ('a' - 'A');
	}
}
void main() {
	char s[50];
	int choice;
	printf("Enter a string :");
	gets(s);
	printf("Enter choice 1)Lower to upper\n2)Upper to lower\n");
	scanf_s("%d", &choice);
	switch (choice) {
		case 1:	lowerToUpper(s);
				printf("%s\n", s);
				break;
		case 2:	upperToLower(s);
				printf("%s\n", s);
				break;
	}
	printf("Modified string : %s", s);
	getch();
}