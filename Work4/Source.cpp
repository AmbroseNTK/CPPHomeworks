#include<iostream>
#include<conio.h>
#include<ctime>

int isContain(int *arr, int n, int value) {
	for (int i = 0; i < n; i++) {
		if (*(arr + i) == value)
			return 1;
	}
	return 0;
}
int isPrime(int p) {
	for (int i = 2; i*i <= p; i++)
		if (p %i == 0)
			return 0;
	return 1;
}
void generateNewRandomArray(int *arr, int n) {
	int newElement;
	for (int i = 0; i < n; i++) {
		do {
			newElement= rand() % 1000 + 1;
		} while (isContain(arr, n, newElement));
		*(arr + i) = newElement;
	}
}

void printArr(int *arr, int n) {
	for (int i = 0; i < n; i++) {
		printf("%4d", *(arr + i));
	}
}
int sumPrime(int *arr, int n) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		if (isPrime(*(arr + i)))
			sum += *(arr + i);
	}
	return sum;
}
void main() {
	int *arr;
	int n = 0;
	printf("Nhap n: ");
	scanf("%d", &n);
	arr = new int[n];
	srand(time(0));
	generateNewRandomArray(arr, n);
	printArr(arr, n);
	printf("\nSum primes = %d", sumPrime(arr, n));
	getch();
	delete arr;
}