#include<stdio.h>
#include<math.h>
void main() {
	int a, b,i,j,flag;
	printf("Enter range :");
	scanf_s("%d%d", &a, &b);
	for (i = a;i <= b;i++) {
		flag = 0;
		for (j = 2;j <= sqrt(i);j++) {
			if (i%j == 0){
				flag++;
				break;
			}
		}
		if (flag == 0 && i!=1)
			printf("%d ", i);
	}
	getch();
}