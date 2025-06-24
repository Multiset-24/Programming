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

// full form -> get smallest number 
vector<int> gsn(int n,int s){
    if(n==1 && s==0)return {0};
    vector<int>sn;
    bool f=false;
    for(int i=1;i<=9;i++){
        if(s-i>=0 && 9*(n-1)>=(s-i)){
            sn.push_back(i);
            s-=i;
            n--;
            f=true;
            break;
        }
    }
    if(!f)return {-1};
    while((n-1)*9>=s){
        n--;
        sn.push_back(0);
    }
    for(int i=1;i<=9;i++){
        if(s-i>=0 && 9*(n-1)>=(s-i)){
            sn.push_back(i);
            s-=i;
            n--;
            f=true;
            break;
        }
    }
    if(!f)return {-1};
    while(n && s){
        sn.push_back(9);
        s-=9;
        n--;
    }
    if(s!=0)return {-1};
    return sn;
}

// full form -> get greatest number
vector<int> ggn(int m,int s){
    if(m>1 && s==0){
        return {-1};
    }
    vector<int>gn;
    while(m>0 && s>0){
        if(s>=9){
            gn.push_back(9);
            s-=9;
        }
        else {
            gn.push_back(max(0LL,s));
            s=0;
        }
        m--;
    }
    if(s!=0){
        return {-1};
    }
    else{
        while(m){
            gn.push_back(0);
            m--;
        }
        return gn;
    }
}
void jarvis()
{
    int n,s;
    cin>>n>>s;
    vector<int>N1=gsn(n,s);
    vector<int>N2=ggn(n,s);
    if(N1[0]==-1 || N2[0]==-1){
        cout<<-1<<" "<<-1<<endl;
        return;
    }
    for(auto it:N1)cout<<it;
    cout<<" ";
    for(auto it:N2)cout<<it;
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