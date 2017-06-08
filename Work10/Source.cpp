#include<iostream>
#include<conio.h>
#include<ctime>

void printArr(float arr[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%f\n", arr[i]);
	}
}
void generateArr(float arr[],int n) {
	srand(time(0));
	for (int i = 0; i < n; i++) {
		int duplicate = 0;
		do {
			arr[i] = (rand() % 50 + 10)*0.1;
			duplicate = 0;
			for (int j = 0; j < i; j++) {
				if (arr[i] == arr[j]) {
					duplicate = 1;
					break;
				}
			}
		} while (duplicate == 1);
	}
}
void input(float arr[], int n) {
	for (int i = 0; i < n; i++) {
		printf("B[%d]=", i);
		scanf("%f", &arr[i]);
	}
}
int isContain(float arr1[], float arr2[], int n, int m) {
	for (int i = 0; i < n; i++) {
		int j = 0;
		for (j = 0; j < m; j++) {
			if (arr1[(i+j)] != arr2[j])
				break;
		}
		if (j == m)
			return 1;
	}
	return 0;
}
void main() {
	float arr[1000],arr2[1000];
	int n,m;
	printf("Nhap n: ");
	scanf("%d", &n);
	generateArr(arr, n);
	printArr(arr, n);
	printf("Nhap m: ");
	scanf("%d", &m);
	input(arr2, m);
	printf(isContain(arr, arr2, n, m) == 1 ? "B la con cua A" : "B khong la con cua A");
	getch();
}