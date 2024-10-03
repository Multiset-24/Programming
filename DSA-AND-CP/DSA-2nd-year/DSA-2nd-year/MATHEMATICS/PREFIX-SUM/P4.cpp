#include <bits/stdc++.h>

using namespace std;
// leetcode 2483
//minimum penalty for a shop vali problem
class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.length();
        vector<int> pre(n + 1, 0);
        vector<int> suf(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            pre[i] = pre[i - 1] + (customers[i - 1] == 'N');
        }

        for (int i = n - 1; i >= 0; i--) {
            suf[i] = suf[i + 1] + (customers[i] == 'Y');
        }

        int min_pe = INT_MAX;
        for (int i = 0; i <= n; i++) {
            min_pe = min(min_pe, pre[i] + suf[i]);
        }

        for (int i = 0; i <= n; i++) {
            if (pre[i] + suf[i] == min_pe) {
                return i;
            }
        }

        return 0;
    }
};

int main() {
    Solution solution;
    string customers = "NNNNNYYYYYYYYYNY";
    int result = solution.bestClosingTime(customers);
    cout << "The best closing time is at position: " << result << endl;
    return 0;
}
