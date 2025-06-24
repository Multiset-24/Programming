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
const int N=5e5+10;
int nss[N];//N sum is square or not ki value store karega ye
bool isq(int x){
    return 1LL*sqrt(x)*sqrt(x)==x;
}
void jarvis()
{
    int n;
    cin>>n;
    if(nss[n]==1)cout<<-1<<endl;
    else{
        for(int i=1;i<=n;i++){
            if(nss[i]){
                cout<<i+1<<" "<<i<<" ";
                i++;
            }
            else cout<<i<<" ";
        }
        cout<<endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for(int i=1;i<N;i++){
        nss[i]=isq((i*(i+1)/2));
    }
    int q = 1;
    cin >> q;
    while (q--)
    {
        jarvis();
    }
    return 0;
}