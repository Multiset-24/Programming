#include <bits/stdc++.h>
 
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int ans = 1, cur = 1;
        for(int i = 1; i < n; i++)
        {
            if(s[i] != s[i - 1]) cur = 1;
            else cur++;
            ans = max(ans, cur);
        }
        cout << ans + 1 << endl;
    }    
}