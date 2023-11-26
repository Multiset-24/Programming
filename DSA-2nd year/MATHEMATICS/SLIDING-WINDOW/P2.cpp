#include <bits/stdc++.h>
using namespace std;
// first negitive number in every window of size k
vector<int> frstneg(vector<int> &nums, int k)
{
    int n = nums.size();
    int i = 1;
    int j = k;
    vector<int> ans;
    int p = -1;
    for (int i = 0; i < k; i++)
    {
        if (nums[i] < 0)
        {
            p = i;
            ans.push_back(nums[i]);
            break;
        }
    }
    if (p == -1)
        ans.push_back(0);
    while (j < n)
    {
        if (i < p)
        {
            ans.push_back(nums[p]);
        }
        else
        {
            p=-1;
            for (int l = i; l <=j; l++)
            {
                if (nums[l] < 0)/*-1,2,4,-5,6,7,8,9,10,-12,13*/
                {
                    p = l;
                    ans.push_back(nums[l]);
                    break;
                }
            }
        }
        if(p==-1){
            ans.push_back(0);
        }
        i++;
        j++;
    }
    return ans;
}
int main()
{
vector<int>nums={-1,2,4,-5,6,7,8,9,10,-12,13};
vector<int>ans=frstneg(nums,3);
for (int i = 0; i < ans.size(); i++)
{
    cout<<ans[i]<<" ";
}


    return 0;
}
