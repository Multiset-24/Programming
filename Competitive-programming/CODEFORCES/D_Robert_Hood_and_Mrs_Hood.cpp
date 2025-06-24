#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pi;
#define endl '\n'

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

void jarvis()
{
    int n, d, k;
    cin >> n >> d >> k;

    vector<pair<int, int>> J(k);

    for (int i = 0; i < k; i++) {
        cin >> J[i].first >> J[i].second;
    }
    int maxoverlap = 0, minoverlap = k + 1;
    int bb = 1, bm = 1;

   
    vector<int> overlap_count(n + 2, 0);


    for (auto& naukri : J) {
      
        int start_overlap = max(1LL, naukri.first - d + 1);
        int end_overlap = min(n - d + 1, naukri.second);

        if (start_overlap <= end_overlap) {
            overlap_count[start_overlap]++;
            if (end_overlap + 1 <= n - d + 1) {
                overlap_count[end_overlap + 1]--;
            }
        }
    }


    int current_overlap = 0;
    for (int i = 1; i <= n - d + 1; i++) {
        current_overlap += overlap_count[i];


        if (current_overlap > maxoverlap) {
            maxoverlap = current_overlap;
            bb = i;
        }

        if (current_overlap < minoverlap) {
            minoverlap = current_overlap;
            bm = i;
        }
    }

    cout << bb << " " << bm << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    cin >> q;
    while (q--) {
        jarvis();
    }
    return 0;
}
