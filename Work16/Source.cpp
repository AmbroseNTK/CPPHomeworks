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
	srand(time(NULL));  //khoi tao tham so ham rand()
	char key = a[l + rand() % (r - l + 1)];  //lay khoa la gia tri ngau nhien tu a[l] -> a[r]
											//int key = a[(l+r)/2];
	int i = l, j = r;

	while (i <= j)
	{
		while (a[i] < key) i++;       // tim phan tu ben trai ma >=key
		while (a[j] > key) j--;       // tim phan tu ben trai ma <=key
		if (i <= j)
		{
			if (i < j)
				swap(a[i], a[j]);  // doi cho 2 phan tu kieu int a[i], a[j].
			i++;
			j--;
		}
	}
	//bay gio ta co 1 mang : a[l]....a[j]..a[i]...a[r]
	if (l < j) quickSort(a, l, j);   // lam lai voi mang a[l]....a[j]
	if (i < r) quickSort(a, i, r); // lam lai voi mang a[i]....a[r]
}
void main() {
	char str[100] = { '\0' };
	char result[100] = { '\0' };
	printf("Enter string: ");
	gets_s(str);
	removeChar(' ', str, result);
}