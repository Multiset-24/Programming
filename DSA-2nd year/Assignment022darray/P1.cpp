#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m, n;
    cin >> m >> n;
    int a[m][n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if ((i + j == (m-1)) || (i == j))
            {
                cout << a[i][j] << " ";
            }
            else
            {
                cout << " ";
            }
        }
        cout<<endl;
    }

    return 0;
}