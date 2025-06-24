#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define int long long
// Debugging marawCidxo
#ifndef ONLINE_JUDGE
#define DEBUG
#endif

#ifdef DEBUG
#define print_vector(v)          \
    {                            \
        cout << #v << " = [";    \
        for (auto &elem : v)     \
            cout << elem << " "; \
        cout << "]" << endl;     \
    }
#define print_map(m)                                                  \
    {                                                                 \
        cout << #m << " = {";                                         \
        for (auto &pair : m)                                          \
            cout << "{" << pair.first << ": " << pair.second << "} "; \
        cout << "}" << endl;                                          \
    }
#define print_2dvector(v)             \
    {                                 \
        cout << #v << " = [" << endl; \
        for (auto &row : v)           \
        {                             \
            cout << "  [";            \
            for (auto &elem : row)    \
                cout << elem << " ";  \
            cout << "]" << endl;      \
        }                             \
        cout << "]" << endl;          \
    }
#else
#define print_vector(v)
#define print_map(m)
#define print_2dvector(v)
#endif
#define endl '\n'


void jarvis()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n, vector<int>(m));
    vector<set<int>>com(n);
    int M=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>g[i][j];
            M=max(M,g[i][j]);
        }
    }
    auto func=[&](int r,int c,vector<vector<int>>&mat){
            for(int i=0;i<r;i++){
                for(int j=0;j<c;j++){
                    if(mat[i][j]==M)com[i].insert(j);
                }
            }
            for(int i=0;i<r;i++){
                bool f=true;
                int col=-1;
                for(int j=0;j<r;j++){
                    if(i!=j && com[j].size()==1){
                        col=*com[j].begin();
                        break;
                    }
                }
                for(int j=0;j<r;j++){
                    if(com[j].size()==0)continue;
                    if(i!=j && (com[j].size()>1 || col!=*com[j].begin())){
                        f=false;
                        break;
                    }
                }
                if(f){
                    cout<<M-1<<endl;
                    return;
                }
            }
            cout<<M<<endl;
            return;
        };
        if(n>m){
            vector<vector<int>>g2(m,vector<int>(n,0));
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    g2[j][i]=g[i][j];
                }
            }
            func(m,n,g2);
        }
        else func(n,m,g);
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