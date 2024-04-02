#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define int long long
typedef pair<int, int> pi;
#define u_mp unordered_map
#define u_st unordered_set
template <typename T>

// Function templates for reading input
void read(T &t)
{
    cin >> t;
}
template <typename T, typename... Args>
void read(T &t, Args &...args)
{
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

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int total_sum = 0;
    int n;
    read(n);
    u_mp<int, int> mp;
    vector<int> num(n + 1);
    for (int i = 1; i <= n; i++)
    {
        read(num[i]);
        total_sum += num[i];
        mp[num[i]]++;
    }

    vector<int> ans;
    for(int i=1;i<=n;i++){
        int sum=total_sum-num[i];
        if(sum%2==0){
            if(mp.find(sum/2)!=mp.end()){
                if(sum/2!=num[i] || mp[num[i]]>1){
                    ans.push_back(i);
                }
            }
        }
    }

    cout << ans.size() << endl;
    for (auto x : ans)
    {
        cout << x << " ";
    }

    return 0;
}
