#include<iostream>
#include<conio.h>

void main() {
	int n, t;
	printf("Nhap n\n");
	scanf("%d", &n);
	t = 0;
	for (int i = 1; i <= n; i += 2) {
		t += i;
	}
	printf("1 + 3 + 5 + ... + n = %d\n", t);
	t = 0;
	for (int i = 1, dau = 1; i <= n; i++, dau = -dau) {
		t += dau*i;
	}
	printf("1 - 2 + 3 - 4 + ... + (-1)^(N+1)N = %d", t);
	getch();
}