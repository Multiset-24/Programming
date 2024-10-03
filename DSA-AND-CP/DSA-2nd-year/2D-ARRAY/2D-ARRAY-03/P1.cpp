#include <bits/stdc++.h>
using namespace std;
//pascal triangle leetcode 118
int main() {
    int numRow;
    cin>>numRow;
    vector<vector<int>>v;
    for (int i = 0; i < numRow; i++)
    {
        vector<int>a(i+1);
        v.push_back(a);
        for (int j = 0; j <=i; j++)
        {
            if (j==0||i==j)
            {
                v[i][j]=1;
            }
            else{
                v[i][j]=v[i-1][j]+v[i-1][j-1];
            }
        }
    }
    for (int i = 0; i < numRow; i++)
    {
        for (int j = 0; j <=i; j++)
        {
            cout<<" "<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}