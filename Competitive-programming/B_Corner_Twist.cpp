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

int n,m;
vector<vector<int>>a,b;
void op1(int i,int j){
    a[i][j]+=1;
    a[i][j]%=3;
    a[i+1][j]+=2;
    a[i+1][j]%=3;
    a[i][j+1]+=2;
    a[i][j+1]%=3;
    a[i+1][j+1]+=1;
    a[i+1][j+1]%=3;
}
void op2(int i,int j){
    a[i][j]+=2;
    a[i][j]%=3;
    a[i+1][j]+=1;
    a[i+1][j]%=3;
    a[i][j+1]+=1;
    a[i][j+1]%=3;
    a[i+1][j+1]+=2;
    a[i+1][j+1]%=3;
}
void jarvis()
{
    cin>>n>>m;
    vector<string>s1(n),s2(n);
    a.assign(n,vector<int>(m,0));
    b.assign(n,vector<int>(m,0));
    for(int i=0;i<n;i++)cin>>s1[i];
    for(int i=0;i<n;i++)cin>>s2[i];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            a[i][j]=s1[i][j]-'0';
            b[i][j]=s2[i][j]-'0';
        }
    }
    for(int i=0;i<n-1;i++){
        for(int j=0;j<m-1;j++){
            if(a[i][j]==b[i][j])continue;
            if((a[i][j]==1 && b[i][j]==2)||(a[i][j]==0&&b[i][j]==1)||(a[i][j]==2&&b[i][j]==0)){
                op1(i,j);
            }
            else{
                op2(i,j);
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]!=b[i][j]){
                cout<<"NO"<<endl;
                return;
            }
        }
    }
    cout<<"YES"<<endl;
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