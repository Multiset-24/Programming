#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define ll long long
typedef pair<int,int> pp;

// #define DEBUG
#ifdef DEBUG
#define debug(x) cout << #x << " = " << x << endl
#else
#define debug(x)
#endif

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s;
    cin>>s;
    int count=0;   
    string username="",pwd="",profile="",role="",key=""; 
    for(int i=0;i<s.length();i++){
        if(s[i]=='=' and count==0){
            while(i+1<s.length()&&s[i+1]!='&'){
                username+=s[i+1];
                i++;
            }
            count++;
        }
        else if(i+1<s.length()&&s[i]=='=' and count==1 ){
            while(i+1<s.length()&&s[i+1]!='&'){
                pwd+=s[i+1];
                i++;
            }
            count++;
        }
        else if(i+1<s.length()&&s[i]=='=' and count==2 ){
            while(i+1<s.length()&&s[i+1]!='&'){
                profile+=s[i+1];
                i++;
            }
            count++;
        }
        else if(i+1<s.length()&&s[i]=='=' and count==3 ){
            while(i+1<s.length()&&s[i+1]!='&'){
                role+=s[i+1];
                i++;
            }
            count++;
        }
        else if(i+1<s.length()&&s[i]=='=' and count==4){
            while(i+1<s.length()&&s[i+1]!='&'){
                key+=s[i+1];
                i++;
            }
            count++;
        }
    }

    cout<<"username: "<<username<<"\n";
    cout<<"pwd: "<<pwd<<"\n";
    cout<<"profile: "<<profile<<"\n";
    cout<<"role: "<<role<<"\n";
    cout<<"key: "<<key<<"\n";
    return 0;
}