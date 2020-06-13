#include<stdio.h>
#include<string.h>
int main(){
	char chuoi[100];
	gets(chuoi);
	int a=strlen(chuoi),b=1;
	if(chuoi[0]==' '){
		b=0;
	}
	for(int i=0;i<a;i++){
		if(chuoi[i]==' ' && chuoi[i+1]!=' ' ){
		b++;
		}
	}
	printf("%d",b);
}
