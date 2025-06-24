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
    int a,b;
    cin>>a>>b;
    int a2=0,a3=0,a5=0,b2=0,b3=0,b5=0,x=0,y=0;
    while(a%2==0 || b%2==0){
        if(a%2==0){
            a2++;
            a/=2;
        }
        if(b%2==0){
            b2++;
            b/=2;
        }
    }    
    while(a%3==0 || b%3==0){
        if(a%3==0){
            a3++;
            a/=3;
        }
        if(b%3==0){
            b3++;
            b/=3;
        }
    }  
    while(a%5==0 || b%5==0){
        if(a%5==0){
            a5++;
            a/=5;
        }
        if(b%5==0){
            b5++;
            b/=5;
        }
    }  
    if(a!=b){
        cout<<-1<<endl;
    }
    else {
        cout<<abs(a2-b2)+abs(a3-b3)+abs(a5-b5)<<endl;
    }
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