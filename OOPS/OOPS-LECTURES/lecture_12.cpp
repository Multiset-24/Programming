#include <bits/stdc++.h>
using namespace std;
// constructor overloading
int main()
{
    class complex
    {
    private:
        int x, y;

    public:
        void display()
        {
            cout << "Numbers entered by you are- " << x << " " << y << endl;
        }
        complex(int a, int b)//1st constructor
        {
            x = a;
            y = b;
        }
        complex(int a)//2nd constructor
        {
            x = a;
            y = 0;
        }
    };
    complex c1(2, 5);
    c1.display();

    complex c2(3);
    c2.display();
    return 0;
}