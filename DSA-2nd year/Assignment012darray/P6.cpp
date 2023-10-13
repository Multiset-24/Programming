#include <bits/stdc++.h>
using namespace std;
//baad mai karna
void display_mid(int m,int arr[][100]){
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(i==(m-1)/2||j==(m-1)/2){
                cout<<arr[i][j]<<" ";
            }
        }
        
    }
}
int main() {
    int m;
    int a[100][100];
for (int i = 0; i < m; i++)
{
    for (int j = 0; j < m; j++)
    {
        cin>>a[i][j];
    }
}
display_mid;
    return 0;
}