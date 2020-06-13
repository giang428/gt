#include <stdio.h>
#include<string.h>
typedef struct {
	int id;
	char msv[100];
	char name[100];
} Object;

int const size = sizeof(Object);
FILE* f;
char dmp[100];
Object arr[50];
void getData(Object* obj)
{
	gets(obj->msv);
	gets(obj->name);
	
}
int nextID()
{
	int id;
	f = fopen("B19DCCN143.bin", "rb");

	if (f == NULL)
		return 1;

	Object obj;
	if (fread(&obj, size, 1, f))
	{
		fseek(f, -size, SEEK_END);
		fread(&obj, size, 1, f);
		id = obj.id;
	}
	else
		return 1;

	fclose(f);
	return id;
}

void writeData(Object* obj, int id)
{
	f = fopen("B19DCCN143.bin", "ab");
	obj->id = id;
	fwrite(obj, size, 1, f);
	fclose(f);
}

void updateData()
{
	f = fopen("B19DCCN143.bin", "rb+");
	char ma[11];
	Object a, b;
	gets(ma);
	getData(&a);

	while (fread(&b, size, 1, f))
	{
		if (strcmp(ma,b.msv)==0)
		{
			a.id = b.id;
			fseek(f, -size, SEEK_CUR);
			fwrite(&a, size, 1, f);
			break;
		}
	}
	puts(a.msv);
	printf("\n");

	fclose(f);
}

int readData()
{
	f = fopen("B19DCCN143.bin", "rb");
	Object obj;
	int i;
	for (i = 0; fread(&obj, size, 1, f); i++)
		arr[i] = obj;
	fclose(f);
	return i;
}

int main()
{
	int mode;
	scanf("%d", &mode);

	switch (mode)
	{
	case 1:
	{
		int n;
		scanf("%d", &n);

		int id = nextID();
		gets(dmp);
		for (int i = 1; i <= n; i++)
		{
			Object obj;
			getData(&obj);
			writeData(&obj, id++);
		}
		printf("%d", n);
		break;
	}
	case 2:
		gets(dmp);
		updateData();
		break;
	case 3:
	{
		int s = readData();
		char chuoi[10];
		gets(dmp);
		gets(chuoi);
		for (int i = 0; i < s; i++) {
			if(strstr(arr[i].msv,chuoi))
			printf("%d %s %s\n", arr[i].id, arr[i].name, arr[i].msv);
		}
		break;
	}
	default:
		break;
	}

	return 0;
}
