#include <bits/stdc++.h>
using namespace std;
/*inheritancc in oops
----------->Types of inheritence
1.single inheritence
2.Multiple inheritence
3.Hierarchichal inheritence
4.Multilevel inheritence*/
//------------->
// Derived class syntax
/*
class {{derived-class-name}}:{{visibility-mode}} {{base-class-name}}
{
    class members/methods etc
}
*/
class employee
{
public:
    int id;
    float salary;
    employee(int idoe, int s)
    { 
        id = idoe;
        salary = s;
    }
    employee(){};
};
class programmer : public employee
{
public:
    int languagecode;
    programmer(int idp)
    {
        id = idp;
        languagecode = 9;
    }
    void getdata()
    {
        cout << id << endl;
    }
};
int main()
{
    employee saurav, sneha;
    saurav = employee(2, 100);
    sneha = employee(1, 500);
    cout << saurav.salary << endl;
    cout << sneha.salary << endl;
    programmer skillf(10);
    cout << skillf.languagecode << endl;
    cout << skillf.id << endl; // because we have inherited it privately
    skillf.getdata();
    return 0;
}