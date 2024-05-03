#include <bits/stdc++.h>
using namespace std;
// implimentation of DSU
// approach 1..
class disjoint_set_1
{
    vector<int> parent;
public:
    disjoint_set_1(int n) {
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int _find(int x) {
        if (parent[x] != x) {
            parent[x] = _find(parent[x]); // Path compression
        }
        return parent[x];
    }

    void _union(int a, int b) {
        int root_a = _find(a);
        int root_b = _find(b);

        if (root_a != root_b) {
            parent[root_b] = root_a;
        }
    }
};

#define mod 1000000007

int main() {
    disjoint_set_1 ds(6);

    cout << ds._find(2) << endl;

    ds._union(0, 2);

    cout << ds._find(2) << endl;

    ds._union(5, 2);

    cout << ds._find(2) << endl;

    return 0;
}
