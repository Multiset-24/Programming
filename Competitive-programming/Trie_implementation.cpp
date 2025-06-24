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
    node* child[26];
    vector<string> words;
    int prefix;
    bool isEnd;

    node() {
        prefix = 0;
        for (int i = 0; i < 26; i++) child[i] = nullptr;
        isEnd = false;
    }
};

class trie {
    node* root;
public:
    trie() {
        root = new node;
    }
    void insert(string s) {
        node* curr = root;

        for (auto c : s) {
            int idx = c - 'a';
            curr->prefix++;
            if (curr->child[idx] != nullptr) {
                curr = curr->child[idx];
            }
            else {
                curr->child[idx] = new node;
                curr = curr->child[idx];
            }
        }
        curr->prefix++;
        curr->words.push_back(s);
        curr->isEnd = true;
    }
    bool search(string s) {
        node* curr = root;

        for (auto c : s) {
            int idx = c - 'a';
            if (curr->child[idx] != nullptr) {
                curr = curr->child[idx];
            }
            else {
                return false;
            }
        }
        return curr->isEnd;
    }
    void deleteWord(string s) {
        node* curr = root;
        if (!search(s)) return;
        for (auto c : s) {
            int idx = c - 'a';
            node* next = curr->child[idx];
            if (--next->prefix == 0) {
                curr->child[idx] = nullptr;
                delete next;
                break;
            }
            else {
                curr = curr->child[idx];
            }
        }
    }
    bool startsWith(string s) {
        node* curr = root;

        for (auto c : s) {
            int idx = c - 'a';
            if (curr->child[idx] != nullptr) {
                curr = curr->child[idx];
            }
            else {
                return false;
            }
        }
        return true;
    }
};

void jarvis()
{

}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q = 1;
    cin >> q;
    while (q--)
    {
        jarvis();
    }
    return 0;
}
