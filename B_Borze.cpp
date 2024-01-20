#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin>>s;
    vector<int>v;
    for(int i=0;i<s.size();i++){
        if(s[i]=='-'){
            if(s[i+1]=='-'){
                v.push_back(2);
            }
            else{
                v.push_back(1);
            }
            i++;
        }
        else{
            v.push_back(0);
        }
    }

    for(int i=0;i<v.size();i++){
            cout<<v[i];
    }
    return 0;
}