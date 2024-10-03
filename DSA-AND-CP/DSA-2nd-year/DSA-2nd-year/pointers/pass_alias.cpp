#include <bits/stdc++.h>
using namespace std;
void swap(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;    //no  easy logic
    return;
}
int main() {
    int a,b;
    cin>>a>>b;
    swap(a,b);
    cout<<a<<" "<<b;
    return 0;
}