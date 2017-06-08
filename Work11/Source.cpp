#include <iostream>
#include <conio.h>

void main() {
	int n = 0;
	int sum = 0;
	while (n < 1000) {
		printf("Nhap n: \n");
		scanf("%d", &n);
	}
	while (n / 10.0 > 0) {
		sum += n - int(n / 10.0) * 10;
		n /= 10.0;
	}
	printf("Ket qua: %d", sum);
	getch();
}
