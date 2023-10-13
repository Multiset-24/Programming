// //my approach

#include <bits/stdc++.h>
using namespace std;
vector<int> twoSum(vector<int> &nums, int target)
{
    vector<int> output;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = nums.size() - 1; j >= 0 && j != i; j--)
        {
            if (nums[i] + nums[j] == target)
            {
                output.push_back(i);
                output.push_back(j);
            }
        }
    }
    return output;
}
int main()
{
    int n, target;
    cin >> target >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    vector<int> result = twoSum(nums, target);
    if (result.size() == 2)
    {
        cout << result[0] << " " << result[1];
    }
    else
    {
        cout << " indices not found";
    }
    return 0;
}

// optimised approach


#include <bits/stdc++.h>
using namespace std;
int main()
{
    int target, n;
    cout << "Enter the target-";
    cin >> target;
    vector<int> v;
    cout << "Enter the number of elements in Vector-";
    cin >> n;
    cout << "Enter the element of the Vector-";
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    for (int i = 0; i < v.size() - 1; i++)
    {
        for (int j = i + 1; j < v.size(); j++)
        {
            if (v[i] + v[j] == target)
            {
                cout << "(" << v[i] << "," << v[j] << ")" << endl;
            }
        }
    }

    return 0;
}