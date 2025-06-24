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

int f1(int a,int b,int c){
    int x=min({a,b,c});
    return x+((a-x)/3)+((b-x)/3)+((c-x)/3);
}
int f2(int a,int b,int c){
    return (a/3)+(b/3)+min({a%3,b%3,c});
}
int f3(int a,int b,int c){
    return (a/3)+(b/3)+(c/3)+min({a%3,b%3,c%3});
}
int f4(int a,int b,int c){
    int x=min({a%3,b,c});
    return a/3+(x+(b-x)/3+(c-x)/3);
}
void jarvis()
{
    int a,b,c;
    cin>>a>>b>>c;
    cout<<max({f1(a,b,c),f2(a,b,c),f2(a,c,b),f2(b,a,c),f2(b,c,a),f2(c,a,b),f2(c,b,a),f3(a,b,c),f4(a,b,c),f4(b,c,a),f4(c,a,b)})<<endl;
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