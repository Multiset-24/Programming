#include <bits/stdc++.h>
using namespace std;
// leetcode 2187 minimum time to complete trips
bool check(long long mid, vector<int> &time, int totalTrips)
{
    long long n = time.size();
    long long count = 0;
    for (int i = 0; i < n; i++)
    {
        count += (mid / time[i]);
    }
    if (count < totalTrips)
        return false;
    else
        return true;
}
long long minimumTime(vector<int> &time, int totalTrips)
{
    long long n = time.size();
    long long max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (max < time[i])
        {
            max = time[i];
        }
    }
    long long lo = 1;
    long long hi = (long long)totalTrips * max;
    long long ans = -1;
    while (lo <= hi)
    {
        long long mid = (long long)lo + (long long)(hi - lo) / (long long)2;
        if (check(mid, time, totalTrips))
        {
            hi = mid - 1;
            ans = mid;
        }
        else
        {
            lo = mid + 1;
        }
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    vector<int>time(n);
    for (int i = 0; i < n; i++)
    {
        cin>>time[i];
    }
    int totalTrips;
    cin>>totalTrips;
    cout<<minimumTime(time,totalTrips);
    return 0;
}