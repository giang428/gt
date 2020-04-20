#include<stdio.h>
int main() {
	int n,m;
	scanf("%d %d", &n,&m);
	if (m <= 0 || n <= 0) {
		return 0;
	}
	int mt1[50][50],mtt[50][50];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &mt1[i][j]);
		}
	}
	int z = 0;
for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j)
			{
				for (int k = 0; k < m; k++){
					mtt[i][j] += mt1[i][k]*mt1[i][k];
				}
			}
			else
			{
				for (int k = 0; k < m; k++)
				{
					mtt[i][j] += mt1[i][k]*mt1[j][k];
					
				}
				
			}
			
			
		}
	
}
for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", mtt[i][j]);
		}
		printf("\n");
}
}