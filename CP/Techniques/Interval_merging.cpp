#include <bits/stdc++.h>
using namespace std;
//address on leeetcode: https://leetcode.com/problems/merge-intervals/
#define mod 1000000007
#define int long long
typedef pair<int,int> pi;
#define u_mp unordered_map 
#define u_st unordered_set 
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

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    read(n);
    vector<pi> intervals(n);// Vector of pairs to store the intervals
    for(int i = 0; i < n; i++) {
        int x, y;
        read(x, y);
        intervals[i] = {x, y};
    }

    sort(intervals.begin(), intervals.end());// Sort the intervals based on the first element of the pair

    vector<pi> merged_intervals;


    for(int i = 0; i < n; i++) {
        int start = intervals[i].first;
        int end = intervals[i].second;

        while(i < n - 1 && intervals[i + 1].first <= end) {
            end = max(end, intervals[i + 1].second);
            i++;
        }

        merged_intervals.push_back({start, end});
    }

    for(auto interval: merged_intervals) {
        cout << interval.first << " " << interval.second << endl;
    }
    return 0;
}