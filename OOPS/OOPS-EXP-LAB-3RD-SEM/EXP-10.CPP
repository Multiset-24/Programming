#include <iostream>
using namespace std;
//11.	Write a C++ program to create three objects for a class named pntr_obj with data members such as roll_no & name . Create a member function set_data() for setting the data values and print() member function to print which object has invoked it using ‘this’ pointer.
class pntr_obj {
private:
    int roll_no;
    string name;

public:
    void set_data(int roll, const string& student_name) {
        roll_no = roll;
        name = student_name;
    }

    void print() {
        cout << "Object with roll_no " << roll_no << " and name " << name << " has invoked this function." << endl;
    }
};

int main() {
    pntr_obj obj1, obj2, obj3;

    obj1.set_data(101, "Alice");
    obj2.set_data(102, "Bob");
    obj3.set_data(103, "Charlie");

    obj1.print();
    obj2.print();
    obj3.print();

    return 0;
}
