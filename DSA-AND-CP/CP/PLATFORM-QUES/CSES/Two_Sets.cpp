#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define ll long long
typedef pair<int, int> pp;

void solve(ll n,ll sum)
{
    cout << "YES\n";
    vector<ll> set1;
    vector<ll> set2;
    ll mid = sum / 2;

    for (ll i = n; i >= 1; i--)
    {
        if (i <= mid)
        {
            set1.push_back(i);
            mid = mid - i;
        }
        else
        {
            set2.push_back(i);
        }
    }

    cout << set2.size() << endl;

    for (auto ele : set2)
        cout << ele << " ";

    cout << endl
         << set1.size() << endl;

    for (auto ele : set1)
        cout << ele << " ";
}
int main()
{
    ll n;

    cin >> n;

    ll sum = n * (n + 1) / 2;

    if (sum % 2 != 0)
    {
        cout << "NO";
        return 0;
    }
    else
    {
        solve(n, sum);
    }
    return 0;
}