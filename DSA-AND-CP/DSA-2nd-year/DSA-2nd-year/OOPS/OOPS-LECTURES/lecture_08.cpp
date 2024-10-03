#include <bits/stdc++.h>
using namespace std;
//FRIEND CLASS AND MEMBER FRIEND FUNCTION
class complexn;//forward declaration
class calculator
{
public:
    int add(int a, int b)
    {
        return (a + b);
    }
    int sumRealcomplex(complexn o1, complexn o2);//make another class's function a friend function 
    int sumImgcomplex(complexn o1, complexn o2);
    //------------alternative
    // friend class calculator;
};
class complexn
{
    int a, b;

public:
    void setNumber(int n1, int n2)
    {
        a = n1;
        b = n2;
    }
    void printnumber()
    {
        cout << "your nummber is " << a << " + " << b << "i" << endl;
    }
    friend int calculator::sumImgcomplex(complexn o1,complexn o2);
    friend int calculator::sumRealcomplex(complexn o1,complexn o2);
};
int calculator::sumImgcomplex(complexn o1, complexn o2)
{
    return (o1.b + o2.b);
}
int calculator::sumRealcomplex(complexn o1, complexn o2)
{
    return (o1.a + o2.a);
}
int main()
{
complexn c1,c2;
c1.setNumber(1,2);
c2.setNumber(12,7);
c1.printnumber();
c2.printnumber();

calculator res;
int x=res.sumImgcomplex(c1,c2);
int y=res.sumRealcomplex(c1,c2);
cout<<"The sum of complex number is "<<x<<"+"<<y<<"i";
    return 0;
}