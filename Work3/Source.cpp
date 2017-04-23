#include<iostream>
#include<conio.h>

void main() {
	int n;
	float t;
	printf("Nhap n\n");
	scanf("%d", &n);
	t = 0;
	for (int i = 1, dau = 1; i <= n; i++, dau = -dau) {
		t += dau*(1.0 / i);
	}
	printf("1 - 1/2 + 1/3 - 1/4 +...1/N = %f\n", t);
	t = 0;
	for (int i = 2; i <= n - 1; i += 2) {
		t += i;
	}
	printf("2 + 4 + 6 + ... + N-1 = %.0f\n", t);
	for (int i = 1; i <= n; i++) {
		t += pow(i,2);
	}
	printf("1 + 2^2 + 3^2 + ... + N^2 = %.0f\n", t);
	getch();
}