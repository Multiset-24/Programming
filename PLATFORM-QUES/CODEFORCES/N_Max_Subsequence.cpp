#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    
    string s;
    cin>>s;
    char last=s[0];
    int len=1;
    for(int i=0;i<s.length();i++){
        if(s[i]!=last){
            len++;
            last=s[i];
        }
    }
    
    cout<<len;
}