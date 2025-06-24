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
    int a,b,xk,yk,xq,yq;
    cin>>a>>b>>xk>>yk>>xq>>yq;
    int dx[8] = {+a, +a, -a, -a, +b, +b, -b, -b};
    int dy[8] = {+b, -b, +b, -b, +a, -a, +a, -a};  
    int cnt=0;
    set<pair<int,int>>km,qm;
    for(int i=0;i<8;i++){
        int kkx=xk+dx[i],kky=yk+dy[i];
        int qkx=xq+dx[i],qky=yq+dy[i];
        km.insert({kkx,kky});
        qm.insert({qkx,qky});
    }
    for(auto it:km){
        if(qm.count(it))cnt++;
    }
    cout<<cnt<<endl; 
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