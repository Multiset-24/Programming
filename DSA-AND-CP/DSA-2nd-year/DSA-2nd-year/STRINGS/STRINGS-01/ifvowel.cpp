#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    getline(cin,s);
   int  vowels=0;
int i=0;
    while(s[i]!='\0'){
        if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
            vowels++;
        }
        i++;
    }
    cout<<vowels;
    return 0;
}