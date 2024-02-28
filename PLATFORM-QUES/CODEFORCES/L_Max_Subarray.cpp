#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define ll long long
typedef pair<int, int> pp;
void L_max_subarray(vector<int> &num)
{
    int n = num.size();
    int _max = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        _max = INT_MIN;
        for (int j = i; j < n; j++)
        {
            _max = max(_max, num[j]);
            cout << _max << " ";
        }
    }
}
int main()
{
    int n;
    cin >> n;

    while (n--)
    {
        int k;
        cin >> k;
        vector<int> num(k);

        for (int i = 0; i < k; i++)
        {
            cin >> num[i];
        }

        L_max_subarray(num);
        cout << endl;
    }
    return 0;
}