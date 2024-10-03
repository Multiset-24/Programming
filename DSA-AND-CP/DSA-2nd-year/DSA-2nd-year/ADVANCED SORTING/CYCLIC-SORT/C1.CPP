#include <bits/stdc++.h>
using namespace std;
// cyclic sort (this is only applicable for the array having elemensts from 1 to n in a random order)
// everytime you are asked for the T.c of O(n) and S.C of O(1) then this is applicable
void cyclic_sort(vector<int> &v)
{
    int i = 0;
    int n = v.size();
    while (i < n)
    {
        int correctidx = v[i] - 1;
        if (i == correctidx)
            i++;
        else
            swap(v[i], v[correctidx]);
    }
}
int main()
{
    vector<int> v(6);
    for (int i = 0; i < 6; i++)  cin >> v[i];
    cyclic_sort(v);
    for (int i = 0; i < 6; i++) cout << v[i] << " ";
    return 0;
}