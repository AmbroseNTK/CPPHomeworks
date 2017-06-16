#include<iostream>
#include<conio.h>

void inputArr(int *arr, int n) {
	for (int i = 0; i < n; i++) {
		do {
			printf("Arr[%d] = ", i);
			scanf("%d", arr + i);
		} while ((*(arr + i) > 100) || (*(arr + i) < -100));
	}
}

void process(int *arr, int n) {
	int x1, x2;
	int max = 0;
	for (int i = 1; i < n; i++) {
		int sum = abs(*(arr + i)) + abs(*(arr + i - 1));
		if (sum > max) {
			x1 = i - 1;
			x2 = i;
			max = sum;
		}
	}
	printf("Result (x1,x2) = (%d,%d)", x1, x2);
}

void main() {
	printf("Do dai mang Arr = ");
	int n;
	scanf("%d", &n);
	int *arr = new int[n];
	inputArr(arr, n);
	process(arr, n);
	getch();
	delete arr;
}