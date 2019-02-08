#include<stdio.h>
void main() {
	int arr[10], n,temp,i,j;
	printf("Enter no. of array values :");
	scanf_s("%d", &n);
	printf("Enter %d values :", n);
	for (i = 0;i < n;i++)
		scanf_s("%d", &arr[i]);
	i = 0;
	j = n - 1;
	while (i < j) {
		if (arr[i] < 0)
			i++;
		if (arr[j] > 0)
			j--;
		if ((arr[i] >= 0 && arr[j] < 0)&&i<j) {
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;

			i++;
			j--;
		}
	}
	for (i = 0;i < n;i++)
		printf("%d ", arr[i]);
	getch();
}