#include <bits/stdc++.h>
using namespace std;
vector<int> merge(vector<int> &a, vector<int> &b)
{
    int i = 0, j = 0, k = 0;
    vector<int> r(a.size() + b.size());
    while (i < a.size() && j < b.size())
    {
        if (a[i] < b[j])
            r[k++] = a[i++];
        else
            r[k++] = a[j++];
    }
    if (i == a.size())
    {
        while (j < b.size())
            r[k++] = b[j++];
    }
    if (j == b.size())
    {
        while (i < a.size())
            r[k++] = a[i++];
    }
    return r;
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    vector<int> a(arr, arr + 5);
    int brr[] = {6, 7, 20, 34, 56, 78, 90, 100,120,129,130};
    vector<int> b(brr, brr + 11);
    vector<int> merge_array = merge(a, b);
    for (int i = 0; i < merge_array.size(); i++)
    {
       cout<<merge_array[i]<<" ";
    }

    return 0;
}