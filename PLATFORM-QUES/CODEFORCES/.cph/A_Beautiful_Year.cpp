#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    for (int i = n + 1; i <= n+200; i++) {
        int k = i;
        unordered_set<int> digits;

        for (int j = 0; j < 4; j++) {
            int digit = k % 10;
            k /= 10;
            digits.insert(digit);
        }

        if (digits.size() == 4) {
            cout << i;
            break;
        }
    }
    return 0;
}