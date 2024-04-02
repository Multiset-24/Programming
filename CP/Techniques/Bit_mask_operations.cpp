#include <bits/stdc++.h>
using namespace std;
//problem link- https://www.hackerearth.com/practice/basic-programming/bit-manipulation/basics-of-bit-manipulation/practice-problems/algorithm/lets-begin/
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

int extractNthBit(int num, int n)
{
    return (num & (1 << n)) != 0;
}

int setNthBit(int num, int n)
{
    return num | (1 << n);
}

int unsetNthBit(int num, int n)
{
    return num & ~(1 << n);
}

int toggleNthBit(int num, int n)
{
    return num ^ (1 << n);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q, num;
    read(q, num);

    while (q--)
    {
        int type, n;
        read(type, n);

        if (type == 1)
        {
            cout << extractNthBit(num, n) << endl;
        }
        else if (type == 2)
        {
            num = setNthBit(num, n);
            cout << num << endl;
        }
        else if (type == 3)
        {
            num = unsetNthBit(num, n);
            cout << num << endl;
        }
        else
        {
            num = toggleNthBit(num, n);
            cout << num << endl;
        }
    }
    return 0;
}