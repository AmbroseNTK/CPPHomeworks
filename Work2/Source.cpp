#include<iostream>
#include<conio.h>

void main() {
	printf("Nhap lan luot a va b\n");
	float a, b = 0;
	scanf("%f%f", &a, &b);
	if (a == 0 && b == 0) {
		printf("Phuong trinh co vo so nghiem");
	}
	else if (a == 0 && b != 0) {
		printf("Phuong trinh vo nghiem");
	}
	else {
		printf("Phuong trinh co nghiem %f", -b / a);
	}
	getch();
}