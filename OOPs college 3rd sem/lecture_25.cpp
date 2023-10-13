#include <bits/stdc++.h>
using namespace std;
// virtual base class & operator overloading
class student
{
protected:
    int roll_num;

public:
    void set_rn(int rn){
        roll_num=rn;
    }
    void get_rn(void){
        cout<<"Your roll number is -"<<roll_num;
    }
};
class test :  virtual public student
{
    protected:
    int maths,physics,chemistry;
    public:
    void set_marks(int m,int p,int c){
        maths=m;
        physics=p;
        chemistry=c;
    }
    void get_marks(void){
        cout<<"Your maths marks is-"<<maths<<endl;
        cout<<"Your physics marks is-"<<physics<<endl;
        cout<<"Your chemistry marks is-"<<chemistry<<endl;
    }
};
class sports : public virtual student
{
    protected:
    int score;
    public:
    void set_score(int s){
        score=s;
    }
    void get_score(void){
        cout<<"Your score in sports is-"<<score<<endl;
    }
};
class result : public test, public sports
{
    public:
   void get_results(void){
    int result=maths+chemistry+physics+score;
    get_rn();
    get_marks();
    get_score();
    cout<<"Your total score is-"<<result<<"/400"<<endl;
   }

};
int main()
{
result r;
r.set_rn(420);
r.set_marks(99,100,100);
r.set_score(80);
r.get_results();
    return 0;
}