#include <bits/stdc++.h>
using namespace std;
// print powerset of a set having duplicate elements
void helper(vector<int> &nums, int idx, vector<int> ans, vector<vector<int>> &finalans)
{
    if (idx == nums.size())
    {
        sort(ans.begin(), ans.end());
        bool flag = true;
        for (int i = 0; i < finalans.size(); i++)
        {
            if (finalans[i] == ans)
            {
                flag = false;
            }
        }
        if (flag == false)
            return;
        else
        {
            finalans.push_back(ans);
            return;
        }
    }
    // exclude vala case
    helper(nums, idx + 1, ans, finalans);
    // include vala case
    ans.push_back(nums[idx]);
    helper(nums, idx + 1, ans, finalans);
}
vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
    vector<vector<int>> finalans;
    vector<int> ans;
    helper(nums, 0, ans, finalans);
    return finalans;
}
int main()
{
    int n;
    cin>>n;
vector<int>nums(n);
for (int i = 0; i < n; i++)
{
    cin>>nums[i];
}
vector<vector<int>>finalans=subsetsWithDup(nums);
for (int i = 0; i < finalans.size(); i++)
{
    cout<<finalans[i][1]<<" ";
}
    return 0;
}
//fix the error later
