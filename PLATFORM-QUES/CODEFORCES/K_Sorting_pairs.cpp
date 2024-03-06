#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define int long long
typedef pair<int,int> pi;
#define u_mp unordered_map 
#define u_st unordered_set 
#define p_qu priority_queue
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

class cmp{
    public:
    bool operator ()(pair<string,int>&p1,pair<string,int>&p2){
            if(p1.second==p2.second)
                return p1.first>p2.first;
            else
                return p1.second<p2.second;
    }
};
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int x;
    cin>>x;

    p_qu<pair<char,int>,vector<pair<string,int>>,cmp>user_data;

    while(x--){
        string name;
        int salary;
        read(name,salary);
        user_data.push({name,salary});
    }

    while(user_data.size()){
        cout<<user_data.top().first<<" "<<user_data.top().second<<endl;
        user_data.pop();
    }
    return 0;
}