#include <bits/stdc++.h>
using namespace std;
#include <vector>
int main() {
 vector<int>p;
 int n;
 cin>>n;
   for (int i = 0; i <n; i++)
   {
      int x;
      cin>>x;
      p.push_back(x);
   }
//    cout<<p.at(2);//at is used to give/edit value of an element in an vector with the help of the index
//    cin>>p.at(2);
//    cout<<p.at(2);
   sort(p.begin(),p.end());
   for (int i = 0; i < n; i++)
   {
    cout<<p[i]<<" ";
   }
   
    return 0;
}