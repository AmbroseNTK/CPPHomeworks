#include<iostream>
#include<conio.h>

void linearSolver(int *a, int *b) {
	if (*a == 0)
		printf("No solution");
	else
		if (b == 0)
			printf("Inf");
		else
			printf("Solution x = %.2f", -1.0 * (*b) / (*a));
}

void main() {
	printf("Enter a and b: \n");
	int *a = new int;
	int *b = new int;
	scanf("%d", a);
	scanf("%d", b);
	linearSolver(a, b);
	getch();
	delete a;
	delete b;
}