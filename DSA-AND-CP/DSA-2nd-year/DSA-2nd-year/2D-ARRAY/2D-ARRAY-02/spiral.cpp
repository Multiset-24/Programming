#include <bits/stdc++.h>
using namespace std;

int main() {
    int m,n;
    cin>>m>>n;
    int a[m][n];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin>>a[i][j];
    cout<<endl;
    int min_R=0,max_R=(m-1),min_C=0,max_C=(n-1);
    //main concept

    int count=0;
while (min_R<=max_R && min_C<=max_C)
{
    //right
    for (int j=min_C;j<=max_C && count<(n*m); j++)
        cout<<a[min_R][j]<<" ";
        count++;
    min_R++;
    //down
    for (int i = min_R; i <= max_R && count<(n*m); i++)
        cout<<a[i][max_C]<<" ";
        count++;
    max_C--;
    //left
    for (int J = max_C; J>=min_C && count<(n*m); J--)
        cout<<a[max_R][J]<<" ";
        count++;
    max_R--;
    //up
    for (int I = max_R; I>=min_R && count<(n*m); I--)
        cout<<a[I][min_C]<<" ";
        count++;
    min_C++;
}
    return 0;
}