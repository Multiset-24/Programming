#include <bits/stdc++.h>
using namespace std;
// sort the string of small letters using bubble sort
vector<string> sort_bubble(vector<string> s)
{
    int n = s.size();
    for (int i = 0; i < n - 1; i++)
    {
        bool flag = true;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (s[j] > s[j + 1])
            {
                swap(s[j], s[j + 1]);
                flag = false;
            }
        }
        if (flag == true)
            return s;
    }
    return s;
}
int main()
{
    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }

    sort_bubble(s);
    for (int i = 0; i < n; i++)
    {
        cout << s[i] << " ";
    }

    return 0;
}