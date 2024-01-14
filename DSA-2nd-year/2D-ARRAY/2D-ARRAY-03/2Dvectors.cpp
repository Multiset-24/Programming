#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int>v1;
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(5);
    vector<int> v2;
    v2.push_back(6);
    v2.push_back(7);
    vector<int> v3;
    v3.push_back(8);
    v3.push_back(9);
    v3.push_back(10);
    v3.push_back(11);
    v3.push_back(12);
    vector<vector<int>>v;
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
// for (int i = 0; i < 5; i++)
// {
//     for (int j = 0; j < 5; j++)
//     {
//         cout<<v[i][j]<<" ";
//     }
//     cout<<endl;
// }
cout<<v[0][3];//invalid
    return 0;
}