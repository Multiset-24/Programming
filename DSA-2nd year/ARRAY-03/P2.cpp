#include <bits/stdc++.h>
using namespace std;
// 2 pass method
void sort01(vector<int>&v){
    int noz=0;
    int noo=0;
    int nots=0;
    int i=0;
    int j=v.size()-1;
    for (int  k = 0; k< v.size(); k++)
    {
        if(v[k]==0) noz++;
        else if(v[k]==1) noo++;
        else if(v[k]==2) nots++;
    }
    for (int  k = 0; k< v.size(); k++)
    {
        if(k<noz) v[k]=0;
        else if(k<(noz+noo)) v[k]=1;
        else v[k]=2;
    }
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i];
    } 
}
// single pass method
void sort02(vector<int>&v){
    int mid=0,low=0,high=v.size()-1;
    while (mid<=high)
    {
        if(v[mid]==2){
            int temp=v[mid];
            v[mid]=v[high];
            v[high]=temp;
            high--;
        }
        else if(v[mid]==0){
             int temp=v[mid];
             v[mid]=v[low];
             v[low]=temp;
             mid++;
            low++;
        }else if(v[mid]==1){
            mid++;
        }
    }
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    
}
//main function
int main() {
    int n;
    cin>>n;
    vector<int>v(n);
    for (int  i = 0; i <n; i++)
    {
       cin>>v[i];
    }
    sort01(v);
    cout<<endl;
    sort02(v);
    return 0;
}