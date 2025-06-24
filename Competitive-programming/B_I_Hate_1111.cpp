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
    int n;
    cin >> n;
    // we can make everythig using chicken mcnugget theorem isme agr do number hai jo co-prime hai then maximum number jo inse nhi bn skta hai vo hai lcm(x,y)-x-y thus for 11,111 maximum number is 1099 less than 1111 hence any number>=1100 can always be represented as a*11+b*111
    /*
    1111=111*10+1=(11*10+1)*10+1=11*100+11
    11111=1111*10+1=1010*11+1=1000*11+111
    so  every number can be represented as 11x+111y=C
    */
    while (n > 1)
    {
        if (n % 11 == 0)
        {
            cout << "YES" << endl;
            return;
        }
        n -= 111;
    }
    cout << (n == 0 ? "YES" : "NO") << endl;
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