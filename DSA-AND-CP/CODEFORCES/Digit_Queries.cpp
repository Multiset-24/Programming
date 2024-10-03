#include <bits/stdc++.h>
using namespace std;

// #define mod 1000000007
#define int long long
typedef pair<int, int> pi;
#define u_mp unordered_map
#define u_st unordered_set
#define r_vector(v, n)           \
    vector<int> v(n + 1, 0);     \
    for (int i = 1; i <= n; i++) \
        cin >> v[i];

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
#define prin9t_2dvector(v)            \
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

int findNthDigit(long long n)
{
    vector<long long> groups(12, 0);
    vector<long long> start(12, 0);
    for (int i = 0; i < 12; i++)
    {
        groups[i] = 9 * (long long)pow(10, i) * (i + 1);
        if (i)
            groups[i] += groups[i - 1];

        start[i] = (long long)(pow(10, i));
    }

    int group =
        lower_bound(groups.begin(), groups.end(), n) - groups.begin();

    if (group == 0)
        return n;
    else
    {
        long long temp = n - groups[group-1];
            int size = group + 1;
            long long divi = (temp - 1) / size;
            int mod = (temp - 1) % size;
            long long finalValue = pow(10, size - 1) + divi;
            cout<<"number"<<finalValue<<endl;
            string str = to_string(finalValue);
            return str[mod] - '0';
    }

    return 0;
}
void jarvis()
{
    long long n;   
    cin >> n;

    cout << findNthDigit(n) << endl;
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
