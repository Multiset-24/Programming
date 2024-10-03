#include <iostream>
using namespace std;
// pointers to objects and arrow operator
class complex
{
private:
    int real, imaginary;

public:
    void get_data()
    {
        cout << "The imaginary part and real part are-" << imaginary << " " << real << endl;
    }
    void set_data(int r, int i)
    {
        real = r;
        imaginary = i;
    }
};
int main()
{
    // complex c1;
    // complex *ptr = &c1;
    complex *ptr = new complex;
    (*ptr).set_data(69, 88);
    (*ptr).get_data();
    ptr->get_data(); // new method- arrow operator
    complex *ptr1 = new complex[4];
    ptr1->set_data(1, 2);
    ptr1->get_data();
    
    return 0;
}