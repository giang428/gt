#include<iostream>
#include<algorithm>
#define MAX 100
using namespace std;
bool comp(const int a, const int b){
   return a > b;
}
void nhap(int n, int bang[MAX][6]){
    for(int i = 0; i<n; i++){
        cout<<"Nhap diem cua van dong vien thu " << i+1 <<": ";
        for(int j = 0; j<5; j++)
        cin >> bang[i][j];
    }
}
void calc(int bang[MAX][6],int bkq[MAX][7],int n){
    int mang[MAX];
    for(int z = 0; z<n; z++){
        bang[z][5] = 0; 
    }
    for(int k = 0; k<n; k++){
        for(int c = 0; c<5; c++){
        bang[k][5] += bang[k][c];
    }
}
for(int t = 0; t<n;t++){
    mang[t] = bang[t][5];
}
std::sort(mang,mang+n,greater<int>());

for(int t = 0; t<n;t++){
    bkq[t][5] = mang[t];
}

for(int i = 0; i<n;i++){
  for(int j = 0; j<n;j++){
      if(bang[j][5] == bkq[i][5]){
          bkq[i][6] = j+1;
          for(int y = 0; y<5; y++){
              bkq[i][y] = bang[j][y];
          }
      }
  }
}
}
void xuat(int bang[MAX][7],int n){
    cout << "--------------------BANG THANH TICH--------------------\n";
    cout << "DS      L1  L2  L3  L4  L5  Tong diem  Huy Chuong\n";
    for(int i = 0; i < n; i++){
          cout <<"VDV "<<bang[i][6]<<": ";
        for(int j = 0; j < 5; j++){
           printf("%*d ",3,bang[i][j]);
        }
        printf("%*d",5,bang[i][5]);
        if(i == 0) cout <<"\tHCV\n";
        else if (i == 1) cout << "\tHCB\n";
        else if (i == 2) cout <<"\tHCD\n";
        else cout << endl;
    }
}

main(){
    int a;
    int bg[MAX][6],kq[MAX][7];
    cin >>a;
    nhap(a,bg);
    calc(bg,kq,a);
    xuat(kq,a);

}