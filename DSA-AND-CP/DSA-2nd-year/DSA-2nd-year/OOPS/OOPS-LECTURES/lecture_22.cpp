#include <bits/stdc++.h>
using namespace std;
//multilevel inheritence
class students{
   protected:
   int roll_num;
   public:
   void set_roll_num(int r);
   void get_roll_num();
};
class Exam:protected students{
     protected:
    float maths_m;
    float physics_m;
    public:
    void set_marks(float m1,float m2);
    void get_marks();
};
class result:public Exam{
    float result;
      public:
      void display_results(){
        get_roll_num();
        get_marks();
        cout<<"Your result is "<<(maths_m+physics_m)/2<<"%"<<endl;
      }
};
void students::set_roll_num(int r){
    roll_num=r;
}
void students::get_roll_num(){
    cout<<"Students roll number is "<<roll_num<<endl;
}
void Exam::set_marks(float m1,float m2){
maths_m=m1;
physics_m=m2;
}
void Exam::get_marks(){
    cout<<"Your marks in exam for maths and physics respectively are "<<maths_m<<","<<physics_m<<endl;
}
int main() {
    students s1;
    s1.set_roll_num(69);
    result r1;
    r1.set_marks(99.0,95.0);
    r1.display_results();
    return 0;
}