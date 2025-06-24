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

int quadratic_solution(int a,int b,int c){
    int lo=1,hi=1e9;

    while(lo<=hi){
        int y=lo+(hi-lo)/2;

        if(a*y*y+b*y+c>0){
            hi=y-1;
        }
        else if(a*y*y+b*y+c<0){
            lo=y+1;
        }
        else{
            return y;
        }
    }
    return 0;
}
void jarvis()
{
    int n;
    cin>>n;

    for(int d=1;d*d*d<=n;d++){
        if(n%d!=0)continue;
        int a=3,b=3*d,c=d*d-n/d;
        int y=quadratic_solution(a,b,c);
        if(y!=0){
            cout<<d+y<<" "<<y<<endl;
            return;
        }
    }

    cout<<-1<<endl;
    return;
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