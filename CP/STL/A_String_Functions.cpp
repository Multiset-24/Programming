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

    int n, Q;
    read(n, Q);

    string s;
    read(s);

    while (Q--)
    {
        string operation;
        read(operation);

        if (operation == "substr")
        {
            int l, r;
            read(l, r);
            if(l>r) swap(l,r);
            l--;
            r--;
            cout << s.substr(l, r - l + 1) << endl; // substr function-syntax- s.substr(starting_index, length)
        }
        else if (operation == "sort")
        {
            int l, r;
            read(l, r);
            if(l>r) swap(l,r);
            l--;
            r--;
            sort(s.begin() + l, s.begin() + r + 1); // syntax- sort(starting_index, ending_index+1)
        }
        else if (operation == "reverse")
        {
            int l, r;
            read(l, r);
            if(l>r) swap(l,r);
            l--;
            r--;
            reverse(s.begin() + l, s.begin() + r + 1); // syntax- reverse(starting_index, ending_index+1)
        }
        else if (operation == "push_back")
        {
            char c;
            read(c);
            s.push_back(c);
        }
        else if (operation == "print")
        {
            int x;
            read(x);
            x--;
            cout << s[x] << endl;
        }
        else if (operation == "pop_back")
        {
            s.pop_back();
        }
        else if (operation == "back")
        {
            cout << s.back() << endl;
        }
        else if (operation == "front")
        {
            cout << s.front() << endl;
        }
        else if(operation=="erase"){
            int l,r;
            read(l,r);
            if(l>r) swap(l,r);
            l--;
            r--;
            s.erase(l,r-l+1); // syntax- erase(starting_index, length)
        }
    }

    return 0;
}