#include<iostream>
#include<conio.h>

void inputArr(int *arr,int n) {
	for (int i = 0; i < n; i++) {
		printf("Arr[%d] = ",i);
		scanf("%d", arr + i);
	}
}

int sum(int *arr, int n) {
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += *(arr + i);
	return sum;
}

void main() {
	printf("Do dai mang Arr = ");
	int n;
	scanf("%d", &n);
	int *arr = new int[n];
	inputArr(arr, n);
	printf("Tong cua arr = %d",sum(arr, n));
	getch();
	delete arr;
}