#include <bits/stdc++.h>
using namespace std;
void vectordisplay(vector<vector<int>> &v)
{
    cout << v.size() << " " << v[0].size();
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[0].size(); j++)
        {
            int x;
            cin>>x;
            v.push_back(x);
        }
    }
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[0].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    vector<vector<int>> value;
    vectordisplay(value);
    return 0;
}