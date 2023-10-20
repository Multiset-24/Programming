#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<int>>v(3,vector<int>(3,2));
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[0].size(); j++)
        {
           cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    return 0;
}