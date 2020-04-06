#include <stdio.h>
#include <math.h>

int main(){
float  a,b,c;
float d;
scanf("%f%f%f", &a, &b, &c);
if (a == 0)
{
printf("NO");
return 0;
}
else
{
d = b*b - 4*a*c;
}
float xone, xtwo;
if (d < 0)
{
    printf("NO");
}
else
{
    xone = (-b + sqrt(d))/(2*a);
    xtwo = (-b - sqrt(d))/(2*a);
    printf("%.2f %.2f", xone, xtwo);
}

}

