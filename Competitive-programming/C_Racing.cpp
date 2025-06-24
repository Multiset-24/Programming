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

void jarvis()
{
    int n;
    cin >> n;
    vector<int> d(n+1);
    for(int i = 1; i <= n; i++) cin >> d[i];
    vector<int> L(n+1), R(n+1);
    for(int i = 1; i <= n; i++){
        cin >> L[i] >> R[i];
    }
    vector<int> lo(n+1), hi(n+1);
    lo[0] = hi[0] = 0;
    bool ok = true;
    for(int i = 1; i <= n; i++){
        int nl, nh;
        if(d[i] == 0){
            nl = lo[i-1];
            nh = hi[i-1];
        }
        else if(d[i] == 1){
            nl = lo[i-1] + 1;
            nh = hi[i-1] + 1;
        }
        else {
            nl = lo[i-1];
            nh = hi[i-1] + 1;
        }
        lo[i] = max(nl, L[i]);
        hi[i] = min(nh, R[i]);
        if(lo[i] > hi[i]){
            ok = false;
            break;
        }
    }
    if(!ok){
        cout << -1 << endl;
        return;
    }
    vector<int> ans(n+1);
    int h = lo[n]; 
    for(int i = n; i >= 1; i--){
        if(d[i] == 0 || d[i] == 1){
            int need = d[i];
            int prev_h = h - need;
            if(prev_h < lo[i-1] || prev_h > hi[i-1]){
                ok = false;
                break;
            }
            ans[i] = need;
            h = prev_h;
        } else {
            if(h >= lo[i-1] && h <= hi[i-1]){
                ans[i] = 0;
            } else {
                ans[i] = 1;
                h = h - 1;
            }
        }
    }
    if(!ok){
        cout << -1 << endl;
        return;
    }
    for(int i = 1; i <= n; i++){
        cout << ans[i] << " ";
    }
    cout << endl;
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