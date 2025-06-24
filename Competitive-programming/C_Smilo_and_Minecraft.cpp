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
    Hinglish tutorial:
        So agr hum question ko twist kare to ye kehna galat nhi hoga ki hum ammount of gold jo waste ho usko minimise karna chahte hai jo ki har blast ki range mai aayga i.e a square of (k-1)*(k-1) baaki boundary vale hum collect karlenge

        Now ek observation ye hai ki agr humne pehla blast  karlia aur usme x ammount of gold khoya then baaki bacha hua gold hum utha skte hai kyun ab minimum to minimum agr k ki value 1 bhi k*k square ke radius mai sb khali ho jayga wether waste hoga ya collect hoga 
        now hum agr prev blast se ek direction shift karte hai then ek boundary side extend hogi aur jitna bhi uss boundary pe hoga usse hum collect kar skte hai thus aese hi baaki saare collect kar skte hai hence 

        Question convert hojaata hai to -> minimise the waste of gold on first blast 
        
        to minimise wastage on first blast we some how have to iterate overall all cell and calculate the wastage for each individual cell in range 
        [x1,y1]=(max(1LL,i-k),max(1LL,j-k))->[x2,y2]=(min(n,i+k),min(m,j+k))

        the range sum can be calculated using 2d prefix sum concept which we have already studied.
*/
void jarvis()
{
    int n,m,k;
    cin>>n>>m>>k;
    k--;
    vector<vector<char>>g(n+1,vector<char>(m+1,'#'));
    int cnt=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>g[i][j];
            cnt+=(g[i][j]=='g');
        }
    }
    vector<vector<int>>p2d(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            p2d[i][j]=(g[i][j]=='g')+p2d[i-1][j]+p2d[i][j-1]-p2d[i-1][j-1];
        }
    }
    auto gs=[&](int x1,int y1,int x2,int y2){
        return p2d[x2][y2]-p2d[x1-1][y2]-p2d[x2][y1-1]+p2d[x1-1][y1-1];
    };
    int wst=1e15;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(g[i][j]=='#' || g[i][j]=='g')continue;
            int x1=max(1LL,i-k),y1=max(1LL,j-k),x2=min(n,i+k),y2=min(m,j+k);
            wst=min(wst,gs(x1,y1,x2,y2));
        }
    }
    cout<<cnt-wst<<endl;
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