#include<bits/stdc++.h>
using namespace std;
//protected visiblity
class Base{
    protected:
        int a; 
    private:
        int b;

};

class Derived: protected Base{
   public:
      void geta(){
        cout<<"Enter the value of a ";
        cin>>a;
        cout<<a<<endl;
      }
};

int main(){
    Base b;
    Derived d;
    // cout<<d.a; // Will not work since a is protected in both base as well as derived class
    d.geta();
    return 0;
}
