#include<iostream>
#include<conio.h>
#include<string>
#include<time.h>

void removeChar(char c,char orgin[],char result[]) {
	int x = 0;
	for(int i=0;i<strlen(orgin);i++)
		if (orgin[i] != c) {
			result[x] = orgin[i];
			x++;
		}
}
void swap(char &c1, char &c2) {
	c1 += c2;
	c2 = c1 - c2;
	c1 -= c2;
}
void quickSort(char *a, int l, int r)
{
	srand(time(NULL));
	char key = a[l + rand() % (r - l + 1)];
	int i = l, j = r;
	while (i <= j)
	{
		while (a[i] < key) i++;    
		while (a[j] > key) j--;     
		if (i <= j)
		{
			if (i < j)
				swap(a[i], a[j]);
			i++;
			j--;
		}
	}
	if (l < j) quickSort(a, l, j);
	if (i < r) quickSort(a, i, r);
}
void main() {
	char str[100] = { '\0' };
	char result[100] = { '\0' };
	printf("Enter string: ");
	gets_s(str);
	removeChar(' ', str, result);
	quickSort(result, 0, strlen(result) - 1);
	puts(result);
	getch();
}