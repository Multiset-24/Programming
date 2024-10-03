#include <bits/stdc++.h>
using namespace std;
//more on friends functions
class Y;
class X{
    private:
    int data;
    friend void exchange(X&o1,Y&o2);
    public:
    void setvalue(int value){
        data=value;
    }
     void display(void){
            cout<< data <<endl;
        }
    void add(X,Y);
};
class Y{
    int num;
    friend void exchange(X&o1,Y&o2);
    public:
    void setvalue(int value){
        num=value;
    }
     friend  void X::add(X,Y);
     void display(void){
            cout<< num <<endl;
        }
};
void  X::add(X o1, Y o2){
    cout<<"summing data of X and Y objects gives me "<<o1.data+o2.num;
}
void exchange(X&o1,Y&o2){
int temp=o1.data;
o1.data=o2.num;
o2.num=temp;
}

int main() {
 X x1;
 Y y1;
 x1.setvalue(3);
 y1.setvalue(4);
 x1.add(x1,y1);
 cout<<endl;
 exchange(x1,y1);
 x1.display();
 y1.display();
    return 0;
}