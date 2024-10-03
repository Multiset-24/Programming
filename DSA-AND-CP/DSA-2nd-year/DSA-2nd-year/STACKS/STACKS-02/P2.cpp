#include <bits/stdc++.h>
using namespace std;
//remove the duplicates in a string
string removeDuplicates(string &s){
    stack<char>st;
    st.push(s[0]);
    for (int i = 1; i < s.length(); i++)
    {
        if(s[i]!=st.top()){
            st.push(s[i]);
        }
    }
    string s2(st.size(),0);
    for (int i = st.size()-1; i >=0; i--)
    {
        s2[i]=st.top();
        st.pop();
    }
return s2;
}
int main() {
    string s="aaabbcddaabffg";
    s=removeDuplicates(s);
    for (int i = 0; i < s.length(); i++)
    {
        cout<<s[i];
    }
    
    return 0;
}