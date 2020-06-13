#include<stdio.h>
#include<string.h>
int main() {
	char str1[50],dem[50];
	gets(str1);
	int m = strlen(str1);
	for (int i = 0; i < m; i++) {// chuyen chu hoa ve chu thuong
		if (str1[i] >= 'A' && str1[i] <= 'Z') {
			str1[i] += 32;
		}
	}
	char* words1[20];
	int n1 = 0;
	char* token = strtok(str1, " ");
	while (token != NULL)
	{
		words1[n1++] = token;
		token = strtok(NULL, " ");
	}
	for (int i = 0; i < n1; i++) {// dem va gan so lan xuat hien vao mang
		int v = 0, a = 0;
		for (int j = 0; j < i; j++) {
			if (strcmp(words1[i], words1[j]) == 0) {
				v++;
			}
		}
		if (v == 0) {
			for (int j = 0; j < n1; j++) {
				if (strcmp(words1[i], words1[j]) == 0) {
					a++;

				}
			}printf("%s %d\n", words1[i], a);
		}
	}

	return 0;
}
