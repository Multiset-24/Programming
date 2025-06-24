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
typedef vector<vector<int>> matrix;
matrix mul(matrix m1,matrix m2){
    matrix m3={{0,0},{0,0}};
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            for(int k=0;k<2;k++){
                int e=(m1[i][k]*m2[k][j])%mod;
                m3[i][j]+=e;
                m3[i][j]%=mod;
            }
        }
    }
    return m3;
}
matrix matpow(matrix a,int b){
    matrix res={{1,1},{1,1}};
    while(b){
        if(b&1){
            res=mul(res,a);
        }
        a=mul(a,a);
        b>>=1;
    }
    return res;
}
void jarvis()
{
    int n;
    cin>>n;
    if(n==0 || n==1){
        cout<<n<<endl;
        return;
    }
    matrix a={{1,1},{1,0}};
    matrix fib=matpow(a,n-2);
    cout<<fib[0][0]<<endl;
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