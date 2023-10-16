#include <bits/stdc++.h>
using namespace std;
// find the lower bound using linear search and binary search
int lower_bound_LS(vector<int> &v, int x)
{
    sort(v.begin(),v.end());
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        if (v[i] > x)
            return v[i - 1];
    }
    return -1;
}
int lower_bound_BS(vector<int> &nums, int target)
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
    return nums[hi];
}
int main()
{
int n;
cout<<"Enter the size of the array- ";
cin>>n;
cout<<"Enter the elemenst of the array- ";
vector<int>v(n);
for (int i = 0; i < n; i++)
{
    cin>>v[i];
}
cout<<"Enter the x for which lower bound is to be found- ";
int x;
cin>>x;
cout<<lower_bound_LS(v,x);
cout<<endl;
cout<<lower_bound_BS(v,x);
    return 0;
}