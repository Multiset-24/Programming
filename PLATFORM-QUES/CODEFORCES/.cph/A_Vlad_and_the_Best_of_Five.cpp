#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define ll long long
char most_freq_char(string &s){
    unordered_map<char,int>mp;

    for(int i=0;i<s.size();i++){
        mp[s[i]]++;
    }

    char charc;
    int freq=0;
    for(auto ele:mp){
        char c=ele.first;
        int f=ele.second;

        if(f>freq){
            charc=c;
            freq=f;
        }
    }

    return  charc;
}
int main() {
    int n;//no of testcases
    cin>>n;

    while(n--){
        string s;
        cin>>s;
        cout<<most_freq_char(s)<<endl;
    }
    return 0;
}