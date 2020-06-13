#include <stdio.h>

typedef struct {
	int id;
	char name[100];
	float sbj_a, sbj_b, sbj_c;
} Object;

int const size = sizeof(Object);
FILE* f;
char dmp[100];
Object arr[50];

void swap(Object* a, Object* b)
{
	Object tmp = *a;
	*a = *b;
	*b = tmp;
}

void bubble_sort(Object* arr, int size)
{
	int should_stop = 1;
	do
	{
		should_stop = 1;
		for (int i = 0; i < size - 1; i++)
		{
			float sum = arr[i].sbj_a + arr[i].sbj_b + arr[i].sbj_c;
			float sumn = arr[i + 1].sbj_a + arr[i + 1].sbj_b + arr[i + 1].sbj_c;
			if (sum > sumn)
			{
				swap(&arr[i], &arr[i + 1]);
				should_stop = 0;
			}
		}
	} while (!should_stop);
}

void getData(Object* obj)
{
	gets(dmp);
	gets(obj->name);
	scanf("%f %f %f", &(obj->sbj_a), &(obj->sbj_b), &(obj->sbj_c));
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

	Object a, b;
	scanf("%d", &a.id);
	getData(&a);

	while (fread(&b, size, 1, f))
	{
		if (a.id == b.id)
		{
			fseek(f, -size, SEEK_CUR);
			fwrite(&a, size, 1, f);
			break;
		}
	}
	printf("%d\n", a.id);

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
		updateData();
		break;
	case 3:
	{
		int s = readData();
		bubble_sort(arr, s);
		for(int i = 0; i < s; i++)
			printf("%d %s %.1f %.1f %.1f\n", arr[i].id, arr[i].name, arr[i].sbj_a, arr[i].sbj_b, arr[i].sbj_c);
		break;
	}
	default:
		break;
	}

	return 0;
}
