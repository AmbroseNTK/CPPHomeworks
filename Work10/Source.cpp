#include<iostream>
#include<conio.h>

void main() {
	int n, t;
	printf("Nhap n\n");
	scanf("%d", &n);
	int k = n * 2 - 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j<int(k / 2.0) - i; j++)
			printf("  ");
		for (int j = 0; j < (i + 1) * 2 - 1; j++) {
			printf("* ");
		}
		printf("\n");
	}
	printf("\n\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j<int(k / 2.0) - i; j++)
			printf("  ");
		for (int j = 0; j < (i + 1) * 2 - 1; j++) {
			if (i == 0 || i == n - 1 || j == 0 || j == (i + 1) * 2-2) {
				printf("* ");
			}
			else
				printf("  ");
		}
		printf("\n");
	}
	getch();
}