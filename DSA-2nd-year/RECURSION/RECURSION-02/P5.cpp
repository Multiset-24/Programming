#include <bits/stdc++.h>
using namespace std;
// CONCEPT OF PRE-IN-POST
/*
---------VISUALIZE WITH DIFFERENT STRUCTURE--------
1. TREE DIAGRAM-A bit difficult
2. CALL STACKS-make two seperate stacks one for output and other for call
*/

void pip(int n)
{
    if (n == 0)
        return;
    cout << "pre " << n << endl;
    pip(n - 1);
    cout << "In " << n << endl;
    pip(n - 1);
    cout << "post" << n << endl;
}
// Ques1- print zigzag pattern
void zigzag(int n)
{
    if (n == 0)
        return;
    cout << n;
    zigzag(n - 1);
    cout << n;
    zigzag(n - 1);
    cout << n;
}

int main()
{
    // pip(2);
    zigzag(5);
    return 0;
}