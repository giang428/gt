#include<stdio.h>

int prime(int so){
     int c;
   for (c = 2; c <= so - 1; c++)
   {
      if (so%c == 0)
     return 0;
   }
   if (c == so)
      return 1;
}
int main() {
	int n;
	scanf("%d", &n);
	if (n <= 0) {
		return 0;
	}
	int mt[50][50];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &mt[i][j]);
		}
	}

    int temp[2*n];
    int x = 0;
    for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j || i+j == n-1)
            {
                temp[x] = mt[i][j];
                x++;
            }
            
		}
	}
   /* for (x = 0; x < 2*n; x++)
    {
        printf("%d ", temp[x]);
    } */
    int temp2[2*n]; int v = 0;
    for (x = 0; x<2*n; x++){
        if (prime(temp[x]) == 1){
            temp2[v] = temp[x];
            v++;
        }
    }

    for (int t = 0; t < v; t++){
        for (int b = t + 1; b < v; b++){
            if (temp2[b] == temp2[t]){
                v--;
            }
        }
    }
 printf("%d", v);
}