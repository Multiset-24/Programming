#include <bits/stdc++.h>
using namespace std;
//marcurian and k-ordered LCS

#define mod 1000000007
#define F(i,a,b) for(int i = (int)(a); i <= (int)(b); i++)
#define RF(i,a,b) for(int i = (int)(a); i >= (int)(b); i--)

int f(string s1,string s2,int i,int j,k){
    if(i>=s1.size()) return 0;
    if(j>=s2.size()) return 0;
    
    int ans=f(s1,s2,i+1,j+1,k);

    if(s1[i]==s2[j]) ans=max(1+f(s1,s2,i+1,j+1,k),ans);
    else if(k>0){
        int change=f(s1,s2,i+1,j+1,k-1);
        int no_change=max(f(s1,s2,i,j+1,k),f(s1,s2,i+1,j,k));
        int ans=max(ans,max(change,no_change));
    }
    else if(k<=0){
        ans=max(f(s1,s2,i,j+1,k),f(s1,s2,i+1,j,k));
    }
    return ans;
}
int main() {
    
    return 0;
}