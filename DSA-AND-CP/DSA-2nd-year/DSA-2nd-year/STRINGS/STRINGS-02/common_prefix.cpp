#include <bits/stdc++.h>
using namespace std;
string common_prefix(vector<string> v)
{
    sort(v.begin(), v.end());
    string first = v[0];
    string last = v[v.size() - 1];
    string s = "";
    if (v.size() == 1){
        return v[0];
    }
    else
    {
        for (int i = 0; i < min(first.size(), last.size()); i++)
        {
            if (first[i] == last[i])
            {
                s += first[i];
            }
            else
            {
                return s;
            }
        }
    }
    return s;
}
int main()
{
    vector<string> v = {"flower", "flow", "flowting"};
    cout << common_prefix(v);
    return 0;
}