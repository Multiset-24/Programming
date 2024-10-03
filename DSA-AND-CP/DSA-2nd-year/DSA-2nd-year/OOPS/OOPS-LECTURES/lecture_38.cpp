#include <bits/stdc++.h>
using namespace std;
/*
template<class T1,class T2>
class multiple_parameters{
    ------------
};
*/
template<class T1,class T2>
class multiple_parameters{
    T1 roll_no;
    T2 name;
    public:
    void getin(T1 roll_no,T2 name){
        this->roll_no=roll_no;
        this->name=name;
    }
    void display(){
        cout<<roll_no<<endl<<name;
    }
};
int main() {
    multiple_parameters<int,string>v;
    v.getin(34,"saurav");
    v.display();

    return 0;
}