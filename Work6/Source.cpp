#include<iostream>
#include<conio.h>

void main() {
	for (int i = int('A'); i <= int('Z'); i++)
		printf("%c ", i);
	printf("\n");
	for (int i = int('Z'); i >= int('A'); i--)
		printf("%c ", i);
	printf("\n");
	for (int i = int('a'); i <= int('z'); i++)
		printf("%c ", i);
	printf("\n");
	for (int i = int('z'); i >= int('a'); i--)
		printf("%c ", i);
	printf("\n");
	getch();
}