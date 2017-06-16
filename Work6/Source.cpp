#include<iostream>
#include<conio.h>
#include<ctime>

void inputMatrix(int **matrix, int r, int c) {
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++) {
			printf("Nhap mat[%d][%d] = ", i, j);
			scanf("%d", &matrix[i][j]);
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
int sumRC(int **mat, int r, int c, int k, int ROW) {
	int sum = 0;
	if (ROW==1)
		for (int i = 0; i < c; i++)
			sum += mat[k][i];
	else
		for (int i = 0; i < r; i++)
			sum += mat[i][k];
	return sum;
}
int sumMainCross(int **matrix, int r, int c) {
	int sum = 0;
	if (r == c)
		for (int i = 0; i < r; i++)
			sum += matrix[i][i];
	else
		return NULL;
	return sum;
}
int maxCol(int **mat, int r, int c) {
	int max = sumRC(mat, r, c, 0, 0);
	int k = 0;
	for (int i = 1; i < c; i++) {
		int m = sumRC(mat, r, c, i, 0);
		if (m > max) {
			max = m;
			k = i;
		}
	}
	return k;
}
void swap(int &c1, int &c2) {
	int temp = c1;
	c1 = c2;
	c2 = temp;
}
void quickSort(int **a, int l, int r,int C)
{
	srand(time(NULL));
	int key = a[l + rand() % (r - l + 1)][C];
	int i = l, j = r;
	while (i <= j)
	{
		while (a[i][C] < key) i++;
		while (a[j][C] > key) j--;
		if (i <= j)
		{
			if (i < j)
				swap(a[i][C], a[j][C]);
			i++;
			j--;
		}
	}
	if (l < j) quickSort(a, l, j,C);
	if (i < r) quickSort(a, i, r,C);
}
void main() {
	int **matrix;
	int n, m,k;
	printf("So dong: ");
	scanf("%d", &n);
	printf("So cot: ");
	scanf("%d", &m);

	matrix = new int*[n];
	for (int i = 0; i < n; i++)
		matrix[i] = new int[m];

	inputMatrix(matrix, n, m);
	printMat(matrix, n, m);

	printf("\nSo k: ");
	scanf("%d", &k);
	printf("sum(matrix[%d][])=%d\n",k, sumRC(matrix, n, m, k, 1));
	printf("sum(matrix[][%d])=%d\n",k, sumRC(matrix, n, m, k, 0));
	printf("sum of main cross = %d\n", sumMainCross(matrix, n, m));
	printf("max(matrix[][k]) ; k=%d\n", maxCol(matrix, n, m));
	printf("sort(matrix[][%d])\n", k);
	quickSort(matrix, 0, n-1,k);
	printMat(matrix, n, m);
	getch();
}
