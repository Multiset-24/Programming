#include <bits/stdc++.h>
using namespace std;
// leetcode 704
int bin_search(vector<int> &nums, int target)
{
    sort(nums.begin(),nums.end());
    int n = nums.size();
    int lo = 0, hi = n - 1;
    int mid;
    while (lo <= hi)
    {
        mid = lo + (hi - lo) / 2;
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] > target)
            hi = mid - 1;
        else if (nums[mid] < target)
            lo = mid + 1;
    }
    return -1;
}
int main()
{
    int n;
    cout<<"Enter size of the array-";
    cin >> n;
    vector<int> v(n);
    cout<<"Enter the elements of the array-";
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int target;
    cout<<"Enter the target element-";
    cin >> target;
    cout << bin_search(v, target);
    return 0;
}