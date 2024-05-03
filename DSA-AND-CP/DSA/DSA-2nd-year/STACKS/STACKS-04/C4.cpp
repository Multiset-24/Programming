#include <bits/stdc++.h>
using namespace std;
// prefixevaluations
int PrefixEvaluation(string &s)
{
    int n = s.length();
    stack<int> val;
    for (int i = n - 1; i >= 0; i--) // difference
    {
        if (s[i] >= 48 && s[i] <= 57)
        {
            val.push(s[i] - 48);
        }
        else
        {
            int v1 = val.top(); // difference
            val.pop();
            int v2 = val.top(); // difference
            val.pop();
            if (s[i] == '+')
                val.push(v1 + v2);
            else if (s[i] == '*')
                val.push(v1 * v2);
            else if (s[i] == '/')
                val.push(v1 / v2);
            else if (s[i] == '-')
                val.push(v1 - v2);
        }
    }
    return val.top();
}
string solve(string v1, string v2, char c)
{
    string ans = "";
    ans += v1;
    ans += c;
    ans += v2;
    return ans;
}
string Prefix2Infix(string &s)
{
    int n = s.length();
    stack<string> val;
    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] >= 48 && s[i] <= 57)
        {
            string digit(1, s[i]);
            val.push(digit);
        }
        else
        {
            string v1 = val.top();
            val.pop();
            string v2 = val.top();
            val.pop();
            string ans = solve(v1, v2, s[i]);
            val.push(ans);
        }
    }
    return val.top();
}
string solve2(string v1, string v2, char c)
{
    string ans = "";
    ans += v1;
    ans += v2;
    ans += c;
    return ans;
}
string Prefix2Postfix(string &s)
{
    int n = s.length();
    stack<string> val;
    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] >= 48 && s[i] <= 57)
        {
            string digit(1, s[i]);
            val.push(digit);
        }
        else
        {
            string v1 = val.top();
            val.pop();
            string v2 = val.top();
            val.pop();
            string ans = solve2(v1, v2, s[i]);
            val.push(ans);
        }
    }
    return val.top();
}
int main()
{
    string s = "-/*+79483";
    int n = PrefixEvaluation(s);
    cout << n;
    string ans = Prefix2Infix(s);
    cout << endl
         << ans;
    ans = Prefix2Postfix(s);
    cout << endl
         << ans;
    return 0;
}