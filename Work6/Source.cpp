#include<iostream>
#include<conio.h>

int max(int a, int b) {
	if (a > b)
		return a;
	else
		return b;
}
int min(int a, int b) {
	if (a > b)
		return b;
	else
		return a;
}
void main() {
	printf("Nhap 4 so a b c d\n");
	int a, b, c, d;
	scanf("%d%d%d%d", &a, &b, &c, &d);
	printf("So lon nhat la: %d\nSo nho nhat la: %d", max(a, max(b, max(c, d))), min(a, min(b, min(c, d))));
	getch();
}