#include <bits/stdc++.h>
using namespace std;
//ambiguity in inheritence
class Base1{
    public:
        void greet(){
            cout<<"How are you?"<<endl;
        }
};

class Base2{
    public:
        void greet()
        {
            cout << "Kaise ho?" << endl;
        }
};

//ambiguity-01
class Derived : public Base1, public Base2{
   int a;
   public:
    void greet(){
        Base2 :: greet();
    }
};
int main() {
 
    return 0;
}