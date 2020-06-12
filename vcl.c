#include<stdio.h>
#include<math.h>
int mx(int a, int b){
    if(a>b) return a;
    else return b;
}
int mn(int a, int b){
    if(a>b) return b;
    else return a;
}
int main(){
    int b, a[50];
    scanf("%d", &b);
    for (int i = 0; i<b; i++){
        scanf("%d", &a[i]);
    }
int tmX, tmY, min = 10000;
    for(int piv = 0; piv < b; piv++){
        for(int run = piv + 1; run < b; run++){
           if(abs(a[piv]-a[run]) < min){ min = abs(a[piv]-a[run]);
           tmX = mn(a[piv],a[run]); tmY = mx(a[piv],a[run]);}
        }
    }
    printf("%d %d %d", min, tmX, tmY);
}