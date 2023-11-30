#include <bits/stdc++.h>
using namespace std;
// constructors in derived class
/*
CASE 1----->
class B:public A{
    //order of execution of constructor -> first A() then B()
};
 CASE 2---->
class A :public B, public c{
    //order of execution of constructor->B()then c()then A()
};
CASE 3---->
class A: public B,virtual public C{
    //order of execution of constructor -> c()then B()then A()
}
*/
class students
{
protected:
    int roll_num;
    string name;

public:
    students(int rn, string n)
    {
        roll_num = rn;
        name = n;
        cout << "This has been called out -students";
    }
};
class POR
{
protected:
    string posi_name;

public:
    POR(string por_N)
    {
        posi_name = por_N;
        cout << "This has been called out -POR";
    }
};
class rank : public POR, public students
{
protected:
    int ran;

public:
    rank(int rk, string por_N, int rn, string n) : POR(por_N), students(rn, n)
    {
        rk = ran;
        cout << "This has been called out-rank";
    }
};
int main()
{
    rank r(2, "monitor", 69, "snake");
    return 0;
}