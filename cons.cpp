#include<iostream>
#define pi 3.14159
#include<math.h>
using namespace std;

class circle
{
private:
	float radius;
	float cenx, centy;
public:
void inp(float r){
	cin >> this->radius;
}
float outr(){
	return this->radius;
}
void inp(float a, float b){
	cin >> this->cenx >> this->centy;
}
float outc(bool x){
	return x ? this->cenx:this->centy;
}
float peri(){
	return 2*pi*this->radius;
}
float area(){
	return pi*this->radius*this->radius;
}
};

main(){
	float a,b,c;
	int cs;
	circle tron1,tron2;
	cout << "Nhap toa do tam hinh tron 1: ";
	tron1.inp(a,b);
	cout << "Nhap toa do tam hinh tron 2: ";
	tron2.inp(a,b);
	cout << "Nhap ban kinh hinh 1: ";
	tron1.inp(c);
	cout << "Nhap ban kinh hinh 2: ";
	tron2.inp(c);
	do{
	cout <<"Nhap lua chon: \n";
	cout <<"1. Hien thi thong tin\n"<<"2. Tinh chu vi\n"<<"3. Tinh dien tich\n"<<"4. Vi tri tuong doi\n";
	cin >> cs;
	if((cs>4)||(cs<1)){ cout << "Lua chon ko chinh xac. Xin moi ban nhap lai\n";}
	else break;
	}while(1);
	
	switch (cs)
	{
	case 1:
	cout << "Hinh tron 1: ";
	cout << "\tr = "<< tron1.outr(); 
	cout << "\tO("<<tron1.outc(1)<<","<<tron1.outc(0)<<")"; cout<<endl;
	
	cout << "Hinh tron 2: ";
	cout << "\tr = "<< tron2.outr(); 
	cout << "\tO("<<tron2.outc(1)<<","<<tron2.outc(0)<<")"; cout<<endl;
	break;
	
	case 2:
		int cs2; 
		do{
		cout<<"Chon hinh can tinh: \n";
		cout<<"1. Hinh 1 \t 2. Hinh 2 \t 3. Ca hai\n";
		cin >> cs2;
		if((cs2>3)||(cs2<1)){ cout << "Lua chon ko chinh xac. Xin moi ban nhap lai\n";}
		else break;
		}while(1);
		switch (cs2)
		{
		case 1:
			cout << "\nChu vi hinh 1= " << tron1.peri();
			break;
		
		case 2:
			cout << "\nChu vi hinh 2= " << tron2.peri();
			break;
		default:
			cout << "\nChu vi hinh 1= " << tron1.peri();
			cout << "\nChu vi hinh 2= " << tron2.peri();
			break;
		break;	
		}
	break;

	case 3:
		int cs3;
		do{
		cout<<"Chon hinh can tinh: \n";
		cout<<"1. Hinh 1 \t 2. Hinh 2 \t 3. Ca hai\n";
		cin>>cs3;
		if((cs3>3)||(cs3<1)){ cout << "Lua chon ko chinh xac. Xin moi ban nhap lai\n";}
		else break;
		}while(1);

		switch (cs3)
		{
		case 1:
			cout << "\nDien tich hinh 1= " << tron1.area();
			break;
		
		case 2:
			cout << "\nDien tich hinh 2= " << tron2.area();
			break;
		default:
			cout << "\nDien tich hinh 1= " << tron1.area();
			cout << "\nDien tich hinh 2= " << tron2.area();
			break;
		break;	
		}
	break;

	case 4:
		double sumrad,absrad; double sum;
		sumrad = tron1.outr() + tron2.outr();
		absrad = abs(tron1.outr() - tron2.outr());
		sum = sqrt(pow((tron1.outc(1) - tron2.outc(1)),2) + pow((tron1.outc(0) - tron2.outc(0)),2));
		if(sum == sumrad){ cout<<"Hai hinh tron tiep xuc ngoai";}
		else if(sum > sumrad){ cout<<"Hai hinh tron khong cat nhau";}
		else if ((sum < sumrad)&&(sum > absrad)){cout<<"Hai hinh tron cat nhau";}
		else if(sum == absrad){ cout<<"Hai hinh tron tiep xuc trong";}
		else if(sum == 0){ cout<<"Hai hinh tron dong tam";}
		else{
			if(sum < tron1.outr()) cout <<"Hinh tron 2 nam trong hinh tron 1";
			else cout<<"Hinh tron 1 nam trong hinh tron 2";
		}
		break;	
	}
	//cout << "Hinh tron: ";
	//cout << "\nr = "; tron.outr(); 
	//cout << "\nO"; tron.outc();
	//cout << "\nChu vi = " << tron.peri();
	//cout << "\nDien tich = " << tron.area();



}