#include <bits/stdc++.h>
using namespace std;
int a=3;  //global variable 
void arguments(int x,int y){
    cout<<&x<<endl<<&y;
}
int main() {
     int x,y; //local variable
     cout<<&x<<endl<<&y<<endl;
     arguments(x,y);
    return 0;
}