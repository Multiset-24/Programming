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

class f{
    public:
    deque<int>dq;
    deque<int>rdq;
    int sc=0,rv_sc=0,sm=0;
    int shift(){
        if(dq.empty())return 0;
        int x=dq.back();
        sc-=(x*dq.size());
        sm-=x;
        sc+=(x+sm);
        rv_sc-=(x+sm);
        dq.pop_back();
        dq.push_front(x);
        rdq.pop_front();
        rdq.push_back(x);
        sm+=x;
        rv_sc+=(x*dq.size());
        return sc;
    }
    int rev(){
        swap(dq,rdq);
        swap(sc,rv_sc);
        return sc;
    }
    int append(int x){
        dq.push_back(x);
        rdq.push_front(x);
        sc+=(x*dq.size());
        rv_sc+=(x+sm);
        sm+=x;
        return sc;
    }
};
void jarvis()
{
    int q;
    cin>>q;
    f ds;
    while(q--){
        int t;
        cin>>t;
        if(t==1)cout<<ds.shift()<<endl;
        else if(t==2)cout<<ds.rev()<<endl;
        else{
            int x;
            cin>>x;
            cout<<ds.append(x)<<endl;
        }
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