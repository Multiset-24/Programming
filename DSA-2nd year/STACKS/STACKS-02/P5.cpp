#include <bits/stdc++.h>
using namespace std;
//Stock span problem- This problem is storing The number of cosecutive  previous days stock's price is highest
vector<int> StockSpan(vector<int>arr){
    stack<int>st;
    vector<int>ans(arr.size());
    ans[0]=1;
    st.push(0);
    for (int i = 1; i < arr.size(); i++)
    {
        while(arr[st.top()]<arr[i]) st.pop();
        if(st.size()==0) ans[i]=1;
        else ans[i]=i-st.top();
        st.push(i);
    }
    return ans;
}

vector<int>Prevsmall(vector<int>& heights){
        stack<int>st;
        vector<int>ans(heights.size());
        st.push(0);
        ans[0]=-1;
        for(int i=1;i<heights.size();i++){
            while(st.size()!=0 && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.size()==0) ans[i]=-1;
            else ans[i]=i-st.top();
            st.push(i);
        }
        return ans;
    }
int main() {
    vector<int>arr={100,80,60,70,60,75,85};
    vector<int>ans=StockSpan(arr);
    for (int i = 0; i < arr.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    ans=Prevsmall(arr);
    for (int i = 0; i < arr.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}