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

void jarvis()
{
    int n, k;
    cin >> n >> k;
    int x = 0;
    int msb_k = 30;
    for (int i = 30; i >= 0; i--)
    {
        if (k & (1LL << i))
        {
            msb_k = i;
            break;
        }
    }
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 62; i >= 0; i--)
    {
        bool set_in_k = ((k >> i) & 1);
        int cnt_0 = 0;
        int cnt_1 = 0;
        int greater_num = (x | (1LL << i));
        bool is_less_made_sure = false;
        for (int j = 0; j < n; j++)
        {
            if (a[j]&(1LL << i))
            {
                cnt_1++;
            }
            else
            {
                cnt_0++;
            }
        }
        if (set_in_k || is_less_made_sure)
        {
            if (cnt_0 > cnt_1)
            {
                x = (x | (1LL << i));
            }
            continue;
        }
        else if (greater_num < k && !set_in_k)
        {
            if (cnt_0 > cnt_1)
            {
                x = (x | (1LL << i));
            }
        }
        else
        {
            if (i <= msb_k)
            {
                is_less_made_sure = true;
            }
        }
    }
    int ans=0;
    for(int i=0;i<n;i++)ans+=(x^a[i]);
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q = 1;
    // cin >> q;
    while (q--)
    {
        jarvis();
    }
    return 0;
}