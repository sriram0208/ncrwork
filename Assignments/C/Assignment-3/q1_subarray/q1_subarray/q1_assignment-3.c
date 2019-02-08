#include<stdio.h>
void main() {
	int arr[20],n,i,j,num,sum,flag;
	printf("Enter no. of elements :");
	scanf_s("%d", &n);
	printf("Enter %d values :", n);
	for(i=0;i<n;i++)
		scanf_s("%d", &arr[i]);
	printf("Enter sum to be found 1 :");
	scanf_s("%d", &num);
	for (i = 0;i < n;i++) {
		if (arr[i] == num) {
			printf("Sum lies between indexes %d %d\n", i, i);
			break;
		}
		else {
			flag = 0;
			sum = arr[i];
			for (j = i + 1;j < n;j++) {
				sum += arr[j];
				if (sum == num) {
					flag++;
					break;
				}
			}
			if (flag != 0) {
				printf("Sum lies between indexes %d %d\n", i, j);
				break;
			}
		}
	}
	if (flag == 0)
		printf("No subarray found\n");
	getch();
}