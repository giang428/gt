#include <stdio.h>
#include <math.h>
int ar[50][50];
int a,b = 0;
int main(){
    scanf("%d", &a);
    b = a;
    for(int i = 0; i<a; i++){
        for (int j = 0; j<a; j++)
        {
        if (i == j){
            ar[i][j] = 1;
        }
        else
        {
            for(int k = a; k > 1; k--){
            if((i-j < k)&&(i-j > -k)){
                ar[i][j] = k;
            }
            }
        }
        
            
    }
        
    }
    for(int i = 0; i<a; i++){
        for (int j = 0; j<a; j++)
        {
           printf("%d ", ar[i][j]);
            }
            printf("\n");
        }
}
