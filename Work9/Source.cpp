#include<iostream>
#include<conio.h>

void main() {
	int n;
	printf("Nhap n\n");
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("* ");
		}
		printf("\n");
	}
	printf("\n\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == 0 || i == n - 1 || j == 0 || j == n - 1)
				printf("* ");
			else
				printf("  ");
		}
		printf("\n");
	}
	printf("\n\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			printf("* ");
		}
		printf("\n");
	}
	printf("\n\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (i == 0 || i == n - 1 || j == 0 || j == i - 1)
				printf("* ");
			else
				printf("  ");
		}
		printf("\n");
	}
	getch();
}