#include <bits/stdc++.h>
using namespace std;

int main() {
    string str="Hello world";
    cout<<str[0];
    cout<<str<<" ";
    cin>>str;//can take input as a word only not a line
    cout<<str;
    getline(cin,str);// can input the line now using this
    cout<<str;
    return 0;
}