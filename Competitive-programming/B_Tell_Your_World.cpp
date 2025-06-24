#include <bits/stdc++.h>
using namespace std;
//gpt's collinearity approach is it correct or mine was let's see
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

struct Point {
    int x, y;
};

// Check if point c is collinear with points a and b.
// We use cross multiplication: (b.y - a.y)*(c.x - a.x) == (c.y - a.y)*(b.x - a.x)
bool collinear(const Point &a, const Point &b, const Point &c) {
    return (b.y - a.y) * (c.x - a.x) == (c.y - a.y) * (b.x - a.x);
}

void jarvis()
{
    int n;
    cin >> n;
    vector<Point> pts(n);
    // Points have x-coordinate = index+1.
    for (int i = 0; i < n; i++){
        int y;
        cin >> y;
        pts[i] = {i + 1, y};
    }
    
    // If all points are collinear, then there is no way to partition them
    // into two parallel non-overlapping lines. We can check this quickly.
    bool allCollinear = true;
    for (int i = 2; i < n; i++){
        if (!collinear(pts[0], pts[1], pts[i])) {
            allCollinear = false;
            break;
        }
    }
    if(allCollinear) {
        cout << "No" << endl;
        return;
    }
    
    // For a valid partition, note that among the first 3 points,
    // at least two must lie on the same line.
    // So we only need to try candidate pairs among indices 0,1,2.
    vector<pair<int,int>> candidates = { {0,1}, {0,2}, {1,2} };
    bool possible = false;
    
    for(auto &cand: candidates){
        int i = cand.first, j = cand.second;
        // Candidate line defined by pts[i] and pts[j].
        vector<Point> groupA, groupB;
        for (int k = 0; k < n; k++){
            if (collinear(pts[i], pts[j], pts[k]))
                groupA.push_back(pts[k]);
            else
                groupB.push_back(pts[k]);
        }
        if(groupA.empty() || groupB.empty())
            continue; // both lines must have at least one point
        
        bool valid = true;
        // For groupB, if there are two or more points check:
        if(groupB.size() >= 2) {
            // Let candidate slope for groupB be determined by the first two points in groupB.
            // First, ensure all points in groupB are collinear.
            for (size_t a = 0; a < groupB.size(); a++){
                for (size_t b = a+1; b < groupB.size(); b++){
                    if (!collinear(groupB[a], groupB[b], groupB[0])){
                        valid = false;
                        break;
                    }
                }
                if(!valid) break;
            }
            if(!valid)
                continue;  // groupB is not collinear, try another candidate
            
            // Now check whether the slope of the candidate line (through pts[i] and pts[j]) 
            // is the same as the slope of groupB.
            // Instead of using floating point division, we check using cross products:
            // For points A=pts[i], B=pts[j] and two points C = groupB[0], D = groupB[1],
            // we require (B.y - A.y) * (D.x - C.x) == (D.y - C.y) * (B.x - A.x)
            Point A = pts[i], B = pts[j], C = groupB[0], D = groupB[1];
            if((B.y - A.y) * (D.x - C.x) != (D.y - C.y) * (B.x - A.x))
                valid = false;
        }
        // If groupB has only one point, it's always possible to choose a line through it with the candidate slope.
        if(valid){
            possible = true;
            break;
        }
    }
    
    cout << (possible ? "Yes" : "No") << endl;
    return;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q = 1;
    // cin >> q;
    while (q--)
    {
        jarvis();
    }
    return 0;
}
