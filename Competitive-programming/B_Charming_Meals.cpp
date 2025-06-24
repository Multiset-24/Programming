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

/*
    question:
    1<=i<=n
    ith dish has spiciness bi and appetizer has spiciness of ai
    A czech meal has one appetizer and one main dish
    for a meal M having appetizer a and main dish b having speciness level as x and y then Charm value=abs(x-y)

    Task -> maximise the minimum charm value that we can achieve

    solution required Tc=O(n) or O(nlogn)

    tc:
    5
    1 2 3 4 5
    1 2 3 4 5

    charm = 3
    5-2=3 
    minimum charm pair=(5,2) or (2,5)
    other pairs=(1,4)(4,1)(2,3)(3,2)
    pattern ka idea-binary search
    agr hume minimum charm value di ho ek array ki to kya hum bta skte hai ki vhi minimum hai ya usse km bhi charm value exist kar skti hai abs(x-y)=@
    _____________x_____________y____________ number line
    for a x
    we have x=@+y or x=@-y we can find this using lowerbound
*/
void jarvis()
{
    int n;
    cin>>n;
    vector<int>a(n),b(n);
    for(auto &x:a)cin>>x;
    for(auto &x:b)cin>>x;
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int lo=abs(a[0]-b[0]),hi=abs(max(abs(a[0]-b[n-1]),abs(a[n-1]-b[0])));
    auto check = [&](int x){
    multiset<int> ms(b.begin(), b.end());
    for(int i = 0; i < n; i++){
        auto it1 = ms.lower_bound(a[i] + x);
        if(it1 != ms.end()){
            ms.erase(it1);
            continue;
        }
        auto it2 = ms.upper_bound(a[i] - x);
        if(it2 == ms.begin()) return false;
        --it2;
        ms.erase(it2);
    }
    return true;
};
    int ans=lo;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(check(mid)){
            lo=mid+1;
            ans=mid;
        }
        else hi=mid-1;
    }
    cout<<ans<<endl;
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