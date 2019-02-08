
#include<stdio.h>
void main() {
	float table[2][3] = { { 1.1,1.2,1.3},{2.1,2.2,2.3} };
	printf("Given instruction : float table[2][3] = { { 1.1,1.2,1.3},{2.1,2.2,2.3} };\n\n");
	printf("table gives the base address of given 2-D array : %u\n",table);
	printf("(table+1) gives the address of 2nd row of given 2-D array :%u\n", (table+1));
	printf("*(table+1) gives the starting address of 2nd row of given 2-D array :%u\n", *(table+1));
	printf("(*(table + 1) + 1) gives the address of 2nd element of 2nd row of given 2-D array : %u\n", (*(table + 1) + 1));
	printf("(*(table)+1) gives the address of 2nd element of 1st row : %u\n", (*(table)+1));
	printf("*(*(table + 1) + 1) gives value at 2nd row 2nd element : %.1f\n",*(*(table + 1) + 1));
	printf("*(*(table)+1)) gives value at 1st row 2nd element : %.1f\n",*(*(table)+1));
	printf("*(*(table + 1)) gives value at 2nd row 1st element : %.1f\n",*(*(table + 1)));
	printf("*(*(table) + 1)+1 adds 1 to the value at 1st row 2nd element : %.1f\n", *(*(table)+1) + 1);
	getch();
}