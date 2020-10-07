#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<stack>
#include <sstream>

using namespace std;
int num;
class nhiphan{
private:
    long n;
    char so[1000];
public:
    nhiphan(){}
    void doctep(long &n){
    //vector <char> s;
        fstream fd;
        fd.open("d:\\sonhiphan.txt", ios::in);
            fd >> this->n;
            fd.close();

   }
    char *doinhiphan(long n){
        stack <int> s;
        int i = 0;
        while(n>0){
            s.push(n%2);
            n = n/2;
        }
        while(!s.empty()){
            this->so[i] = s.top();
            s.pop();
            i++;
        }
        this->so[i+1] = '\0';
    return this->so;
    }

};

main(){
long snp;
nhiphan e;
e.doctep(snp);
e.doinhiphan(snp);

}
