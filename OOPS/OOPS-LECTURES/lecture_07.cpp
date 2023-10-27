#include <bits/stdc++.h>
using namespace std;
//friend function
class complexn{
    int a,b;
    public:
    void setNumber(int n1,int n2){
        a=n1;
        b=n2;
    }
    void printnumber(){
        cout<<"your nummber is "<<a<<" + "<<b<<"i"<<endl;
    }
friend class sumC;//can be declared anywhere in the class
};
class sumC{
    public:
complexn sumcomplex(complexn o1,complexn o2){
    complexn o3;
     o3.setNumber(o1.a+o2.a,o1.b+o2.b);
     return o3;
}
};
int main() {
  complexn c1,c2,c4;
  c1.setNumber(1,2);
  c2.setNumber(3,4);
  c1.printnumber();
  c2.printnumber();
  sumC c3;
  c4=(c3.sumcomplex(c1,c2));
  c4.printnumber();
    return 0;
}