#include <bits/stdc++.h>
using namespace std;
// leetcode 1480 very eary running sum of 1d array
vector<int> runningSum(vector<int> &nums)
{
    int n = nums.size();
    vector<int> run(n);
    run[0] = nums[0];
    for (int i = 1; i < n; i++)
    {
        run[i] = run[i - 1] + nums[i];
    }
    return run;
}
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    vector<int> ans = runningSum(v);
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    return 0;
}