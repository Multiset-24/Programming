#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define int long long
typedef pair<int,int> pi;
#define u_mp unordered_map 
#define u_st unordered_set 
template<typename T>

// Function templates for reading input
void read(T& t) {
    cin >> t;
}
template<typename T, typename... Args>
void read(T& t, Args&... args) {
    cin >> t;
    read(args...);
}

// Debugging macro
#define DEBUG
#ifdef DEBUG
#define debug(x) cout << #x << " = " << x << endl
#else
#define debug(x)
#endif

#define endl '\n'

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int q;
    read(q);
    
        end:
    while(q--){
        int n,c,d;
        read(n,c,d);

        int minm=INT_MAX;
        u_mp<int,int> s;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                int x;
                read(x);
                s[x]++;
                if(x<minm){
                    minm=x;
                }
            }
        }

        vector<vector<int>> v(n,vector<int>(n,0));
        v[0][0]=minm;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0){
                    continue;
                }
                else if(j==0){
                    v[i][j]=v[i-1][j]+c;
                }else{
                    v[i][j]=v[i][j-1]+d;
                }
            }
        }
        bool flag=true;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){

                if(s.find(v[i][j])==s.end()){
                    cout<<"NO"<<endl;
                    flag=false;
                    break;
                }
                else{
                    
                    s[v[i][j]]--;
                    if(s[v[i][j]]==0){
                        s.erase(v[i][j]);
                    }
                    }
            }
            if(flag==false){
                break;
            }
        }
        if(flag==true)cout<<"YES"<<endl;
    }
    return 0;
}