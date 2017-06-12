#include<iostream>
#include<string>
#include<conio.h>

int isContain(char s1[], char s2[]) {
	for (int i = 0; i < strlen(s1); i++) {
		int j = 0;
		for (j = 0; j < strlen(s2); j++) {
			if (s1[(i + j)] != s2[j])
				break;
		}
		if (j == strlen(s2))
			return 1;
	}
	return 0;
}
void main() {
	char s1[100] = { '\0' };
	char s2[100] = { '\0' };
	printf("S1: ");
	gets_s(s1);
	printf("S2 ");
	gets_s(s2);
	printf(isContain(s1, s2) == 1 ? "S2 la con S1" : "S2 khong la con S1");
	getch();
}