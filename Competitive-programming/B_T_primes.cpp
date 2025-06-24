#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define int long long
// Debugging macro
#ifndef ONLINE_JUDGE
#define DEBUG
#endif

#ifdef DEBUG
#define print_vector(v) { cout << #v << " = ["; for (auto &elem : v) cout << elem << " "; cout << "]" << endl; }
#define print_map(m) { cout << #m << " = {"; for (auto &pair : m) cout << "{" << pair.first << ": " << pair.second << "} "; cout << "}" << endl; }
#define print_2dvector(v) { cout << #v << " = [" << endl; for (auto &row : v) { cout << "  ["; for (auto &elem : row) cout << elem << " "; cout << "]" << endl; } cout << "]" << endl; }
#else
#define print_vector(v)
#define print_map(m)
#define print_2dvector(v)
#endif
#define endl '\n'

bool isprime(int x){
    if(x==1)return false;
    for(int i=2;i*i<=x;i++){
        if(x%i==0)return false;
    }
    return true;
}
bool f(int n) {
    int low = 1, high = 1e6 + 10; //we use binary search on possible sqrts since we can not go over 1 to n route due to long long overflow
    while (low <= high) {
        int mid = (low + high) / 2;
        int sq = mid * mid;
        if (sq == n) return isprime(mid);
        else if (sq < n) low = mid + 1;
        else high = mid - 1;
    }
    return false;
}
void jarvis()
{
    int n;
    cin>>n; 
    vector<int>num(n,0);
    for(auto &x:num){
        cin>>x;
        cout<<(f(x)?"YES":"NO")<<endl;
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