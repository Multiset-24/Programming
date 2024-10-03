#include <bits/stdc++.h>
using namespace std;
//this is the only way to pass an 2D-array into a function
void tdaI(int a[3][3]){
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin>>a[i][j];
        }
    }
    
}
int main() {
 int a[3][3];
 tdaI(a);
 for (int i = 0; i < 3; i++)
 {
    for (int j = 0; j < 3; j++)
    {
        cout<<a[i][j]<<" ";
    }
    cout<<endl;
 }
 
    return 0;
}