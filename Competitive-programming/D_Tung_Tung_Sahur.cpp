#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define int long long
// Debugging macro
#ifndef ONLINE_JUDGE
#define DEBUG
#endif

#ifdef DEBUG
#define print_vector(v)          \
    {                            \
        cout << #v << " = [";    \
        for (auto &elem : v)     \
            cout << elem << " "; \
        cout << "]" << endl;     \
    }
#define print_map(m)                                                  \
    {                                                                 \
        cout << #m << " = {";                                         \
        for (auto &pair : m)                                          \
            cout << "{" << pair.first << ": " << pair.second << "} "; \
        cout << "}" << endl;                                          \
    }
#define print_2dvector(v)             \
    {                                 \
        cout << #v << " = [" << endl; \
        for (auto &row : v)           \
        {                             \
            cout << "  [";            \
            for (auto &elem : row)    \
                cout << elem << " ";  \
            cout << "]" << endl;      \
        }                             \
        cout << "]" << endl;          \
    }
#else
#define print_vector(v)
#define print_map(m)
#define print_2dvector(v)
#endif
#define endl '\n'

string s, t;
int n, m;
bool dfs(int i, int j)
{
    if (i == n && j == m)
        return true;
    else if (i >= n || j >= m || s[i] != t[j])
        return false;
    int ans = dfs(i + 1, j + 1);
    if (j + 1 < m && t[j + 1] == s[i])
        ans |= dfs(i + 1, j + 2);
    return ans;
}
void jarvis()
{
    cin >> s >> t;
    n = s.size(), m = t.size();
    int i = 0, j = 0;
    bool p = true;
    while (i < n && j < m)
    {
        // cout<<i<<" "<<j<<endl;
        if (s[i] != t[j])
        {
            // cout<<i<<" "<<j<<endl;
            p = false;
            break;
        }
        int k = i;
        while (k + 1 < n && s[k + 1] == s[i])
        {
            k++;
        }
        int cntS = k - i + 1;
        int l = j;
        while (l + 1 < m && t[l + 1] == t[j])
        {
            l++;
        }
        int cntT = l - j + 1;
        if (cntT < cntS || cntT > 2 * cntS)
        {
            // cout<<i<<" "<<j<<endl;
            p = false;
            break;
        }
        else
        {
            i = k + 1;
            j = l + 1;
        }
    }
    // cout<<p<<" "<<i<<" "<<j<<endl;
    if (!p || i != n || j != m)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
    }
    cout << "-------" << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q = 1;
    cin >> q;
    while (q--)
    {
        jarvis();
    }
    return 0;
}