#include<stdio.h>
#define LEN 20
FILE *fp;
void countCharacters() {
	char ch;
	int digits = 0, alpha = 0, spaces = 0, special_chars = 0, total_len = 0;
	while (!feof(fp)) {
		ch = fgetc(fp);
		if ((ch >= 'a'&&ch <= 'z') || (ch >= 'A'&&ch <= 'Z'))
			alpha++;
		if ((ch >= '0'&&ch <= '9'))
			digits++;
		if (ch == ' ')
			spaces++;
		total_len++;
	}
	special_chars = total_len - (digits + alpha + spaces);
	printf("Total no. of :\n alphabets : %d\n digits :%d\n spaces :%d\n specialcharacters :%d\n", alpha, digits, spaces, special_chars);
	getch();
}


int str_len(char *s) {
	int i, cnt = 0;
	for (i = 0; s[i] != '\0'; i++)
		cnt++;
	return cnt;
}


void rotate(char *s) {
	int i, j, len;
	char temp;
	len = str_len(s);
	for (i = 0, j = len - 1; i <= j; i++, j--)
	{
		temp = *(s + i);
		*(s + i) = *(s + j);
		*(s + j) = temp;
	}
}


void findMatchingWord(char *s) {
	char *temp, ch;
	int len, i;
	len = str_len(s);
	//copy the word to be matched in to a temp string
	temp = (char *)malloc((len + 1) * sizeof(char));
	strcpy_s(temp, len + 1, s);

	//rotate the string
	rotate(s);

	//search for the string and replace it with rotated string
	while (!feof(fp)) {
		for (i = 0; i < len; i++) {
			ch = fgetc(fp);
			if (ch != temp[i])
				break;
		}
		if (i == len) {
			fseek(fp, (-1)*len, SEEK_CUR);
			for (i = 0; i < len; i++)
				fputc(s[i], fp);

			fseek(fp, 0, SEEK_END);
		}
	}

	//come to the starting position to print the file content
	fseek(fp, 0, SEEK_SET);
	while (!feof(fp)) {
		ch = fgetc(fp);
		putchar(ch);
	}
}


void replaceAllTabs() {
	char *p, ch;
	int len = 0, i, cnt = 0;
	while (!feof(fp)) {
		ch = fgetc(fp);
		putchar(ch);
		len++;
	}
	fseek(fp, 0, SEEK_SET);
	while (!feof(fp)) {
		ch = fgetc(fp);
		cnt++;
		if (ch == '\t') {
			p = (char *)malloc((len - cnt - 1) * sizeof(char));
			fgets(p, len - cnt + 1, fp);

			fseek(fp, cnt - 1, SEEK_SET);
			fputc('\\', fp);
			fputc('t', fp);
	
			fputs(p,fp);
			fseek(fp, 0, SEEK_SET);
			cnt = 0;
		}
	}
	while (!feof(fp)) {
		ch = fgetc(fp);
		putchar(ch);
	}
}


void main() {
	char choice, s[LEN] = "hello";
	fopen_s(&fp, "sample.txt", "r+");
	printf("Choose the task to be performed :\n");
	printf("a)Count the number of alphabets,digits,special charachters in the file\n");
	printf("b)Remove all comments from the file content\n");
	printf("c)Find a matching word in the file and rotate the word and place it in the same file\n");
	printf("d)Replace all tabs present in the file content with it\n");
	printf("Enter 0 to exit\n");

	printf("\nEnter your choice :\n");
	choice = getchar();
	while (choice != '0')
	{
		
		switch (choice) {
		case 'a':countCharacters(fp);
			break;
			//case 'b':removeComments(fp);
			//	break;
		case 'c':
			findMatchingWord(s);
			break;
		case 'd':
			//replaceAllTabs();
			//break;
		default:
			break;
		}
		printf("\nEnter your choice :\n");
		choice = getchar();
	}
	getch();
}