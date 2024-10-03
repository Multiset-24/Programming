#include <bits/stdc++.h>
using namespace std;
// check if the array can be patitioned into 2 contaginous array having equal sum
int partition(vector<int> &nums)
{
    for (int i = 1; i < nums.size(); i++)
        nums[i] = nums[i - 1] + nums[i];
    for (int i = 0; i < nums.size(); i++)
        if (2 * nums[i] == nums[nums.size() - 1])
            return i;
    return -1;
}
int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    cout << partition(nums);
    return 0;
}