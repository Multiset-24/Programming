#include <bits/stdc++.h>
using namespace std;

int main() {
    int m,n;
    cin>>m>>n;
    int arr[m][n];
    int brr[n][m];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin>>arr[i][j];
        }
        
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j< n; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < m; i++)
        {
            brr[j][i]=arr[i][j];
            cout<<arr[i][j]<<" ";
        }
        cout<<endl; 
    }
    cout<<endl<<endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j< m; j++)
        {
            cout<<brr[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}