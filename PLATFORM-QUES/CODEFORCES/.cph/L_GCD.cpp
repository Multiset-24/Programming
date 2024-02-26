#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define ll long long
typedef pair<int,int> pp;

int main() {
    int a,b;

    cin>>a>>b;


   while(a!=0){
         int temp = a;
         a = b%a;
         b = temp;
    } // O(log(min(a,b))

   cout<<b<<endl;
    return 0;
}