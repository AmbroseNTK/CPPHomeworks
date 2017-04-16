#include<iostream>
#include<conio.h>

void main() {
	printf("Nhap a b c\n");
	float a, b, c, delta;
	scanf("%f%f%f", &a, &b, &c);
	if (a != 0) {
		delta = pow(b, 2) - 4 * a*c;
		if (delta < 0) {
			printf("Phuong trinh vo nghiem");
		}
		else if (delta == 0) {
			printf("Phuong trinh co nghiem x=%f", -1 * b / (2 * a));
		}
		else
		{
			printf("Phuong trinh co nghiem x1=%f ; x2=%f", (-1 * b + pow(delta, 0.5)) / (2 * a), ((-1 * b - pow(delta, 0.5) )/ (2 * a)));
		}
	}
	else {
		printf("%.2fx^2+%.2fx+%.2f=0 khong la phuong trinh bac 2", a, b, c);
	}
	getch();
}