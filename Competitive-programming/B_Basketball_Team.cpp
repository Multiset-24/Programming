#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

double nCr(int n, int r) {
    if (r > n || r < 0) return 0; 
    double res = 1;
    for (int i = 0; i < r; i++) {
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}

void jarvis() {
    int n, m, h;
    cin >> n >> m >> h;
    
    vector<int> s(m + 1);
    int totalPlayers = 0;
    
    for (int i = 1; i <= m; i++) {
        cin >> s[i];
        totalPlayers += s[i];
    }

    int sh = s[h]; 

    if (totalPlayers < n) {
        cout << -1 << endl;
        return;
    }

    if (sh == 1) {
        cout << 0.0 << endl;
        return;
    }

    double totalWays = nCr(totalPlayers - 1, n - 1);
    double badWays = nCr(totalPlayers - sh, n - 1);
    double probability = 1.0 - (badWays / totalWays);

    cout << fixed << setprecision(6) << probability << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    jarvis();
    return 0;
}
