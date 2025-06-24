#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int MAX_N = 100;
const int MAX_MASK = 1 << 17;

int n;
vector<int> a;
vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59};
vector<int> x_masks(60, 0); // Bitmask for each x (1-59)
vector<vector<int>> dp(MAX_N, vector<int>(MAX_MASK, -1)); // Memoization table
vector<vector<pair<int, int>>> parent(MAX_N, vector<pair<int, int>>(MAX_MASK, {-1, -1})); // For reconstruction

// Precompute bitmask for each x (1-59)
void precompute_masks() {
    for (int x = 1; x < 60; ++x) {
        int mask = 0;
        for (int i = 0; i < primes.size(); ++i) {
            if (x % primes[i] == 0) {
                mask |= (1 << i);
            }
        }
        x_masks[x] = mask;
    }
}

// Recursive DP function
int solve(int i, int mask) {
    if (i == n) return 0; // Base case: no more elements to process
    if (dp[i][mask] != -1) return dp[i][mask]; // Return memoized result

    int min_cost = INF;
    for (int x = 1; x < 60; ++x) {
        int xm = x_masks[x];
        if ((mask & xm) != 0) continue; // Skip if primes overlap
        int new_mask = mask | xm;
        int cost = abs(a[i] - x) + solve(i + 1, new_mask);
        if (cost < min_cost) {
            min_cost = cost;
            parent[i][mask] = {x, new_mask}; // Store parent for reconstruction
        }
    }
    return dp[i][mask] = min_cost; // Memoize and return
}

// Reconstruct the sequence b
vector<int> reconstruct() {
    vector<int> b;
    int mask = 0;
    for (int i = 0; i < n; ++i) {
        int x = parent[i][mask].first;
        int new_mask = parent[i][mask].second;
        b.push_back(x);
        mask = new_mask;
    }
    return b;
}

int main() {
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    precompute_masks(); // Precompute bitmasks for all x (1-59)
    int min_cost = solve(0, 0); // Start DP from the first element and empty mask
    vector<int> b = reconstruct(); // Reconstruct the sequence b

    // Output the sequence b
    for (int x : b) cout << x << " ";
    cout << endl;

    return 0;
}