#include <bits/stdc++.h>
using namespace std;

int main() {
    int m,n;
    cin>>m>>n;
    int a[m][n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin>>a[i][j];
        }
    }
    int max_element=0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
           if (a[i][j]>max_element)
           {
            max_element=a[i][j];
           }
           
        }
    }
    cout<<"The maximum element is:"<<max_element;
    
    return 0;
}