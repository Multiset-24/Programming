#include <bits/stdc++.h>
using namespace std;
//run time polymorphism
class shape{
    public:
        void display(){
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