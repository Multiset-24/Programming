#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define ll long long
typedef pair<int, int> pp;
bool is_b_a_subsequence_of_a(vector<int>& a, vector<int>& b)
{
    if (a.size() < b.size())
    {
        int i = 0;
        int j = 0;

        while (i < a.size() && j < b.size())
        {
            if (a[i] == b[j])
            {
                i++;
                j++;
            }
            else
            {
                j++;
            }
        }
        if (i == b.size())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        int i = 0;
        int j = 0;

        while (i < a.size() && j < b.size())
        {
            if (a[i] == b[j])
            {
                i++;
                j++;
            }
            else
            {
                i++;
            }
        }
        if (j == b.size())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}
int main()
{
    int n,m;

    cin>>n>>m;

    vector<int> a(n);
    vector<int>b(m);

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    for(int i=0;i<m;i++)
    {
        cin>>b[i];
    }

    if(is_b_a_subsequence_of_a(a,b))
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
    return 0;
}