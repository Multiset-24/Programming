#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define int long long
#ifndef ONLINE_JUDGE
  #define DEBUG
#endif
#ifdef DEBUG
  #define print_vector(v) { cout << #v << " = ["; for (auto &e : v) cout << e << " "; cout << "]\n"; }
#else
  #define print_vector(v)
#endif
#define endl '\n'

// ---------------------- your hasher structs ----------------------
struct hasher{
    int n, _k, _p;
    vector<int> powk, base;
    
    void init(const string &s, int k, int p){
        _k = k; _p = p;
        n = s.length();
        powk.resize(n+1);
        base.resize(n+1);
        powk[0] = 1;
        base[0] = 0;
        for(int i = 0; i < n; i++){
            int num = (s[i]-'a'+1) % _p;
            base[i+1] = (base[i]*1LL*_k + num) % _p;
            powk[i+1] = (powk[i]*1LL*_k) % _p;
        }
    }
    int gethash(int l,int r) const {
        int ans = (base[r+1] - base[l]*1LL*powk[r-l+1]) % _p;
        return ans < 0 ? ans + _p : ans;
    }
};

struct double_hash{
    hasher a, b;
    void init(const string &s){
        a.init(s, 37, 1000000021);
        b.init(s, 39, 1000000009);
    }
    pair<int,int> get(int l,int r) const {
        return { a.gethash(l,r), b.gethash(l,r) };
    }
};
// ---------------------------------------------------------------

// build suffix-array by sorting with hash-based comparator
vector<int> build_sa_hash(const string &S){
    int N = S.size();
    double_hash dh;
    dh.init(S);
    
    vector<int> sa(N);
    iota(sa.begin(), sa.end(), 0);
    
    auto cmp = [&](int i, int j){
        if(i == j) return false;
        int maxlen = N - max(i,j);
        int lo = 0, hi = maxlen-1, lcp = -1;
        while(lo <= hi){
            int mid = (lo + hi) >> 1;
            if(dh.get(i, i+mid) == dh.get(j, j+mid)){
                lcp = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        // agar ek suffix dusre ka prefix hai
        if(lcp + 1 >= maxlen) 
            return i > j;  // shorter suffix is smaller
        return S[i + lcp + 1] < S[j + lcp + 1];
    };
    
    sort(sa.begin(), sa.end(), cmp);
    return sa;
}

void jarvis(){
    string A, B;
    cin >> A >> B;
    int n = A.size(), m = B.size();
    string S = A + A + "#" + B + B + "$";
    
    // auto SA = build_sa_hash(S);
    int  seenB = 0, ans = 0;
    // int sep = 2*n;  // index of '#'
    // for(int pos : SA){
    //     if(pos < n){
    //         // rotation of A at k=pos
    //         ans += (m - seenB);
    //     }
    //     else if(pos > sep && pos <= sep + m){
    //         // rotation of B at j = pos - (sep+1)
    //         seenB++;
    //     }
    // }
    // cout << ans << endl;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    // cin >> t;
    while(t--) jarvis();
    return 0;
}
