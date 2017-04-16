#include<iostream>
#include<conio.h>

void main() {
	printf("Nhap n\n");
	int n = 0;
	scanf("%d", &n);
	if (n % 3 == 0) {
		printf("%d chia het cho 3",n);
	}
	else {
		printf("%d ko chia het cho 3", n);
	}
	getch();
}