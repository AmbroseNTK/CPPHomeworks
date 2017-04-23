#include<iostream>
#include<conio.h>

void main() {
	printf("\t\t\t\tBANG CUU CHUONG\n\n");
	for (int i = 1; i <= 10; i++) {
		for (int j = 1; j <= 9; j++) {
			printf("%d\t", i*j);
		}
		printf("\n");
	}
	getch();
}