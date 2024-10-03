#include <bits/stdc++.h>
using namespace std;

int main() {
 // cout row number having maximum sum
 int m,n;
 cin>>m>>n;
 int a[m][n];
 for (int i = 0; i < m; i++)
 {
    for (int j = 0; j < n;j++)
    {
        cin>>a[i][j];
    }
 }
 int max_sum=INT_MIN,sum=0,max_index=0;
 for (int i = 0; i < m; i++)
 {
    sum=0;
    for (int j = 0; j < n;j++)
    {
        sum=sum+a[i][j];
    }
    if(max_sum<sum){
        max_sum=sum;
        max_index=i+1;
    }
    
 }
 cout<<"The "<<max_index<<" row has the maximum sum i.e "<<max_sum;
    return 0;
}