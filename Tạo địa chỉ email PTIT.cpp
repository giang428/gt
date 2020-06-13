#include<stdio.h>
#include<string.h>
int main(){
	char chuoi[100],chuoi1[100];
	gets(chuoi);
	strlwr(chuoi);
	int a=strlen(chuoi),b=0,c;
	for(int i=0;i<a;i++){
		if(chuoi[0]!=' ' && i==0){
			chuoi1[0]=chuoi[0];
			b++;
		}else{
		if(chuoi[i]==' '&&chuoi[i+1]!=' '){
			chuoi1[b]=chuoi[i+1];
			b++;
			c=i+1;
		}}
	}
	for(int i=c;i<a;i++){
	printf("%c",chuoi[i]);
	}
	for(int i=0;i<b-1;i++){
	printf("%c",chuoi1[i]);
	}
	printf("@ptit.edu.vn");
}
