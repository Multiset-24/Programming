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
/*
kon kon greet kar skta hai 
maanlo 2 log hai 
a1----b1
a2----b2

case1:
    a1<a2 and b1<b2 kbhi greet nhi karenge
case2:
    a1<a2 and b1>b2 greet karenge
    
    approach: segments ko a ke basis pe sort karlo ab dekho har ek b ko iterate karo now from after sorting har bi ke liy tumhe pichhe dhudne hai kitne bj hai such that j<i and bj>bi kyuki jo pehle aj cover hue hai vo to ai ke pehle hi shuru hue honge since sorting hui thi so agr bj>bi count kia to total segments mil jayga jo ai-bi ko fully cover karenge , jo hum inversion count se nikal sakte hai jo ki segment tree se nikala jaa skta hai 

    Main approach -> Total Inversion count = Total greetings 

    Inversion count -> first map the all b's with numbers from 0 to n-1 such that it forms permutation now build a segment tree of query type range sum , now jb jb ek point ko cover karo then uss point se lekr n tk array mai sum nikal lo jisse ki previosly visited jo bj jo bi se bade hai vo aajayenge then bi update kardo in array 
*/

class segment_tree{
    private:
        vector<int>arr;
        vector<int>tree;
    public:
        segment_tree(int n){
            arr.assign(n,0);
            tree.resize(4*n+1,0);
        }
        void update(int root,int l,int r,int pos,int v){
            if(pos<l || pos>r)return ;

            if(l==r){
                tree[root]=v;
                arr[l]=v;
                return;
            }

            int mid=l+(r-l)/2;

            update(2*root+1,l,mid,pos,v);
            update(2*root+2,mid+1,r,pos,v);

            tree[root]=tree[2*root+1]+tree[2*root+2];

            return;
        }

        int query_sum(int root,int l,int r,int lq,int rq){
            if(lq>r || l>rq){
                return 0;
            }

            if(lq<=l && r<=rq){
                return tree[root];
            }

            int mid=l+(r-l)/2;

            return query_sum(2*root+1,l,mid,lq,rq)+query_sum(2*root+2,mid+1,r,lq,rq);
        }
};
void jarvis()
{
    int n;
    cin>>n;
    vector<pair<int,int>>sgmts;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        sgmts.push_back({a,b});
    }
    sort(sgmts.begin(),sgmts.end(),[&](pair<int,int>a,pair<int,int>b){
        return a.first<b.first;
    });
    vector<int>temp;
    for(int i=0;i<n;i++)temp.push_back(sgmts[i].second);
    map<int,int>mp;
    sort(temp.begin(),temp.end());
    for(int i=0;i<n;i++){
        mp[temp[i]]=i;
    }
    vector<int>b;
    for(int i=0;i<n;i++)b.push_back(mp[sgmts[i].second]);
    int cnt=0;
    segment_tree sgmt_tree(n);
    for(int i=0;i<n;i++){
        cnt+=sgmt_tree.query_sum(0,0,n-1,b[i],n-1);
        sgmt_tree.update(0,0,n-1,b[i],1);
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