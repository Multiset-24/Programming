#include <bits/stdc++.h>
using namespace std;
// this is for sorting the array of 0's and 1's don't use sort stl
void sort02(vector<int>&v){
    int i=0;
    int j=v.size()-1;
    while(i<j){
        if(v[i]==1&&v[j]==0){
        int temp=v[i];
        v[i]=v[j];
        v[j]=temp;
        i++;
        j--;
        }
        else if(v[j]==1) j--;
        else if(v[i==0]) i++;
    }
    for (int  k= 0; k < v.size(); k++)
    {
        cout<<v[k];
    }
    
}
void sort01(vector<int>v)
{
    int noo = 0, noz = 0;
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        if (v[i] == 0) noz++;
         else noo++;
    }
    for (int i = 0; i < n; i++)
    {
        if(i<noz) v[i]=0;
        else v[i]=1;
    }
for (int i = 0; i < n; i++)
{
    cout<<v[i];
}

    
}
    int main()
    {
        int n;
        cin >> n;
        vector<int>v(n);
        for (int i = 0; i < n; i++)
        {
            cin>>v[i];
        }
        sort01(v);
        cout<<endl;
        sort02(v);
            return 0;
    }
