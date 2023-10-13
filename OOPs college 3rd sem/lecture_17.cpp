#include <bits/stdc++.h>
using namespace std;
//destructor intro
int countn=0;
class constructor{
    int a,b;
    public:
    constructor(){
        cout<<"This is when constructor is called "<<endl;
        countn++;
    }
    ~constructor(){
        cout<<"This is when distructor is created "<<endl;
        countn--;
    }
    void display(){
        cout<<"The value of countn is "<<countn<<endl;
    }
};
int main() {
 constructor n1;
 n1.display();
 {//this is block when this block ends the destructor gets activated
constructor n2;
n2.display();
 }
//after this n1 got destructed 
    return 0;
}