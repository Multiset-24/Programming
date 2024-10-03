#include <bits/stdc++.h>
using namespace std;
//constructor and its properties
class complexn{
    private:
    int a,b;
    public:
    complexn(void);//constrcutor have the same name as that of class
    void printnumber(void){
        cout<<"Your number is "<<a<<"+"<<b<<"i"<<endl;
    }
};
    complexn::complexn(void)//---->only accepts default arguments
    {
        a=0;
        b=0;
    }
int main() {
 complexn c1,c2;
c1.printnumber();
c2.printnumber();
    return 0;
}