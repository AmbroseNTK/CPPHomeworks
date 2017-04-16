#include<iostream>
#include<conio.h>

void main() {
	printf("Nhap ngay thu n\n");
	int d;
	scanf("%d", &d);
	switch (d)
	{
	case 1:
		printf("Sunday");
		break;
	case 2:
		printf("Monday");
		break;
	case 3:
		printf("Tuesday");
		break;
	case 4:
		printf("Wednesday");
		break;
	case 5:
		printf("Thursday");
		break;
	case 6:
		printf("Friday");
		break;
	case 7:
		printf("Saturday");
		break;
	default:
		printf("Nhap sai so ngay!");
		break;
	}
	getch();
}