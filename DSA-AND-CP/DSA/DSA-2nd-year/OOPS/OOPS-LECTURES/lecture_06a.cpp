#include <bits/stdc++.h>
using namespace std;
//array of objects
class employee
{
private:
    int salary;
    int id;

public:
    void set_id_salary()
    {
        cout << "Enter the ID:" << endl;
        cin >> id;
        cout << "Enter the salary of the employee:";
        cin >> salary;
    }
    void get_id_salary()
    {
        cout << "The id of the employee is " << id << endl
             << "The salary of the employee is " << salary;
    }
};
int main()
{
    int n;
    cout << "Enter the number of employee ";
    cin >> n;
    employee fb[n];
    for (int i = 0; i < n; i++)
    {
        fb[i].set_id_salary();
        fb[i].get_id_salary();
        cout<<endl;
    }

    return 0;
}