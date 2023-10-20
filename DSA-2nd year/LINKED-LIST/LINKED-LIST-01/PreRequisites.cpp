#include <bits/stdc++.h>
using namespace std;
class student{
    public:
       string name;
       int roll_num;
       float marks;
       student(string n,int r,float m){
              name=n;
              roll_num=r;
              marks=m;
       }
       void get_data(){
        cout<<"Your name is -"<<name<<endl;
        cout<<"Your roll number is -"<<roll_num<<endl;
        cout<<"Your marks is -"<<marks<<endl;
       }
};
int main() {
    student* s=new student("saurav",21,99.47);
    s->get_data();
    s->name="saurav kumar";
    s->roll_num=22;
    (*s).marks=99.53;
    cout<<endl;
    (*s).get_data();
    cout<<endl;
    return 0;
}