#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        int total_elements, min_sum, max_sum;
        cin >> total_elements >> min_sum >> max_sum;

        vector<long> nums(total_elements); // Instantiate nums with total_elements
        for (long &num : nums)
        {
            cin >> num;
        }

        int valid_subarrays = 0;
        long current_total = 0;
        int subarray_start = 0;

        for (int i = 0; i < total_elements; ++i)
        {
            if (nums[i] > max_sum)
            {
                current_total = 0;
                subarray_start = i + 1;
                continue;
            }

            current_total += nums[i];

            while (current_total < min_sum && i < total_elements - 1)
            {
                ++i;
                current_total += nums[i];
            }

            if (current_total >= min_sum && current_total <= max_sum)
            {
                ++valid_subarrays;
                current_total = 0;
                subarray_start = i + 1;
            }
            else if (current_total > max_sum)
            {
                current_total = 0;
                i = subarray_start;
                ++subarray_start;
            }
        }

        cout << valid_subarrays << endl;
    }

    return 0;
}