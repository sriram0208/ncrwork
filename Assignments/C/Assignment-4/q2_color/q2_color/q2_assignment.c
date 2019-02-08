#include<stdio.h>
void main() {
	char *color[6] = { "red", "green", "blue", "white", "black", "yellow"};
	printf("color gives base addres of given array of char pointers :%u\n", color);
	printf("(color+2) gives address of 3rd element of array of char pointers :%u\n",(color + 2));
	printf("*color gives the 1st string :%s\n", *color);
	printf("*(color + 2) gives 3rd string :%s\n",*(color + 2));
	printf("color[5]  and *(color + 5) gives value(string) at 5th index of the array :%s %s",color[5],*(color + 5));
	getch();
}