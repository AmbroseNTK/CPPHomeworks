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
	for (int i = length - 1; source[i] != ' '; i--) {
		firstName[length - i - 1] = source[i];
	}
	invertStr(firstName);
	lowerStr(firstName);
}
void makeEmail(char name[],char id[]) {
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
	strcat(email, id+3);
	strcat(email, "@sinhvien.hoasen.edu.vn");
	puts(email);
}
void main() {
	char name[100] = { '\0' };
	char id[10] = { '\0' };
	printf("Enter your name: ");
	gets_s(name);
	printf("Enter your student ID: ");
	gets_s(id);
	makeEmail(name, id);
	getch();
}