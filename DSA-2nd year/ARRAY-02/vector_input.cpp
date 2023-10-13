#include <bits/stdc++.h>
using namespace std;

int main() {
 vector<int>v(5);//when size is already mentioned
 for (int i = 0; i < 5; i++)
 {
    cin>>v[i];
 }
 for (int i = 0; i < 5; i++)
 {
   cout<<v[i]<<" ";
 }
 
 vector<int>p;
 int n;
 cin>>n;
   for (int i = 0; i <n; i++)
   {
      int x;
      cin>>x;
      p.push_back(x);
   }
   for (int i = 0; i <p.size(); i++)
   {
      cout<<p[i]<<" ";
   }
   
    return 0;
}