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

int main(){
    int a;
    scanf("%d", &a);
    if(prime(a) == 1){
        printf("1");
    }
    else
    {
        printf("0");
    }
    
}