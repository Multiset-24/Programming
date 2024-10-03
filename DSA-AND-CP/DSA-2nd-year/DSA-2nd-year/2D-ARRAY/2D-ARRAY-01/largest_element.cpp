#include <bits/stdc++.h>
using namespace std;

int main() {
    int m,n;
    cin>>m>>n;
    int arr[m][n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin>>arr[i][j];
        }
    }
    cout<<endl;
    int max=arr[0][0];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j]>max)
            {
                max=arr[i][j];
            }
            
        }
    }
    cout<<"largest element in the matrix is-"<<max;
    return 0;
}