#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define ll long long
typedef pair<int, int> pp;

int main()
{
    ll n;
    cin >> n;
    ll count=0;
    while ((n>0))
    {
        n/=5;
        count+=n;
    }
    cout<<count;
    return 0;
}