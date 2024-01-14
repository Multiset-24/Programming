#include <bits/stdc++.h>
using namespace std;
// next greater element using stacks
vector<int> NextGreater(vector<int>arr)
{
    stack<int> st;
    vector<int> ans(arr.size());
    st.push(arr[arr.size() - 1]);
    ans[arr.size() - 1] = -1;
    for (int i = arr.size() - 2; i >= 0; i--)
    {
        while (st.top() <= arr[i])
            st.pop();
        if (st.size() == 0)
            ans[i] = -1;
        else
            ans[i] = st.top();
        st.push(arr[i]);
    }
    return ans;
}
int main()
{
    vector<int> arr = {10, 1, 2, 5, 4, 6, 2, 3};
    arr = NextGreater(arr);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i]<<" ";
    }
    return 0;
}