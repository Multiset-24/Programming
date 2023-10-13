#include <bits/stdc++.h>
using namespace std;

int main() {
    int x=6;
    int y=7;
    int* x1=&x;
    int* y1=&y;
    cout <<"sum is:"<< x+y;
    cout<<endl;
    cout<<"sum is(using pointers) :"<<*x1+*y1;
    cin>>*x1>>*y1;
     cout<<"sum is(using pointers) :"<<*x1+*y1;
    return 0;
}