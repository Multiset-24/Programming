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

int n;
char grid[n][n];
string R,C;
map<int,char>mp;
char choices[4]={'A','B','C','.'};

int check(int i,int j,char ch){

}
void rec(int i,int j){
    if(i==n){
        return ;
    }
    else if(j==n){
        return rec(i+1,0);
    }

    for(int choice=0;choice<4;choice++){
        char ch=mp[choice];
        if(ch!='.' && check(i,j,ch)){
            grid[i][j]=ch;
            rec(i,j+1);
            grid[i][j]='.';
        }
    }
}
void jarvis()
{
    cin>>n;

    cin>>R>>C;

    memset(grid,'.',sizeof(grid));

    for(int i=0;i<4;i++){
        mp[i]=choices[i];
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