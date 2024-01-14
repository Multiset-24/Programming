#include <bits/stdc++.h>
using namespace std;
#include <stack>
// infix evaluation
int kaam(stack<int> &val, char c)
{
    int v2 = val.top();
    val.pop();
    int v1 = val.top();
    val.pop();
    if (c == '+')
        return (v1 + v2);
    if (c == '-')
        return (v1 - v2);
    if (c == '*')
        return (v1 * v2);
    if (c == '/')
        return (v1 / v2);
}
int priority(char c)
{
    if (c == '+' || c == '-')
        return 1;
    else
        return 2;
}
int InfixEvaluation(string &s)
{
    int n = s.length();
    stack<char> op;
    stack<int> val;
    for (int i = 0; i < n; i++)
    {
        if (s[i] >= 48 && s[i] <= 57)
        {
            val.push(s[i] - 48);
        }
        else
        {
            if (op.size() == 0)
                op.push(s[i]);
            else if (priority(s[i]) > priority(op.top()))
                op.push(s[i]);
            else
            {
                while (op.size() && priority(s[i]) <= priority(op.top()))
                {
                    int sval = kaam(val, op.top()); // yha galti hui op.top ki jagah s[i] likh dia tha
                    val.push(sval);
                    op.pop();
                }
                op.push(s[i]);
            }
        }
    }
    while (op.size() != 0)
    {
        int sval = kaam(val, op.top());
        val.push(sval);
        op.pop();
    }
    return val.top();
}
int InfixEvaluationBrackets(string &s){
    int n = s.length();
    stack<char> op;
    stack<int> val;
    for (int i = 0; i < n; i++)
    {
        if (s[i] >= 48 && s[i] <= 57)
        {
            val.push(s[i] - 48);
        }
        else
        {
            if (op.size() == 0)
                op.push(s[i]);
            else if(op.top()=='(') op.push(s[i]);//this line is most important since there is no priority of brackets they need to be solved at first
            else if(s[i]=='(' || s[i]==')'){
                if(s[i]=='(') op.push(s[i]);
                else{
                    while(op.top()!='('){
                        int sval = kaam(val, op.top()); // yha galti hui op.top ki jagah s[i] likh dia tha
                    val.push(sval);
                    op.pop();
                    }
                    op.pop();
                }
            }
            else if (priority(s[i]) > priority(op.top()))
                op.push(s[i]);
            else
            {
                while (op.size() && priority(s[i]) <= priority(op.top()))
                {
                    int sval = kaam(val, op.top()); // yha galti hui op.top ki jagah s[i] likh dia tha
                    val.push(sval);
                    op.pop();
                }
                op.push(s[i]);
            }
        }
    }
    while (op.size() != 0)
    {
        int sval = kaam(val, op.top());
        val.push(sval);
        op.pop();
    }
    return val.top();
}
int main()
{
    string s = "2+6*4/8-3";
    int ans = InfixEvaluation(s);
    cout << ans<<endl;
    s="1+(2+6)*4/8-3";
    ans=InfixEvaluationBrackets(s);
    cout<<ans;
    return 0;
}