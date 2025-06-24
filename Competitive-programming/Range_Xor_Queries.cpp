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

class segment_tree
{
private:
    vector<int> arr;
    vector<int> tree;

public:
    segment_tree(vector<int> &num)
    {
        arr = num;
        tree.resize(4 * num.size() + 1, 0);
    }

    void build(int root, int l, int r)
    {
        if (l == r)
        {
            tree[root] = arr[l];
            return;
        }

        int mid = l + (r - l) / 2;

        build(2 * root + 1, l, mid);
        build(2 * root + 2, mid + 1, r);

        tree[root] = tree[2 * root + 1] + tree[2 * root + 2]; // this merge logic is correct for 0 indexed only

        return;
    }

    void update(int root, int l, int r, int pos, int v)
    {
        if (pos < l || pos > r)
            return;

        if (l == r)
        {
            tree[root] = v;
            arr[l] = v;
            return;
        }

        int mid = l + (r - l) / 2;

        update(2 * root + 1, l, mid, pos, v);
        update(2 * root + 2, mid + 1, r, pos, v);

        tree[root] = tree[2 * root + 1] + tree[2 * root + 2];

        return;
    }

    int query_xor_sum(int root, int l, int r, int lq, int rq)
    {
        if (lq > r || l > rq)
        {
            return 0;
        }

        if (lq <= l && r <= rq)
        {
            return tree[root];
        }

        int mid = l + (r - l) / 2;

        return query_xor_sum(2 * root + 1, l, mid, lq, rq) + query_xor_sum(2 * root + 2, mid + 1, r, lq, rq);
    }

    void print()
    {
        for (int i = 0; i <= 4 * arr.size(); i++)
        {
            cout << tree[i] << " ";
        }
    }
};
void jarvis()
{
    int n, q;
    cin >> n >> q;

    vector<int> arr(n, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    segment_tree sgt(arr);
    sgt.build(0, 0, n - 1);

    while (q--)
    {
        int t;
        cin >> t;

        if (t == 2)
        {
            int l, r;
            cin >> l >> r;
            l--, r--;
            cout << sgt.query_xor_sum(0, 0, n - 1, l, r) << endl;
        }
        else{
            int k,v;
            cin>>k>>v;
            k--;
            sgt.update(0,0,n-1,k,v);
        }
    }
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