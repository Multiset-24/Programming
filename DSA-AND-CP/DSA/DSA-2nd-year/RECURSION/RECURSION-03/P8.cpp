#include <bits/stdc++.h>
using namespace std;
// permutations of the strings
void permutate(string s, string ans)
{

    if (s.size() == 0)
    {
        cout << ans << endl;
        return;
    }
    for (int i = 0; i < s.size(); i++)
    {
        char ch = s[i];
        string rest = s.substr(0, i) + s.substr(i + 1); // Remove the character at index i
        permutate(rest, ans + ch);
    }
}
int main()
{
    string s = "ABC";
    string ans = "";
    permutate(s, ans);
    return 0;
}