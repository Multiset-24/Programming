#include <bits/stdc++.h>
using namespace std;
int main() {
 int n;
 cin>>n;
 //last digit 
 int t=n;
 cout<<n%10<<endl;
 //first digit
 while(t>9){
    t=t/10;
 }
 int arr[]={1,2,3,4,4,443,2};
 cout<<endl<<t<<endl;
cout<<*(arr+1)<<endl;
    return 0;
}