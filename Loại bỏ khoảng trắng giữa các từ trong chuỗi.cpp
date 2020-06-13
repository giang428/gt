#include<stdio.h>
#include<string.h>
int main(){
	char chuoi[100];
	gets(chuoi);
	int a=strlen(chuoi);
	for(int i=0;i<a;i++){
		if(chuoi[i]!=' '){
			printf("%c",chuoi[i]);
		}
	}
}
