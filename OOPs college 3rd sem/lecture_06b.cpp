#include <bits/stdc++.h>
using namespace std;
//objects as function argumnets
class complexN
{
private:
    int a;
    int b;

public:
    void set_data(int v1, int v2)
    {
        a = v1;
        b = v2;
    }
    void set_data_sum(complexN o1, complexN o2)
    {
        a = o1.a + o2.a;
        b = o1.b + o2.b;
    }
    void display_complexN()
    {
        cout << "The complex number is " << a << "+" << b << "i"<<endl;
    }
};

int main()
{
   complexN c1,c2,c3;
   c1.set_data(1,2);
   c1.display_complexN();

   c2.set_data(3,4);
   c2.display_complexN();

   c3.set_data_sum(c1,c2);
   c3.display_complexN();

    return 0;
}