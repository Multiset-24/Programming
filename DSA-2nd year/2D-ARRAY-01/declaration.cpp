#include <bits/stdc++.h>
using namespace std;
int main() {
    int arr[3][3]={{1,2,3},{5,6,6},{9,8,3}};
    int brr[3][3]={1,2,3,5,6,6,9,8,3};
    cout<<arr[0][0]<<" "<<brr[0][0]<<endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
        
    }
    
    return 0;
}