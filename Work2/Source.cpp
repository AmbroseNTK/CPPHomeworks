#include<iostream>
#include<conio.h>

void main() {
	int n,x;
	float t;
	printf("Nhap n\n");
	scanf("%d", &n);
	printf("Nhap x\n");
	scanf("%d", &x);
	t = 0;
	for (int i = 1; i <= n; i++) {
		t += float(x) / i;
	}
	printf("x + x/2 + x/3 +...+ x/N = %f", t);
	getch();
}