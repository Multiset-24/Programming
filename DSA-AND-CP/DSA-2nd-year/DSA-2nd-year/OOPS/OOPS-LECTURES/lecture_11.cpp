#include <bits/stdc++.h>
using namespace std;
// parameterized and default constructors
class complexn
{
private:
    int a, b;

public:
    complexn(int x,int y)
    {
        a = x;
        b = y;
    }
    void printnumber(void){
        cout<<"Your point is ( "<<a<<","<<b<<")"<<endl;
    }
};
int main()
{
    //implicit call
    complexn p(5,7);//implicit call
    p.printnumber();
//these just initiate the value of main function and invoked automatically when an object is created
    complexn q=complexn(1,2);//explicit call
q.printnumber();
    return 0;
}