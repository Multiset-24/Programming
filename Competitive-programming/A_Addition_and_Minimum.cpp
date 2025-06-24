#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define int long long
// Debugging macros (you can ignore these if not debugging)
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

const int inf = 1e10;

// Each node stores the minimum value in its segment and a lazy value (pending update)
struct node {
    int minm; // the minimum value in the segment
    int lazy; // pending addition that hasn't been pushed down
    node(int m = 0, int l = 0) : minm(m), lazy(l) {}
};

class modifiedsgt {
private:
    vector<node> tree;
    int n; // size of the original array
public:
    modifiedsgt(int n) {
        this->n = n;
        // allocate enough space for the segment tree (4*n is safe)
        tree.resize(4 * n, node(0, 0));
    }
    
    // Push down the lazy update from node 'idx' to its children.
    void pushDown(int idx, int start, int end) {
        if (tree[idx].lazy != 0 && start != end) { // non-zero lazy value and not a leaf
            int mid = (start + end) / 2;
            // Left child (index 2*idx)
            tree[2 * idx].minm += tree[idx].lazy;
            tree[2 * idx].lazy += tree[idx].lazy;
            // Right child (index 2*idx+1)
            tree[2 * idx + 1].minm += tree[idx].lazy;
            tree[2 * idx + 1].lazy += tree[idx].lazy;
            // Clear lazy value in current node after propagation
            tree[idx].lazy = 0;
        }
    }
    
    // Update the range [l, r] (inclusive) by adding 'value'
    void updateRange(int idx, int start, int end, int l, int r, int value) {
        // No overlap
        if (r < start || l > end)
            return;
        // Complete overlap
        if (l <= start && end <= r) {
            tree[idx].minm += value;
            tree[idx].lazy += value;
            return;
        }
        // Partial overlap: first push down any pending updates
        pushDown(idx, start, end);
        int mid = (start + end) / 2;
        updateRange(2 * idx, start, mid, l, r, value);
        updateRange(2 * idx + 1, mid + 1, end, l, r, value);
        // Update current node from children
        tree[idx].minm = min(tree[2 * idx].minm, tree[2 * idx + 1].minm);
    }
    
    // Query the minimum in the range [l, r] (inclusive)
    int queryRange(int idx, int start, int end, int l, int r) {
        // No overlap
        if (r < start || l > end)
            return inf;
        // Complete overlap
        if (l <= start && end <= r)
            return tree[idx].minm;
        // Partial overlap: push down pending updates before recursing
        pushDown(idx, start, end);
        int mid = (start + end) / 2;
        int leftMin = queryRange(2 * idx, start, mid, l, r);
        int rightMin = queryRange(2 * idx + 1, mid + 1, end, l, r);
        return min(leftMin, rightMin);
    }
};

void jarvis() {
    int n, m;
    cin >> n >> m;
    
    // Create the segment tree for an array of n elements (all initially zero)
    modifiedsgt segTree(n);
    
    // Process m queries
    while (m--) {
        int type;
        cin >> type;
        if (type == 1) {
            // Query type 1: range addition update.
            // Input: 1 l r v  --> add v to all elements in [l, r-1]
            int l, r, v;
            cin >> l >> r >> v;
            segTree.updateRange(1, 0, n - 1, l, r - 1, v);
        } else {
            // Query type 2: range minimum query.
            // Input: 2 l r  --> find min on segment [l, r-1]
            int l, r;
            cin >> l >> r;
            int ans = segTree.queryRange(1, 0, n - 1, l, r - 1);
            cout << ans << endl;
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    // For problems with multiple test cases, uncomment the next line:
    // cin >> t;
    while (t--) {
        jarvis();
    }
    return 0;
}
