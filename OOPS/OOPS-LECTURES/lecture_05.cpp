#include <bits/stdc++.h>
using namespace std;
//static variable and functions
class employee
{
    private:
    int id;

public:
    static int count;// static int count=25; will give error here
    void setdata(void)
    {
        cout << "enter ID" << endl;
        cin >> id;
        count++;
    }
    void getdata(void)
    {
        cout << "the ID of the employee is " << id << " and the employee number is " << count << endl;
    employee::getcount();
    }

    static void getcount(void)//can only access the static variable and static functions
    {
       // cout<<id;//throws can error 
        cout << "The value of count is " << count << endl;
    }
};
int employee::count = 1000; // default value is 0, default value can be changed here only
int main()
{
    employee saurav, harsh, kashish, anurag;
    saurav.setdata();
    saurav.getdata();
    //employee::getcount();//static functions can be accessed only in this way

    harsh.setdata();
    harsh.getdata();

    kashish.setdata();
    kashish.getdata();
  //  employee::getcount();

    anurag.setdata();
    anurag.getdata();
   // employee::getcount();
cout<<(employee::count);//class variable is accessed using class name and scope resolution operetor
    return 0;
}