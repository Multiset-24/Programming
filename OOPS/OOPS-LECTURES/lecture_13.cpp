#include <bits/stdc++.h>
using namespace std;
//constructor with default arguments
class complexn{
    private :
    float data1,data2;
    public:
    complexn(float h=8,float b=8){
        data1=h;
        data2=b;
    }
    void area(){
        float area=(data1*data2);
        cout<<area<<endl;
    }
};
int main() {
 complexn c1;
 c1.area();
 complexn c2(4,5.5);
 c2.area();
    return 0;
}