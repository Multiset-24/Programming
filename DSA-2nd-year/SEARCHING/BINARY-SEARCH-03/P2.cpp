#include <bits/stdc++.h>
using namespace std;
// leetocode 875 koko eating bananas
bool check(int mid, vector<int> &piles, int h)
{
    int n = piles.size();
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (count > h)
            return false;
        if (mid >= piles[i])
            count++;
        else if (piles[i] % mid == 0)
        {
            count += (piles[i] / mid);
        }
        else
        {
            count += (piles[i] / mid) + 1;
        }
    }

    if (count > h)
        return false;
    else
        return true;
}
int minEatingSpeed(vector<int> &piles, int h)
{
    int n = piles.size();
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (max < piles[i])
            max = piles[i];
    }
    int lo = 1;
    int hi = max;
    int minK = max;
    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;
        if (check(mid, piles, h))
        {
            minK = mid;
            hi = mid - 1;
        }
        else
        {
            lo = mid + 1;
        }
    }
    return minK;
}
int main()
{
    int n;
    cin >> n;
    vector<int> piles(n);
    for (int i = 0; i < n; i++)
    {
        cin >> piles[i];
    }
    int h;
    cin >> h;
    cout << minEatingSpeed(piles, h);
    return 0;
}