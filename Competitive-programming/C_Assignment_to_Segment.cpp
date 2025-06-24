#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define int long long
// Debugging macro
#ifndef ONLINE_JUDGE
#define DEBUG
#endif

#ifdef DEBUG
#define print_vector(v)          \
    {                            \
        cout << #v << " = [";    \
        for (auto &elem : v)     \
            cout << elem << " "; \
        cout << "]" << endl;     \
    }
#define print_map(m)                                                  \
    {                                                                 \
        cout << #m << " = {";                                         \
        for (auto &pair : m)                                          \
            cout << "{" << pair.first << ": " << pair.second << "} "; \
        cout << "}" << endl;                                          \
    }
#define print_2dvector(v)             \
    {                                 \
        cout << #v << " = [" << endl; \
        for (auto &row : v)           \
        {                             \
            cout << "  [";            \
            for (auto &elem : row)    \
                cout << elem << " ";  \
            cout << "]" << endl;      \
        }                             \
        cout << "]" << endl;          \
    }
#else
#define print_vector(v)
#define print_map(m)
#define print_2dvector(v)
#endif
#define endl '\n'

// Each node stores the current value of the entire segment it represents,
// and a lazy flag that indicates that the node's children should be updated.
struct node {
    int val = 0;
    bool lazy = false;  // true means "this node has a pending assignment update"
    node(int a) : val(a) {}
};

class sgtmodified {
private:
    vector<int> arr;
    vector<node> tree;

public:
    // Constructor: we copy the initial array and allocate the segment tree
    sgtmodified(vector<int> &arr) {
        this->arr = arr;
        node init(0);
        tree.assign(4 * (int)arr.size() + 1, init);
    }
    
    // push_down propagates a lazy update from the current node (root)
    // to its two children if the current segment is not a leaf.
    void push_down(int root, int l, int r) {
        if (!tree[root].lazy)
            return;
        if (l == r)  // leaf node; nothing to propagate
            return;
        int mid = (l + r) >> 1;
        // Propagate the assignment update to the left child (segment [l, mid])
        tree[2 * root + 1].val = tree[root].val;
        tree[2 * root + 1].lazy = true;
        // Propagate to the right child (segment [mid+1, r])
        tree[2 * root + 2].val = tree[root].val;
        tree[2 * root + 2].lazy = true;
        // Clear the lazy flag at the current node
        tree[root].lazy = false;
    }
    
    // Update the segment tree in the current segment [l, r] so that every element
    // in the query range [lq, rq] is assigned the value v.
    void update(int root, int l, int r, int lq, int rq, int v) {
        // No overlap
        push_down(root, l, r);
        if (r < lq || l > rq)
            return;
        
        // Total overlap: current segment [l, r] lies completely inside [lq, rq].
        if (l >= lq && r <= rq) {
            tree[root].val = v;
            tree[root].lazy = true;
            return;
        }
        
        // Partial overlap: first propagate any pending update
        int mid = (l + r) >> 1;
        update(2 * root + 1, l, mid, lq, rq, v);
        update(2 * root + 2, mid + 1, r, lq, rq, v);
        // (For assignment queries with only point queries later, merging is not required.
        //  If you need to answer range queries, you'll have to combine the results from
        //  the children appropriately here.)
    }
    
    // Query the value at index i in the array.
    int query(int root, int l, int r, int i) {
        // If the current segment does not contain i, return a default (should not happen)
        if (i < l || i > r)
            return 0;
        // If we are at a leaf, return the stored value.
        if (l == r) {
            return tree[root].val;
        }
        // Ensure that any pending updates are pushed down before moving deeper.
        push_down(root, l, r);
        int mid = (l + r) >> 1;
        if (i <= mid)
            return query(2 * root + 1, l, mid, i);
        else
            return query(2 * root + 2, mid + 1, r, i);
    }
};

void jarvis() {
    int n, q;
    cin >> n >> q;
    
    // Initially, all elements are 0.
    vector<int> num(n, 0);
    // Build the segment tree over the array.
    sgtmodified seg(num);
    
    while (q--) {
        int t;
        cin >> t;
        // Query type 1: range update (assignment)
        if (t == 1) {
            int lq, rq, v;
            cin >> lq >> rq >> v;
            // Assuming 0-indexed input; update indices [lq, rq] to value v.
            seg.update(0, 0, n - 1, lq, rq-1, v);
        }
        // Query type 2: point query
        else {
            int i;
            cin >> i;
            cout << seg.query(0, 0, n - 1, i) << endl;
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--) {
        jarvis();
    }
    return 0;
}
