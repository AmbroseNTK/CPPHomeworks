#include<iostream>
#include<conio.h>
#include<ctime>

void input(int A[], int n) {
	for (int i = 0; i < n; i++) {
		printf("\nA[%d]= ", i);
		scanf("%d", &A[i]);
	}
}
void output(int A[], int n) {
	for (int i = 0; i < n; i++)
		printf("%4d", A[i]);
}
void Rando(int A[], int n) {
	srand(time(0));
	for (int i = 0; i < n; i++)
	{
		A[i] = rand() %50;
	}
}
int coutNeg(int A[], int n) {
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (A[i] < 0)
			count++;
	}
	return count;
}
void main() {
	int A[100];
	int n;
	scanf("%d", &n);
	Rando(A, n);
	output(A, n);
	printf("\n%d",coutNeg(A, n));
	
	getch();
}