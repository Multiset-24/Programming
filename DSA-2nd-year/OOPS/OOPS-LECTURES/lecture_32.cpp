#include <bits/stdc++.h>
using namespace std;
//this pointer
class A{
   int a,b;
   public:
         void get_data(int a,int b){
            this->a=a;
            this->b=b;
         }
         void set_data(){
            cout<<" The value of a is "<<a<<" and b is "<<b<<endl;
         }
};
int main() {
 A *ano=new A[3];
 ano->get_data(4,5);
ano->set_data();
    return 0;
}