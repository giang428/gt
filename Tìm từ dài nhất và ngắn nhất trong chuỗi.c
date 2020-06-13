#include<stdio.h>
#include<string.h>
int main() {
	char str1[50],dem[50];
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
		dem[i] = strlen(words1[i]);
	}
	int mx = 0, mn = 20;
	for (int i = 0; i < n1; i++) {
		if (mx < dem[i]) {
			mx = dem[i];
		}
		if (mn > dem[i]) {
			mn = dem[i];
		}
	}
	for (int i = 0; i < n1; i++) {
		if (mx == dem[i]) {
			printf("%s ", words1[i]);
			break;
		}
	}
	for (int i = 0; i < n1; i++) {
		if (mn == dem[i]) {
			printf("%s", words1[i]);
			break;
		}
	}
	return 0;
}
