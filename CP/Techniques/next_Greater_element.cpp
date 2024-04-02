#include <bits/stdc++.h>
using namespace std;
//problem link leetcode-
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
//problem link- https://leetcode.com/problems/next-greater-element-i/

//approach- we will use stack to store the elements in decreasing order and then we will iterate from the end of the array and for each element we will pop the elements from the stack until we find the element which is greater than the current element and then we will store the index of that element in the answer array
//if we don't find any element greater than the current element then we will store -1 in the answer array
//time complexity-O(n)
//space complexity-O(n)

vector<int> next_greater(vector<int>& nums) {
    stack<int> helper;
    vector<int> ans(nums.size(), -1);

    for (int i = nums.size() - 1; i >= 0; --i) {
        while (!helper.empty() && nums[i] >= nums[helper.top()]) {
            helper.pop();
        }
        if (!helper.empty()) {
            ans[i] = helper.top();
        }
        helper.push(i);
    }

    return ans;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    read(n);
    vector<int> v(n);
    for(int i = 0; i <n; i++) {
        read(v[i]);
    }
    vector<int>ans=next_greater(v);
    int q;
    read(q);


    while(q--){
        int x;
        read(x);
        x--;
        if(ans[x]==-1){
            cout<<-1<<endl;
            continue;
        }
        cout<<ans[x]+1<<endl;
    }
    return 0;
}