#include <bits/stdc++.h>
using namespace std;
//previous greater element 
vector<int> PrevGreater(vector<int>arr)
{
    stack<int> st;
    vector<int> ans(arr.size());
    st.push(arr[0]);
    ans[0] = -1;
    for (int i = 1; i <arr.size(); i++)
    {
        while (st.size()>0&&st.top() <= arr[i])
            st.pop();
        if (st.size() == 0 && st.size()>0)
            ans[i] = -1;
        else
            ans[i] = st.top();
        st.push(arr[i]);
    }
    return ans;
}
int main() {
    vector<int> arr = {10, 1, 2, 5, 4, 6, 2, 3};
    arr = PrevGreater(arr);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i]<<" ";
    }
    return 0;
}