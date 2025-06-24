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
    int x_axis[14]={0};

    for(int i=1;i<=7;i++){
        int x;cin>>x;
        x_axis[x]++;
    }

    bool _3f=false,_2f=false;

    for(int i=1;i<=13;i++){
        if(!_3f && x_axis[i]>=3){
            _3f=true;
        }
        else if(x_axis[i]>=2){
            _2f=true;
        }

        if(_2f==1 && _3f==1){
            cout<<"Yes"<<endl;
            return;
        }
    }

    cout<<"No"<<endl;
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