#include <bits/stdc++.h>
using namespace std;
// Write a program to calculate the sum of odd numbers between a and b (both inclusive) using recursion.
int Sumodd(int a, int b)
{
    if (a % 2 == 0)
    {
        if (b % 2 == 0)
        {
            if (a >= b)
                return 0;
            return (a + 1) + Sumodd(a + 2, b);
        }
        else if (b % 2 != 0)
        {
            if (a > b)
                return 0;
            return (a + 1) + Sumodd(a + 2, b);
        }
    }
    else if (a % 2 != 0)
    {
        if (b % 2 == 0)
        {
            if (a >= b)
                return 0;
            return (a) + Sumodd(a + 2, b);
        }
        else if (b % 2 != 0)
        {
            if (a > b)
                return 0;
            return (a) + Sumodd(a + 2, b);
        }
    }
}
int main()
{
    int a, b;
    cin >> a >> b;
    cout << Sumodd(a, b);
    return 0;
}