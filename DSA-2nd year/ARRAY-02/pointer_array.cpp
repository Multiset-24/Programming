#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[6]={23,45,67,1,24,99};
int* p=arr;
int* q=&arr[0];
// int* s=&arr; this will give error
cout<<p<<" "<<q<<" "<<*p<<" "<<*q<<endl;
for (int i = 0; i < 6; i++)
{
    cin>>p[i];
    cout<<endl;
}
for (int i = 0; i < 6; i++)
{
    cout<<p[i]<<" ";
}

    return 0;
}