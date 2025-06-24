#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define int long long
#define endl '\n'

int n;
vector<int> dimentions;
int dp[505][505];
int cut[505][505];
vector<int> open_brackets, close_brackets;

int solve(int l, int r) {
    if (l == r) return 0;

    if (dp[l][r] != -1) return dp[l][r];

    int ans = 1e12;
    for (int p = l; p < r; p++) {
        int cost = solve(l, p) + solve(p + 1, r) + dimentions[l-1] * dimentions[p] * dimentions[r];
        if (cost < ans) {
            ans = cost;
            cut[l][r] = p;
        }
    }

    return dp[l][r] = ans;
}

void calculateBrackets(int l, int r) {
    if (l == r) return;

    int p = cut[l][r];
    open_brackets[l]++;
    close_brackets[r]++;

    calculateBrackets(l, p);
    calculateBrackets(p + 1, r);
}

void printSolution() {
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < open_brackets[i]; j++) cout << "(";
        cout <<i;
        for (int j = 0; j < close_brackets[i]; j++) cout << ")";
    }
    cout << endl;
}

void jarvis() {
    cin >> n;
    dimentions.resize(n + 1);
    open_brackets.assign(n+1, 0);
    close_brackets.assign(n+1, 0);

    for (int i = 0; i <= n; i++) {
        cin >> dimentions[i];
    }

    memset(dp, -1, sizeof(dp));
    memset(cut, -1, sizeof(cut));

    cout << "Minimum cost: " << solve(1, n ) << endl;
    calculateBrackets(1, n);
    cout << "Optimal parenthesization: ";
    printSolution();
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q = 1;
    while (q--) {
        jarvis();
    }
    return 0;
}
