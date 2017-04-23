#include<iostream>
#include<conio.h>

void main() {
	int n, x;
	float t;
	printf("Nhap n\n");
	scanf("%d", &n);
	printf("Nhap x\n");
	scanf("%d", &x);
	t = 0;
	int k = 1;
	for (int i = 1; i <= n + 1; i++) {
		t += float(k) / pow(x, i);
		k *= (i + 1);
	}
	printf("1/X + 2!/X^2 + ... + N!/X^N = %f", t);
	getch();
}