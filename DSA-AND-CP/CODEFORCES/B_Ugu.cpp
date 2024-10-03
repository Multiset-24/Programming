#include <bits/stdc++.h>
using namespace std;
 
int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    string s;
    cin >> n >> s;
    int ans = 0;
    for (int i = 0; i+1 < n; i++) {
      ans += s[i] != s[i+1];
    }
    if (s[0] == '0' && ans >= 1) ans--;
    cout << ans << '\n';
  }
}