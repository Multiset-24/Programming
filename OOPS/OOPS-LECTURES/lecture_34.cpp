#include <bits/stdc++.h>
using namespace std;
//virtual functions- it's just a function with virtal before it's declaration ,this just overwrites the deafualt work of when an pointer of base class points towards the array of obj of derived class then by dafault it point towards base class member functions but with this it will point towards derived class member function
class shape{
    public:
        virtual void  display(){
            cout<<"this is just the class not the shape";
        }
};

class circle:public shape{
    public:
    void display(){
        cout<<" this is the circle";
    }
};
int main() {
    shape *aakar;
    circle obj;
    aakar=&obj;
    aakar->display();//but ye point to circle ke obj ko karrha tha but yha usne shape vale ko hi choose kia
    return 0;
}