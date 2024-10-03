#include <bits/stdc++.h>
using namespace std;
// infix to prefix expression(OP V1 V2)
int priority(char c)
{
    if (c == '+' || c == '-')
        return 1;
    else
        return 2;
}
string solver(string v1,string v2,char c){
    string ans="";
    ans+=c;
    ans+=v1;
    ans+=v2;
    return ans;
}
string solver2(string v1,string v2,char c){
    string ans="";
    ans+=v1;
    ans+=v2;
    ans+=c;
    return ans;
}
string Infix2Prefix(string &s)
{
    int n = s.size();
    stack<string> val;
    stack<char> op;
    for (int i = 0; i < n; i++)
    {
        if (s[i] >= 48 && s[i] <= 57)
        {
            string digit(1, s[i]); // Convert character to string
            val.push(digit);
        }
        else
        {
            if (op.size() == 0)
                op.push(s[i]);
            else if (op.top() == '(')
                op.push(s[i]);
            else if (s[i] == '(')
                op.push(s[i]);
            else if (s[i] == ')')
            {
                while (op.top() != '(')
                {
                    string v2 = val.top();
                    val.pop();
                    string v1 = val.top();
                    val.pop();
                    string sval = solver(v1,v2,op.top());
                    val.push(sval);
                    op.pop();
                }
                op.pop();
            }
            else if (priority(s[i]) > priority(op.top()))
            {
                op.push(s[i]);
            }
            else
            {
                while (op.size()!=0 && priority(s[i]) <= priority(op.top()))
                {
                    string v2 = val.top();
                    val.pop();
                    string v1 = val.top();
                    val.pop();
                    string sval = solver(v1,v2,op.top());
                    val.push(sval);
                    op.pop();
                }
                op.push(s[i]);
            }
        }
    }
    while (op.size() != 0)
    {
        string v2 = val.top();
        val.pop();
        string v1 = val.top();
        val.pop();
        string sval = solver(v1,v2,op.top());
        val.push(sval);
        op.pop();
    }
    return val.top();
}
string Infix2Postfix(string &s)
{
    int n = s.size();
    stack<string> val;
    stack<char> op;
    for (int i = 0; i < n; i++)
    {
        if (s[i] >= 48 && s[i] <= 57)
        {
            string digit(1, s[i]); // Convert character to string
            val.push(digit);
        }
        else
        {
            if (op.size() == 0)
                op.push(s[i]);
            else if (op.top() == '(')
                op.push(s[i]);
            else if (s[i] == '(')
                op.push(s[i]);
            else if (s[i] == ')')
            {
                while (op.top() != '(')
                {
                    string v2 = val.top();
                    val.pop();
                    string v1 = val.top();
                    val.pop();
                    string sval = solver2(v1,v2,op.top());
                    val.push(sval);
                    op.pop();
                }
                op.pop();
            }
            else if (priority(s[i]) > priority(op.top()))
            {
                op.push(s[i]);
            }
            else
            {
                while (op.size()!=0 && priority(s[i]) <= priority(op.top()))
                {
                    string v2 = val.top();
                    val.pop();
                    string v1 = val.top();
                    val.pop();
                    string sval = solver2(v1,v2,op.top());
                    val.push(sval);
                    op.pop();
                }
                op.push(s[i]);
            }
        }
    }
    while (op.size() != 0)
    {
        string v2 = val.top();
        val.pop();
        string v1 = val.top();
        val.pop();
        string sval = solver2(v1,v2,op.top());
        val.push(sval);
        op.pop();
    }
    return val.top();
}
int main()
{
    string s = "(7+9)*4/8-3";
    string ans = Infix2Prefix(s);
    cout << ans;
    ans=Infix2Postfix(s);
    cout<<endl<<ans;
    return 0;
}