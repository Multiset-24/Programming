#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define int long long
typedef pair<int, int> pi;
#define u_mp unordered_map
#define u_st unordered_set
template <typename T>

// Function templates for reading input
void read(T &t)
{
    cin >> t;
}
template <typename T, typename... Args>
void read(T &t, Args &...args)
{
    cin >> t;
    read(args...);
}

// Debugging macro
#define DEBUG
#ifdef DEBUG
#define debug(x) cout << #x << " = " << x << endl
#else
#define debug(x)
#endif

#define endl '\n'

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q;
    deque<int> dq;
    read(q);
    while (q--)
    {
        string operation;
        read(operation);
        if (operation == "push_back")
        {
            int x;
            read(x);
            dq.push_back(x);
        }
        else if (operation == "push_front")
        {
            int x;
            read(x);
            dq.push_front(x);
        }
        else if (operation == "pop_back")
        {
            if (dq.size() > 0)
                dq.pop_back();
        }
        else if (operation == "pop_front")
        {
            if (dq.size() > 0)
                dq.pop_front();
        }
        else if (operation == "front")
        {
            if (dq.size() > 0)
                cout << dq.front() << endl;
        }
        else if (operation == "back")
        {
            if (dq.size() > 0)
                cout << dq.back() << endl;
        }
        else if (operation == "print")
        {
            int idx;
            read(idx);
            idx--;
            if (idx >= 0 && idx < dq.size())
                cout << dq[idx] << endl;
        }
        else
            cout << "Invalid operation" << endl;
    }
    return 0;
}