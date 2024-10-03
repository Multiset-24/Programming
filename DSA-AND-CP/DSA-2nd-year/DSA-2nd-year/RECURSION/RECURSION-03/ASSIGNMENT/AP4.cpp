#include <bits/stdc++.h>
using namespace std;
/*Given an array of integers, print a sum triangle using recursion from it such that the first level has
all array elements. After that, at each level the number of elements is one less than the previous
level and elements at the level will be the sum of consecutive two elements in the previous level.
So, if sample input is [5, 4, 3, 2, 1], sample output will be:
[5, 4, 3, 2, 1]
[9, 7, 5, 3]
[16, 12, 8]
[28, 20]
[48]*/

void triangle(vector<int> &v, int idx, vector<int> ans)
{
    int n = v.size();
    if (idx == n - 1)
    {

    }=
        return;
    }
ans.push_back(v[idx]+v[idx+1]);
    triangle(ans,idx+1,v);
}
int main()
{
int n;
cin>>n;
vector<int>v(n);
trtu
return 0;
}