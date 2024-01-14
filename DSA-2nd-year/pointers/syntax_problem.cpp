#include <bits/stdc++.h>
using namespace std;

int main() {
    int x,y;
    //  int* p=&x,u=&y //error
    int* p=&x,u=y;  //no error
    cout<<p<<" "<<u; //u is not a pointer it's a pointer having a garbage value
    return 0;
}