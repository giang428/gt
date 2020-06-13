#include <stdio.h>
#include <string.h>

void swap(char** a, char** b)
{
	char* tmp = *a;
	*a = *b;
	*b = tmp;
}

int main()
{
	char str1[50], str2[50];
	gets(str1);
	gets(str2);

	//Spliting 1
	char* words1[20];
	int n1 = 0;
	char* token = strtok(str1, " ");
	while (token != NULL)
	{
		words1[n1++] = token;
		token = strtok(NULL, " ");
	}

	//Spliting 2
	char* words2[20];
	int n2 = 0;
	token = strtok(str2, " ");
	while (token != NULL)
	{
		words2[n2++] = token;
		token = strtok(NULL, " ");
	}

	//Filtering
	char* str[20];
	int count = 0;
	for (int i = 0; i < n1; i++)
	{
		int tag = 0;
		for (int j = 0; j < n2; j++)
		{
			if (strcmp(words1[i], words2[j]) == 0)
			{
				tag = 1;
				break;
			}
		}

		for (int j = 0; j < count; j++)
		{
			if (strcmp(str[j], words1[i]) == 0)
			{
				tag = 1;
				break;
			}
		}

		if (!tag)
			str[count++] = words1[i];
	}

	//Sorting
	for (int i = 0; i < count - 1; i++)
		for (int j = i + 1; j < count; j++)
			if (strcmp(str[i], str[j]) > 0)
				swap(&str[i], &str[j]);

	//Printing
	for (int i = 0; i < count; i++)
		printf("%s ", str[i]);
}