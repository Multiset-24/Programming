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
    Hinglish Tutorial for Div2C 1030
    suppose a[i]=0 and  k=6
    kb tk hum badha skte hai like 0->1->3->7->9->15->31->63->127..... ab har transition mai kitne baar operation perform karne pdenge ye find karna hai 

    0->1 1 operation required
    1->11 1->2->3 2 operation needed
    11->111 3->4->5->6->7 4 operations needed 
    111->1111 7->8->9->10->11->....->15 8 operation needed 

    suppose we start with 4 
    100->101 1 operation mai hoga 
    101->111 2 operation mai hoga 
    
    hence ek a[i] ke liy hume (~x)&(x+1) operation needed honge basically ye first zero ki digit ko 1 kardeta hai baaki sb ko 0 jo ki number of operations hai 

    thus har number ke liy hum count karenge ki at max kinte 1 bdha skte hai with in k operations .

    then ek array bnao B jisme Bi ka mtlb hai 1 one bdhane ke liy kitna operation lega phir isko sort kardo then just gain count karlo operation minus karte karte
*/
void jarvis()
{
    int n,k;
    cin>>n>>k;
    vector<int>a(n);
    int def=0;
    for(auto &x:a){
        cin>>x;
        int cnt=0;
        for(int i=0;i<60;i++){
            if((x>>i)&1)cnt++;
        }
        def+=cnt;
    }
    vector<int>opr;
    for(int i=0;i<n;i++){
        int x=a[i];
        while(true){
            int t=(~x&(x+1));
            if(t==0 || t>k)break;
            opr.push_back(t);
            x+=t;
        }
    }
    sort(opr.begin(),opr.end());
    for(auto c:opr){
        if(c>k)break;
        k-=c;
        def++;
    }
    cout<<def<<endl;
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