#include<iostream>
#include<conio.h>

void main() {
	int n, m;
	printf("Nhap n\n");
	scanf("%d", &n);
	printf("Nhap m\n");
	scanf("%d", &m);
	long r = m;
	for (int i = 1; i < n; i++) {
		r *= m;
	}
	printf("%d^%d = %d",m,n,r);
	getch();
}