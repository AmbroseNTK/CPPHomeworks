#include<iostream>
#include<conio.h>

void main() {
	printf("Nhap so kW dien\n");
	int n, factor;
	scanf("%d", &n);
	if (n <= 100)
		factor = 1000;
	else if (n <= 150)
		factor = 1200;
	else if (n <= 200)
		factor = 1600;
	else
		factor = 2000;
	printf("Tong gia tien la: %d", n*factor);
	getch();
}