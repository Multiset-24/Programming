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
    int h,w,a,b;
    cin>>h>>w>>a>>b;
    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    x1+=a;
    x2+=a;
    if(y1==y2){
        if((x1-x2)%a==0)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    else if(x1==x2){
        if((y1-y2)%b==0)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    else{
        if((y1-y2)%b==0 || (x1-x2)%a==0)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
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