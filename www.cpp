#include<iostream>

using namespace std;

bool checkdigit(char a){
	if(((1*a) >= 48)&&((1*a) <= 57)) return true;
	return false;
} //check if a char is number

int convrt(int so[]){
	int kq = 0; int dem = 0;
	int c = 1;
	while(so[dem] != '\0') dem++;
	while(--dem >= 0){
		kq += so[dem]*c;
		c*=10;
	}
	return kq;
} //convert an array_int to int

char* int2string(int a){
	char *s = new char (10);
	char *temp = new char (10);
	if(a == 0){s[0] = '0'; s[1] = '\0'; return s;}
	int i = 0;
	while(a){
		temp[i++] = a%10 + '0';
		a/=10;
	}
	int j = 0;
	while(i--){
		s[j++] = temp[i]; 
	}
	s[j] = '\0';
	return s;
}
class giophut{
	private:
		int gio;
		int phut;
		
	public:
		giophut(){gio = 0; phut = 0;} //ktao
		giophut(int g, int p){
		gio = g;
		phut = p;
		}//ktao
		void nhapbp(){
			cin	>> gio;
			cin >> phut;	
		} //nhập vào bàn phím
		void xemmh(){
			cout <<	gio <<"h"<<phut<<"m\n";
		} //xuất ra màn hình
		void rutgon(){
			gio += phut/60;
			phut = phut%60;
		}//rút gọn
		giophut(int a){
			this->gio = 0;this->phut = a;
			rutgon();
		} //kiểu int sang giophut
		giophut operator + (giophut c){
			giophut k;
			k.gio = gio + c.gio;
			k.phut = phut + c.phut;
			k.rutgon();
			return k;
		}
		giophut operator - (giophut d){
			giophut l;
			l.gio = gio - d.gio;
			l.phut = phut - d.phut;
			while(l.phut<0){
				l.phut += 60;
				l.gio--;
			}
			l.rutgon();
			return l;
		}
		friend giophut operator *(giophut a, int d);
		friend giophut operator /(giophut a, int d);

	operator char*(){
		rutgon();
		const char *hour = " gio ";
		const char *minute = " phut ";
		char *s,*g,*p;
			s = new char(50);
			g = int2string(this->gio);
			p = int2string(this->phut);
			int t = 0; 
			for(int i = 0; g[i] != '\0'; i++) s[t++] = g[i];

			for(int m = 0; hour[m] != '\0'; m++) s[t++] = hour[m];

			for(int i = 0; p[i] != '\0'; i++) s[t++] = p[i];
				
			for(int m = 0; minute[m] != '\0'; m++) s[t++] = minute[m];

		s[t] = '\0';
	return s;
	}	// giophut sang char*

	giophut(const char *s){
		int hr[10] = {0}; int i = 0;
		int mn[10] = {0}; int j = 0;
		bool ishr = true, ismn = false;
		int a = 0;
		while(s[a] != '\0'){
			if(checkdigit(s[a-1]) && !checkdigit(s[a])){ishr = false; ismn = true;}
			if(checkdigit(s[a]) && ishr){
				hr[i++] = s[a] - '0';
			}
			if(checkdigit(s[a]) && ismn ){
				mn[j++] = s[a] - '0';
			}
			a++;
		}
			hr[i] = '\0'; mn[j] = '\0';
		this->gio = convrt(hr); 
		this->phut = convrt(mn);
	} //char sang giophut
};
giophut operator *(giophut a, int d){
	giophut q;
	q.gio = d*a.gio;
	q.phut = d*a.phut;
	q.rutgon();
	return q;
}
giophut operator / (giophut a, int d){
	giophut q;
	q.phut=a.gio*60+a.phut;
	q.phut/=d;
	q.rutgon();
	return q;
}
main(){
	giophut hm,s;
	hm.nhapbp();
	hm.rutgon();
	hm.xemmh();
	
	giophut hm2; hm2 = giophut(375);
	hm2.xemmh();cout<<"\n";
	
	giophut hmt; 
	hmt = hm+hm2;
	hmt.xemmh();cout<<"\n";
	
	giophut hm3 = hm/3;
	hm3.xemmh();

	giophut e = giophut("6h38p");
	e.xemmh();

	char* gp = giophut(14,68);
	cout << gp;
}
