#include<iostream>
#include<conio.h>
#include<ctime>

int isContain(int **arr, int r, int c, int value) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (arr[i][j] == value)
				return 1;
		}
	}
	return 0;
}
void generateNewRandomArray(int **arr, int r, int c) {
	int newElement;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			do {
				newElement = rand() % 30 + 1;
			} while (isContain(arr, r, c, newElement));
			arr[i][j] = newElement;
		}
	}
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
int **invertMatrix(int **arr, int r, int c) {
	int **iMat = new int*[c];
	for (int i = 0; i < c; i++) {
		iMat[i] = new int[r];
	}
	for (int i = 0; i < c; i++)
		for (int j = 0; j < r; j++)
			iMat[i][j] = arr[j][i];
	return iMat;
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
	generateNewRandomArray(arr, r, c);
	printMat(arr, r, c);
	printf("\nInvert matrix = \n");
	
	printMat(invertMatrix(arr, r, c), c, r);
	getch();
	delete arr;
}