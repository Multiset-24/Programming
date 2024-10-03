#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
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
class Mystructure
{
private:
    multiset<int,greater<int>> m1;
    multiset<int,greater<int>> m2;
    int k;
    int sum_k = 0;

public:
    Mystructure(int x)
    {
        k = x;
    }

    void insert(int x)
    {
        if (m1.size() < k)
        {
            m1.insert(x);
            sum_k += x;
        }
        else if (m1.size() == k && x <= *(m1.rbegin()))
        {
            m2.insert(x);
        }
        else if (x > *(m1.rbegin()))
        {
            int y = *(m1.rbegin());
            m1.erase(m1.find(y)); 
            m2.insert(y);
            m1.insert(x);
            sum_k -= y;
            sum_k += x;
        }
    }

    void remove(int x)
    {
        if (m1.find(x) != m1.end())
        {
            m1.erase(m1.find(x));
            if (m2.size() > 0)
            {
                int y = *(m2.begin());
                m2.erase(m2.begin());
                m1.insert(y);
                sum_k += y;
            }
            sum_k -= x;
        }
        else
        {
            if (m2.find(x) != m2.end())
            {
                m2.erase(m2.find(x));
            }
        }
    }

    int sum_top()
    {
        return sum_k;
    }
};
void jarvis()
{
    int q, k;
    cin >> q >> k;

    Mystructure bag(k);

    while (q--)
    {
        int x;
        cin >> x;

        if (x == 1)
        {
            int y;
            cin >> y;

            bag.insert(y);
        }
        else if (x == 2)
        {
            int y;
            cin >> y;

            bag.remove(y);
        }
        else if (x == 3)
        {
            char c;
            cin >> c;

            cout << bag.sum_top() << endl;
        }
    }
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
