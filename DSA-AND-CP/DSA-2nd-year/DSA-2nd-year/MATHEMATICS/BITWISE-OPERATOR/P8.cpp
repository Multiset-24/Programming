#include <bits/stdc++.h>
using namespace std;
// find the size of the subarray in which if we do bitwise and of the elements present in the array then it will attain maximum size
int main() {
 int arr[] = {12, 3, 1,6,1, 18, 18, 6, 6, 6, 4, 3, 8, 13, 13, 8};
    int n = 16;
    int ans = 0;
    int max_el = INT_MIN;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max_el)
        {
            max_el = arr[i];
            count = 1;
        }
        else if (arr[i] == max_el)
        {
            count++;
        }
        ans = max(ans, count);
    }
    cout << ans;
    return 0;
}