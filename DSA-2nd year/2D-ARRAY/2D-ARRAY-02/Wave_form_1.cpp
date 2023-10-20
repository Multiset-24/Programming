#include <bits/stdc++.h>
using namespace std;

int main()
{
int m,n;
cout<<"Enter the rows and columns for the matrix";
cin>>m>>n;
int A[m][n];
//take input
for (int i = 0; i < m; i++)
{
    for (int j = 0; j < n; j++)
    {
        cin>>A[i][j];
    }
    
}
cout<<endl;
//main concept
for (int i = 0; i < m; i++)
{
    if (i%2==0)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<A[i][j]<<" ";
        }
    }
    else{
        for (int j = n-1; j >=0; j--)
        {
            cout<<A[i][j]<<" ";
        }
    }
    cout<<endl;
}
    return 0;
}