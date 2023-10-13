#include <bits/stdc++.h>
using namespace std;
void first_lastdig(int n,int* x,int*y){
    *x=n%10;
    while (n>9)
    {
        n=n/10;
    }
    
*y=n;
cout<<*y<<" "<<*x;
}
int main() {
 int n;
 cin>>n;
 int fdig,sdig;
 int* x=&fdig,*y=&sdig;
 first_lastdig(n,x,y);
    return 0;
}