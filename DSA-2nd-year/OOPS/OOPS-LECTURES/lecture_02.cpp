#include <bits/stdc++.h>
using namespace std;
class employee
{
private:
    int a, b, c;

public:
    int d, e;
    void setData(int a1, int b1, int c1);//Declaration
    void getData()
    {
        cout << a<<endl;
        cout << b<<endl;
        cout << c<<endl;
        cout << d<<endl;
        cout << e<<endl;
    }
};
void employee :: setData(int a1,int b1,int c1){
    a=a1;
    b=b1;
    c=c1;
}
int main()
{
employee saurav;
saurav.d=22;
saurav.e=12;
saurav.setData(23,05,02);
saurav.getData();
    return 0;
}