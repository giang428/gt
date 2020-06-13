#include<stdio.h>
#include<string.h>
int main() {
	char str1[50];
	gets(str1);
	int m = strlen(str1);
	char* words1[20];
	int n1 = 0;
	char* token = strtok(str1, " ");
	while (token != NULL)
	{
		words1[n1++] = token;
		token = strtok(NULL, " ");
	}
	for (int i = 0; i < n1; i++) {
		int j = 0, n = 0;;

		while (words1[i][j] != '\0') {
			if (words1[i][j] >= 'a' && words1[i][j] <= 'z') {
				n++;
			}j++;
		}
		if (n == 0) {
			printf("%s ", words1[i]);
		}
	}
	return 0;
}
