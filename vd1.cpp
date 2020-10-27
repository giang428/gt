#include <iostream>
#include <math.h>
#define MIN 0.00001
using namespace std;

long ucln (long a, long b){
	while(b != 0){
		int r = a%b;
		a = b; b = r;
	}
	return a;
}
float takedu(float a){
	float d = a - int(a);
	return d;
}
bool checkdigit(char a){
    if(((1*a) >= 48) && ((1*a) <= 57)) return true;
    return false;
}
int conv(int so[]){
    int kq=0; int dem = 0;
    int c=1;
    while(so[dem] != '\0') dem++;
    while(--dem >= 0){kq += so[dem]*c; c*=10;} 
    return kq;
}
class phanso{
	private:
		int tu;
		int mau;
	public:
		phanso(){tu = 0; mau = 0;} //init
		phanso(int t,int m){tu=t; mau=m;} //init

		void xemmh(){
			if(mau == 1) {cout<<tu<<"\n"; return;}
			if(mau < 0){
				if(tu > 0){ tu *= -1; mau *= -1;}
				else mau *= -1;
			}
			cout<<tu<<"/"<<mau<<"\n";
		}//print fraction

		void rutgon(){
			long g = ucln(tu,mau);
			tu /= int(g); mau /= int(g);
		}//simplest form

	operator float(){
		float y = float(tu)/float(mau);
		return y;
	}//fraction to float

	phanso (float a){
		int c = 1;
		do{
			a *= 10; c*=10;
		} while (takedu(a) > MIN);
		this->tu = a; this->mau = c;
		rutgon();
	}	//float to fraction

	phanso(const char *s){
	int i = 0;
	int tustr[10] = {0}; int k = 0;
	int maustr[10] = {0}; int q = 0;
	bool ctu = true, cmau = false;
		while(s[i] != '\0'){
      if(checkdigit(s[i-1]) && !checkdigit(s[i])) {ctu = false; cmau = true;}
        if(ctu && checkdigit(s[i])){
            tustr[k++] = s[i]-'0';
        }
        if(cmau && checkdigit(s[i])){
            maustr[q++] = s[i]-'0';
        }
        i++;
		}
    tustr[k] = '\0';
	maustr[q] = '\0';
  this->tu = conv(tustr);
  this->mau = conv(maustr);
	}//string to fraction

	friend phanso operator + (phanso c1, phanso c2); //adding fractions
	friend phanso operator - (phanso t1, phanso t2); //subtracting fractions
	
	phanso operator * (phanso n){
		phanso a;
		a.tu = tu * n.tu;
		a.mau = mau * n.mau;
		a.rutgon();
		return a;
	} //multiplying fractions
	phanso operator / (phanso ch){
		phanso a;
		a.tu = tu * ch.mau;
		a.mau = mau * ch.tu;
		a.rutgon();
		return a;
	} // dividing fractions
};
phanso operator + (phanso c1, phanso c2){
	phanso co;
	co.tu = c1.tu*c2.mau + c1.mau*c2.tu;
	co.mau = c1.mau * c2.mau;
	co.rutgon();
	return co;
}
phanso operator - (phanso t1, phanso t2){
	phanso tr;
	tr.tu = t1.tu*t2.mau - t1.mau*t2.tu;
	tr.mau = t1.mau * t2.mau;
	tr.rutgon();
	return tr;
}
main(){
	phanso a(12,8);
		a.rutgon();
		cout<<"12/8 = "; a.xemmh();
	phanso e = phanso(1.333333333333333);
		cout<<"12.34 = "; e.xemmh(); cout<<"\n";
	phanso f = phanso("34 phan 56");
		cout<<"34 phan 56 = "; f.xemmh();
	phanso cong = a+e;
		cout<<"Tong 2 phan so tren = "; cong.xemmh();
	phanso tru = a-e;
		cout<<"Hieu 2 phan so tren = "; tru.xemmh();
	phanso nhan = a*e;
		cout<<"Tich 2 phan so tren = "; nhan.xemmh();
	phanso chia = a/e;
		cout<<"Thuong 2 phan so tren = "; chia.xemmh();
	
}

