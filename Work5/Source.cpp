#include<iostream>
#include<conio.h>
#include<ctime>

int isDuplicate(float *arr, int n, float value) {
	for (int i = 0; i < n; i++) {
		if (*(arr + i) == value)
			return 1;
	}
	return 0;
}
void generateNewRandomArray(float *arr, int n) {
	float newElement;
	for (int i = 0; i < n; i++) {
		do {
			newElement = (rand() % 40 + 10)*0.1;
		} while (isDuplicate(arr, n, newElement));
		*(arr + i) = newElement;
	}
}

void printArr(float *arr, int n) {
	for (int i = 0; i < n; i++) {
		printf("  %.2f", *(arr + i));
	}
}
void inputNewArr(float *arr, int n) {
	for (int i = 0; i < n; i++) {
		printf("Nhap arr[%d] = ", i);
		scanf("%f", (arr + i));
	}
}
int isContain(float arr1[], float arr2[], int n, int m) {
	for (int i = 0; i < n; i++) {
		int j = 0;
		for (j = 0; j < m; j++) {
			if (arr1[(i + j)] != arr2[j])
				break;
		}
		if (j == m)
			return 1;
	}
	return 0;
}
void main() {
	float *arr;
	int n = 0;
	float *arrB;
	int m = 0;
	printf("Nhap n: ");
	scanf("%d", &n);
	arr = new float[n];
	srand(time(0));
	generateNewRandomArray(arr, n);
	printArr(arr, n);
	printf("\nNhap m: ");
	scanf("%d", &m);
	arrB = new float[m];
	inputNewArr(arrB, m);
	printf(isContain(arr, arrB, n, m) ? "B la con A" : "B khong la con A");
	getch();
	delete arr;
	delete arrB;
}