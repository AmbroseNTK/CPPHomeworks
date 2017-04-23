#include<iostream>
#include<conio.h>

void main() {
	int n, t, i;
	printf("Nhap n\n");
	scanf("%d", &n);
	for (i = 1, t = 1; i < n; i++, t *= i);
	printf("%d! = %d",n, t);
	getch();
}