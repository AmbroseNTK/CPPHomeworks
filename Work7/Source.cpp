#include<iostream>
#include<conio.h>
#include<ctime>

int isContain(int **arr, int r,int c, int value) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (arr[i][j] == value)
				return 1;
		}
	}
	return 0;
}
void generateNewRandomArray(int **arr, int r,int c) {
	int newElement;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			do {
				newElement = rand() % 30 + 1;
			} while (isContain(arr, r, c, newElement));
			arr[i][j]= newElement;
		}
	}
}

int sumOfBorder(int **arr, int r, int c) {
	int sum = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (i == 0 || i == r - 1)
				sum += arr[i][j];
			else {
				sum += arr[i][0] + arr[i][c - 1];
				break;
			}
		}
	}
	return sum;
}
void printMat(int **matrix, int r, int c) {
	printf("\nmatrix = [\n");
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++)
			printf("\t%d", matrix[i][j]);
		printf("\n");
	}
	printf(" ]");
}
void main() {
	int **arr;
	int r = 0;
	int c = 0;
	printf("So dong: ");
	scanf("%d", &r);
	printf("So cot: ");
	scanf("%d", &c);
	arr = new int*[r];
	for (int i = 0; i < r; i++)
		arr[i] = new int[c];

	srand(time(0));
	generateNewRandomArray(arr, r,c);
	printMat(arr, r, c);
	printf("\nSum of border = %d", sumOfBorder(arr, r, c));
	getch();
	delete arr;
}