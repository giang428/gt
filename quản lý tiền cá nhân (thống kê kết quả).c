#include <stdio.h>
#include<string.h>
typedef struct {
	int id;
	int khoanmuc;
	char name[100];
	int sotien;
} Object;

int const size = sizeof(Object);
FILE* f;
char dmp[100];
Object arr[50];
void getData(Object* obj)
{
	scanf("%d", &obj->khoanmuc);
	gets(dmp);
	gets(obj->name);
	scanf("%d", &obj->sotien);
	
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
	int c;
	Object a, b;
	scanf("%d", &c);
	getData(&a);

	while (fread(&b, size, 1, f))
	{
		if (c==b.id)
		{
			a.id = b.id;
			fseek(f, -size, SEEK_CUR);
			fwrite(&a, size, 1, f);
			break;
		}
	}
	puts(a.name);
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
		int n,a=0,b=0;
		scanf("%d", &n);
         
		int id = nextID();
		for (int i = 1; i <= n; i++)
		{
			Object obj;
			getData(&obj);
			writeData(&obj, id++);
			if (obj.khoanmuc == 1)a++;
			if (obj.khoanmuc == 2)b++;
		}
		printf("%d %d", a, b);
		
		break;
	}
	case 2:
		gets(dmp);
		updateData();
		break;
	case 3:
	{
		int s = readData(),b=0,c=0;
		for (int i = 0; i < s; i++) {
			if (arr[i].khoanmuc == 1) b += arr[i].sotien;
			if(arr[i].khoanmuc == 2)c += arr[i].sotien;
			
		}printf("%d %d %d",b,c,(b>c)?b-c:0);
		break;
	}
	default:
		break;
	}

	return 0;
}
