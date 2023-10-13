#include <bits/stdc++.h>
using namespace std;
// copy constructor
class number
{
private:
    int a;

public:
    number()
    {
        a = 0;
    }
    number(int num)
    {
        a = num;
    }
    number(number &o) // this is copy constructor defined by us
    {
        cout << "The copy constructor is called-"<<endl;
        a = o.a;
    }//what if we comments copy constructor will code run without giving error
    void display();
};
void number::display(){
    cout<<"The value of a is "<<a<<endl;
}
int main()
{
number n1,n2(45),n3,n4;
n2.display();
n1.display();
n3=n1;//constructor not called
n3.display();
number n5(n2);
n5.display();
number n6=n2;
n6.display();
    return 0;
}