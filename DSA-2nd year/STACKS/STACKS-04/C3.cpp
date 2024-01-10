#include <bits/stdc++.h>
using namespace std;
// postfix and prefix evaluations
int PostfixEvaluation(string &s)
{
    int n = s.length();
    stack<int> val;
    for (int i = 0; i < n; i++)
    {
        if (s[i] >= 48 && s[i] <= 57)
        {
            val.push(s[i] - 48);
        }
        else
        {
            int v2=val.top();
            val.pop();
            int v1=val.top();
            val.pop();
            if(s[i]=='+') val.push(v1+v2);
           else if(s[i]=='*') val.push(v1*v2);
           else if(s[i]=='/') val.push(v1/v2);
            else if(s[i]=='-') val.push(v1-v2);
        }
    }
        return val.top();
}
string solve(string v1,string v2,char c){
    string ans="";
    ans+=v1;
    ans+=c;
    ans+=v2;
    return ans;
}
string Postfix2Infix(string &s)
{
    int n = s.length();
    stack<string> val;
    for (int i = 0; i < n; i++)
    {
        if (s[i] >= 48 && s[i] <= 57)
        {
            string digit(1,s[i]);
            val.push(digit);
        }
        else
        {
            string v2=val.top();
            val.pop();
            string v1=val.top();
            val.pop();
            string ans=solve(v1,v2,s[i]);
            val.push(ans);
        }
    }
        return val.top();
}
string solve2(string v1,string v2,char c){
    string ans="";
    ans+=c;
    ans+=v1;
    ans+=v2;
    return ans;
}
string Postfix2Prefix(string &s)
{
    int n = s.length();
    stack<string> val;
    for (int i = 0; i < n; i++)
    {
        if (s[i] >= 48 && s[i] <= 57)
        {
            string digit(1,s[i]);
            val.push(digit);
        }
        else
        {
            string v2=val.top();
            val.pop();
            string v1=val.top();
            val.pop();
            string ans=solve2(v1,v2,s[i]);
            val.push(ans);
        }
    }
        return val.top();
}
    int main()
    {
        string s="79+4*8/3-";
        int n=PostfixEvaluation(s);
        cout<<n;
        string ans=Postfix2Infix(s);
        cout<<endl<<ans;
        ans=Postfix2Prefix(s);
        cout<<endl<<ans;
        return 0;
    }