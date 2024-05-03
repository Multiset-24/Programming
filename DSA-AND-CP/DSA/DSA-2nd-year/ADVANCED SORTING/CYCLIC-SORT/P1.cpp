#include <bits/stdc++.h>
using namespace std;
int missingNumber(vector<int> &nums)
{
    int n = nums.size();
    // int sum=0;
    // for(int i=0;i<n;i++){
    //     sum+=nums[i];
    // }
    // int Sum=(n*(n+1))/2;
    // return Sum-sum;
    int i = 0;
    while (i < n)
    {
        if (nums[i] == i || nums[i] == n)
            i++;
        else
            swap(nums[i], nums[nums[i]]);
    }
    for (int i = 0; i < n; i++)
    {
        if (nums[i] != i)
            return i;
    }
    return n;
}
int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    cout<<"Enter the array elemenst now";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
missingNumber(nums);
    return 0;
}