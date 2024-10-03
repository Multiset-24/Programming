#include <bits/stdc++.h>
using namespace std;
// minimum product subset

int minimum_prod(vector<int> v)
{
    int nn = 0;
    int nz = 0;
    int np = 0;

    int max_neg = INT_MIN;
    int min_pos = INT_MAX;
    int pn = 1;
    int pp = 1;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] < 0)
        {
            nn++;
            max_neg = max(v[i], max_neg);
            pn *= v[i];
        }
        if (v[i] == 0)
        {
            nz++;
        }
        if (v[i] > 0)
        {
            np++;
            pp *= v[i];
            min_pos = min(min_pos, v[i]);
        }
    }

    if (nn == 0)
    {
        if (nz > 0)
            return 0;
        else
            return min_pos;
    }
    else if (nn % 2 == 0)
    {
        return pp * (pn / max_neg);
    }
    else
    {
        return pp * pn;
    }
}
int main()
{
    vector<int> v = {2, 3, 1, 2, 4, 5, 0};
    cout << minimum_prod(v);
    return 0;
}