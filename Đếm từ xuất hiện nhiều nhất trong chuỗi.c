#include<stdio.h>
#include<string.h>
int main() {
	char str1[50];
	gets(str1);
	int m = strlen(str1);
	for (int i = 0; i < m; i++) {
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
	}int dem = 0, gan = 0;
	for (int i = 0; i < n1; i++) {
		int a = 0;
		for (int j = 0; j < n1; j++) {
			if (strcmp(words1[i], words1[j]) == 0) {
				a++;

			}
		}
		if (dem < a) {
			dem = a;
			gan = i;
		}
	}
	printf("%s %d", words1[gan], dem);
	return 0;
}
