#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define vi vector<ll>
#define sz(v) (ll)v.size()
#define all(v) v.begin(),v.end()
#define pb push_back
#define pii pair<ll,ll> 
#define fastio                        \
       ios_base::sync_with_stdio(false); \
       cin.tie(NULL);                    \
       cout.tie(NULL);

int main() {
    fastio;

    ll t;
    cin>>t;

    while (t--){

        ll n,k;
        cin>>n>>k;

        vi a(n);
        for(int i =0;i<n;i++) cin>>a[i];

        ll ans = *max_element(all(a)) ;

        for(int i = 1;i<n;i++){
            vi x = a;
            ll kt = k;
            for(int j=i-1;j>=0;j--){
                if(a[j] > a[j+1]) continue;
                ll diff = a[j];
                a[j] = a[j+1] + 1;
                diff = a[j] - diff;
                if(kt >= diff){
                    kt -= diff;
                    ans = max(ans,a[j]);
                }else break;
            }
            a = x;
        }

        for(int i = 1;i<n;i++){
            vi x = a;
            ll kt = k;
            for(int j=i-1;j>=0;j--){
                if(a[j] > a[j+1]) continue;
                ll diff = a[j];
                if(j>=1) a[j] = min(a[j+1]+1 , a[j-1]);
                else a[j] = a[j+1]+1;
                diff = a[j] - diff;
                if(kt >= diff){
                    kt -= diff;
                    ans = max(ans,a[j]);
                }else break;
            }
            a = x;
        }
        
        cout<<ans<<'\n';
    }

    return 0;
}