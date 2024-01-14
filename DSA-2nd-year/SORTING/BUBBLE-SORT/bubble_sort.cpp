#include <bits/stdc++.h>
using namespace std;
//bubble sort algorithm with code
int iterate;
void set_vector(vector<int>&v){
    cout<<" Enter the elements of the array-";
         for (int i = 0; i < v.size(); i++)
         {
            cin>>v[i];
         }
         cout<<endl;
}
void display(vector<int>&v){
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
//most efficient bubble sort code
vector<int> sort_bubble(vector<int>&v){
int n=v.size();
for (int i = 0; i < n-1; i++)//traversal
{
    bool flag=true;
    for (int j = 0; j < n-1-i; j++)
    {
       if (v[j]>v[j+1]){
              int temp=v[j];
              v[j]=v[j+1];
              v[j+1]=temp;
              iterate =i+1;
              flag=false;
       }
    }
    if (flag==true)
    {
        break;
    }
}
return v;
}
int main() {
    int n;
    cout<<" Enter the size of the array-";
    cin>>n;
    cout<<endl;
    vector<int>s(n);
    set_vector(s);
    display(s);
    sort_bubble(s);
    display(s);
    if (iterate<n/2) cout<<"Array was almost sorted "<<iterate;

    return 0;
}