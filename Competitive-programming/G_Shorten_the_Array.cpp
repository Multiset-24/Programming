#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define int long long

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

struct node
{
    node *ch[2];
    int cnt;
    node()
    {
        ch[0] = ch[1] = nullptr;
        cnt = 0;
    }
};

class BT
{
private:
    node *root;
    int l = 60;

public:
    int sz = 0;
    BT()
    {
        root = new node();
    }
    void insert(int x)
    {
        sz++;
        node *curr = root;
        for (int i = l; i >= 0; i--)
        {
            curr->cnt++;
            int b = ((x >> i) & 1);
            if (!curr->ch[b])
                curr->ch[b] = new node();
            curr = curr->ch[b];
        }
        curr->cnt++;
    }
    bool search(int x){
        node* curr=root;

        for(int i=l;i>=0;i--){
            int b = ((x >> i) & 1);
            if(curr->ch[b]==nullptr){
                return false;
            }
            else curr=curr->ch[b];
        }
        return true;
    }
    void remove(int x)
    {
        if(!search(x))return ;
        sz--;
        node *curr = root;
        curr->cnt--;
        for (int i = l; i >= 0; i--)
        {
            int b = ((x >> i) & 1);
            node *next = curr->ch[b];
            if (--next->cnt == 0)
            {
                delete next;
                curr->ch[b] = nullptr;
                return;
            }
            curr = next;
        }
    }
    int getMax(int x)
    {
        node *curr = root;
        int ans = 0;
        for (int i = l; i >= 0; i--)
        {
            int b = ((x >> i) & 1);
            if (curr->ch[!b])
            {
                curr = curr->ch[!b];
                ans |= (1LL << i);
            }
            else if(curr->ch[b]!=nullptr)curr = curr->ch[b];
        }
        return ans;
    }
};

void jarvis()
{
    int n, k;
    cin >> n >> k;

    vector<int> num(n);
    for (auto &x : num)
        cin >> x;

    BT bt;
    int j=0;
    int ans=1e9;
    for(int i=0;i<n;i++){
        bt.insert(num[i]);
        while(bt.sz>0 && bt.getMax(num[i])>=k){
            ans=min(ans,i-j+1);
            bt.remove(num[j]);
            j++;
        }
    }
    cout<<(ans==1e9?-1:ans)<<endl;
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
