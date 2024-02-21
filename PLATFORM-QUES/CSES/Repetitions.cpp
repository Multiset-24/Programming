#include <bits/stdc++.h>
using namespace std;
// https://cses.fi/problemset/task/1069
#define mod 1000000007

long long repetitions(string &s){
    long long max_repeat=INT_MIN;
    long long repeat=1;
    for(int i=1;i<s.length();i++){
        if(s[i]==s[i-1]){
            repeat++;
        }
        else{
            repeat=1;
        }
        max_repeat=max(max_repeat,repeat);
    }
    return (max_repeat==INT_MIN)?1:max_repeat;
}
int main()
{
    string s;
    cin>>s;

    cout<<repetitions(s);
    return 0;
}