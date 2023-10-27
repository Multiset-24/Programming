#include <bits/stdc++.h>
using namespace std;
// leetcode 78
// print susets of a string with unique characters
// follow up-do it for array as well

// for strings
void subset(string s, string ans, int idx)
{
    if (idx == s.size())
    {
        cout << ans << endl;
        return;
    }
    char ch = s[idx];
    subset(s, ans, idx + 1);
    subset(s, ans + ch, idx + 1);
}
vector<string> storefunc(string s, string ans, int idx)
{
    vector<string>v;
    if (idx == s.size())
    {
        v.push_back(ans);
        return v;
    }
    char ch = s[idx];
    subset(s, ans, idx + 1);
    subset(s, ans + ch, idx + 1);
}

//for arrays
void printsubset(int arr[],int n,int idx,vector<int>ans){
    if(idx==n){
        for (int i = 0; i < ans.size(); i++)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
        return;
    }
    printsubset(arr,n,idx+1,ans);
    ans.push_back(arr[idx]);
    printsubset(arr,n,idx+1,ans);
}
int main()
{
    string s = "ABCD";
    string ans = "";
    // subset(s, ans, 0);
    vector<string>S=storefunc(s,ans,0);
    for (int i = 0; i < S.size(); i++)
    {
        cout<<S[i]<<" ";
    }
    int arr[]={3,1,7,4};
    vector<int>ans2;
    printsubset(arr,4,0,ans2);
    return 0;
}