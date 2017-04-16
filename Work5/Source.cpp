#include<iostream>
#include<conio.h>

void main() {
	printf("Nhap so km\n");
	int km, price = 0;
	scanf("%d", &km);
	if (km == 1)
		price = 16000;
	else if (km < 31)
	{
		price = 16000 + 2000 * 5 * (km - 1);
	}
	else
	{
		price = 16000 + 30 * 5 * 2000 + 14000 * (km - 31);
	}
	printf("Cuoc taxi la %d", price);
	getch();
}