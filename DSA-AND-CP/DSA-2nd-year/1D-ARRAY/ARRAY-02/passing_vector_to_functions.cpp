#include <bits/stdc++.h>
using namespace std;
void change(vector<int>p){
    p[0]=100;
}
void change2(vector<int>& q){
    q[0]=100;
}
int main() {
     vector<int>x(6);
     for (int i = 0; i < x.size(); i++)
     {
       cin>>x[i];
     }
     change(x);
     for (int i = 0; i < x.size(); i++)
     {
       cout<<x[i];
     }
     vector<int>y(6);
     for (int i = 0; i < y.size(); i++)
     {
       cin>>y[i];
     }
     change2(y);
     for (int i = 0; i < y.size(); i++)
     {
       cout<<y[i];
     }
    return 0;
}