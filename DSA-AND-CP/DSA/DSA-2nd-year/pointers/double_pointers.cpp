#include <bits/stdc++.h>
using namespace std;

int main() {
    int x;
    int* ptr=&x;
    int** p=&ptr;
    cout<<ptr<<" "<<" "<<p<<" "<<*p<<endl;
    cout<<++(**p);
    return 0;
}