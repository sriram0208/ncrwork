#include<stdio.h>
void main() {
	char * s[] = { "we will teach you how to ",
					"Move a mountain ",
					"Level a building ",
					"Erase the past ",
					"Make a million " };
	char *p;
	int i, j, cnt = 0;
	for (i = 0;i < 5;i++) {
		p = *(s+i);
		printf("%s\n", p);
		
		
		for (j = 0;*(p+j) != '\0';j++)
		{
			if ((*(p + j) == 'e'))
				cnt++;
		}
		printf("%d\n", cnt);
	}
	printf("No. of letters 'e' :%d", cnt);
	getch();
}