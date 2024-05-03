// URL: https://codeforces.com/contest/1418/problem/W

//This approach is based on the concept of mapping the original string to the key string and then using the mapping to encrypt and decrypt the message.
//has the time complexity of O(n) and space complexity of O(1) since size is constant throughout the code;
#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define ll long long
typedef pair<int, int> pp;

#define DEBUG
#ifdef DEBUG
#define debug(x) cout << #x << " = " << x <<endl
#else
#define debug(x)
#endif


void encyption(string &a,string &b,string c){//a is key,b is original,c is message
    char map[256] = {0};
    for(int i=0;i<a.length();i++){
        map[b[i]] = a[i];
    }
    for(int i=0;i<c.length();i++){
        cout<<map[c[i]];
    }
}

void decyption(string &a,string &b,string c){
    char map[256] = {0};
    for(int i=0;i<a.length();i++){
        map[a[i]] = b[i];
    }
    for(int i=0;i<c.length();i++){
        cout<<map[c[i]];
    }
}

int main()
{
    string _Key ="PgEfTYaWGHjDAmQqFLRpCJBownyUKZXkbvzIdshurMilNSVOtec#@_!=.+-*/";
    string Original ="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

    int n;
    cin>>n;
    string s;
    cin>>s;
    debug(s);
    if(n==1){
        encyption(_Key,Original,s);
    }
    else{
        decyption(_Key,Original,s);
    }
    return 0;
}


// #include <bits/stdc++.h>
// using namespace std;

// #define mod 1000000007
// #define ll long long
// typedef pair<int, int> pp;

// void encyption(string &a,string &b,string c){//a is key,b is original,c is message
//         for(int i=0;i<c.length();i++){
//             for(int j=0;j<a.length();j++){
//                 if(c[i]==b[j]){
//                     cout<<a[j];
//                 }
//             }
//         }
// }

// void decyption(string &a,string &b,string c){//a is key,b is original,c is message
//     for(int i=0;i<c.length();i++){
//         for(int j=0;j<a.length();j++){
//             if(c[i]==a[j]){
//                 cout<<b[j];
//             }
//         }
//     }
// }


// int main()
// {
//     string _Key ="PgEfTYaWGHjDAmxQqFLRpCJBownyUKZXkbvzIdshurMilNSVOtec#@_!=.+-*/";
//     string Original ="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

//     int n;
//     cin>>n;
//     string s;
//     cin>>s;
//     if(n==1){
//         encyption(_Key,Original,s);
//     }
//     else{
//         decyption(_Key,Original,s);
//     }
//     return 0;
// }
