#include <bits/stdc++.h>
using namespace std;
int main()
{
    int m, n, p, q;
    cout << "Enter the number of rows for the 1st matirx" << endl;
    cin >> m;
    cout << "Enter the number of columns for 1st the matrix" << endl;
    cin >> n;
    cout << "Enter the number of rows for the 2nd matrix" << endl;
    cin >> p;
    cout << "Enter the number of columns for the 2nd matrix" << endl;
    cin >> q;
    if (n!=p)
    {
        cout<<" The matrices are unmultipliable !";
        return 0;
    }
    
    int a[m][n], b[p][q], R[m][q];
    cout << "Enter the elements of the 1st array" << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
        cout << endl;
    }
    cout << "Enter the elements of the 2nd array";
    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < q; j++)
        {
            cin >> b[i][j];
        }
        cout << endl;
    }
    // main step
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < q; j++)
            {
                R[i][j] = 0;
                for (int k = 0; k < n; k++)
                {
                  R[i][j]+=a[i][k]*b[k][j];  
                }
            }
        }
    cout<<"The resultant matrix is :"<<endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < q; j++)
        {
            cout<<R[i][j]<<" ";
        }
        cout<<endl;
    }
    
        return 0;
}