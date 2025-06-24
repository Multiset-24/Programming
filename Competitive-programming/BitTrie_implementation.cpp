#include <bits/stdc++.h>
using namespace std;

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

struct node {
    node* bit[2];
    int cnt;
    node() {
        bit[0] = nullptr;
        bit[1] = nullptr;
        cnt = 0;
    }
};

class bitTrie {
private:
    node* root;
    int L = 60;

public:
    bitTrie() {
        root = new node;
    }

    void insert(int n) {
        node* curr = root;

        for (int i = L; i >= 0; i--) {
            curr->cnt++;
            int b = ((n >> i) & 1);
            if (curr->bit[b] != nullptr) {
                curr = curr->bit[b];
            } else {
                node* newNode = new node;
                curr->bit[b] = newNode;
                curr = curr->bit[b];
            }
        }
        curr->cnt++;
    }

    bool search(int n) {
        node* curr = root;

        for (int i = L; i >= 0; i--) {
            int b = ((n >> i) & 1);
            if (curr->bit[b] != nullptr) {
                curr = curr->bit[b];
            } else {
                return false;
            }
        }
        return true;
    }

    void remove(int n) {
        if (!search(n)) return;

        node* curr = root;
        for (int i = L; i >= 0; i--) {
            int b = ((n >> i) & 1);

            node* next = curr->bit[b];

            if (--next->cnt == 0) {
                delete next;
                curr->bit[b] = nullptr;
                return;
            }

            curr = next;
        }
    }
};

void jarvis() {
    bitTrie b1;
    
    // Test Insert Operation (Type 1)
    b1.insert(1);
    b1.insert(0);
    b1.insert(17283283);
    b1.insert(INT_MAX);
    
    // Test Search Operation (Type 2)
    cout << "Search 1: " << b1.search(1) << endl;          // Should return true
    cout << "Search INT_MAX: " << b1.search(INT_MAX) << endl;  // Should return true
    cout << "Search 0: " << b1.search(0) << endl;          // Should return true
    cout << "Search 17283283: " << b1.search(17283283) << endl; // Should return true
    
    // Test Remove Operation (Type 3)
    b1.remove(INT_MAX);
    cout << "Search INT_MAX after remove: " << b1.search(INT_MAX) << endl; // Should return false
    b1.remove(0);
    cout << "Search 0 after remove: " << b1.search(0) << endl;  // Should return false
    
    // Test the case when trying to remove an element that is not in the trie
    b1.remove(99999);  // No effect
    cout << "Search 99999: " << b1.search(99999) << endl;  // Should return false
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q = 1;
    // cin >> q;
    while (q--) {
        jarvis();
    }
    return 0;
}
