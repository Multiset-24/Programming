#include <bits/stdc++.h>
using namespace std;
void fun(int x=7,int y=8)//default values
    {
        cout<<x<<" "<<y;
}
int main() {
    int x,y;
    fun();
    fun(4,5);//4,5 are priotized over default values
    fun(4);
    return 0;
}