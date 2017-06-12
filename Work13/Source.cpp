#include<iostream>
#include<string>
#include<conio.h>

void invertStr(char inv[]) {
	int length = strlen(inv);
	for (int i = 0; i < length / 2.0; i++)
	{
		char temp = inv[i];
		inv[i] = inv[length - 1 - i];
		inv[length - 1 - i] = temp;
	}
}
void lowerStr(char source[]) {
	for (int i = 0; i < strlen(source); i++)
		source[i] = tolower(source[i]);
}
void getFirstName(char source[], char *firstName) {
	int length = strlen(source);
	for (int i = length - 1; source[i] !=' '; i--) {
		firstName[length - i - 1] = source[i];
	}
	invertStr(firstName);
	lowerStr(firstName);
}
void makeEmail(char name[]) {
	char firstName[50] = { '\0' };
	getFirstName(name, firstName);
	char lastName[50] = { '\0' };
	int x = 0;
	for (int i = 0; i < strlen(name) - strlen(firstName) - 1; i++)
		if (name[i] != ' ') {
			lastName[x] = name[i];
			x++;
		}
	lowerStr(lastName);
	char email[100] = { '\0' };
	strcat(email, firstName);
	strcat(email, ".");
	strcat(email, lastName);
	strcat(email, "@gmail.com.vn");
	puts(email);
}
void main() {
	char name[] = "Nguyen Tuan Kiet";
	makeEmail(name);
	getch();
}