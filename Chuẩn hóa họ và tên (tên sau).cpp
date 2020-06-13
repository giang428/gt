#include<stdio.h>
#include<string.h>
int main(){
	char chuoi[100],gan[100];
	gets(chuoi);
	int x=strlen(chuoi),a;
	for(int i=0;i<x;i++){
		if(chuoi[i]==' '&&chuoi[i-1]!=' '){
			a=i;
		}
	}
	for(int i=0;i<a;i++){
		if((chuoi[i]==' '&&chuoi[i-1]!=' ') || chuoi[i]!=' ' || (chuoi[i]==' '&&chuoi[i+1]!=' ')){
			if((chuoi[i-1]==' '&&chuoi[i]!=' ' )|| i==0){
			if(chuoi[i]>='a'&&chuoi[i]<='z'){
				chuoi[i]-=32;
			}
			}else{
				if(chuoi[i]>='A'&&chuoi[i]<='Z'){
					chuoi[i]+=32;
				}
			}
			
			printf("%c",chuoi[i]);
		}
	}printf(", ");
	int i=0;	 
	while(a<x){
		if(chuoi[a]!=' '){
			gan[i]=chuoi[a];
			i++;}
			a++;
	}
	strupr(gan);
	printf("%s",gan);
}
