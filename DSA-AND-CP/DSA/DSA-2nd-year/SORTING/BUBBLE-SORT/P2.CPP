#include <bits/stdc++.h>
using namespace std;
//push zeroes to the end while maintaining the relative order of other elements
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
vector<int>pro_blem2(vector<int>&v){
    int n=v.size();
    for (int i = 0; i <n-1; i++)
    {
        for (int j = 0; j < n-1-i; j++)
        {
            if(v[j]==0){
                swap(v[j],v[j+1]);
            }
        }
    }
    return v;
}
int main() {
    int n;
    cout<<" Enter the size of the array-";
    cin>>n;
    vector<int>p2(n);
    set_vector(p2);
    pro_blem2(p2);
    display(p2);
    return 0;
}