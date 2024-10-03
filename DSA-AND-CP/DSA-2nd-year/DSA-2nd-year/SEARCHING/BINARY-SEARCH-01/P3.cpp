#include <bits/stdc++.h>
using namespace std;
//find the smallest non negative element in it.
// O(n) approach
int On_approach(vector<int> &v)
{
    int n = v.size();
    for (int i = 0; i < n - 1; i++)
    {
        if (v[i + 1] != v[i] + 1)
        {
            return v[i] + 1;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    cout << On_approach(v);
    return 0;
}