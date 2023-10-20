#include <bits/stdc++.h>
using namespace std;

int main() {
    string str="padhle bhai pyaar vyaar dhokha hai";
    int len=str.length();//for the length of the array
    cout<<endl<<len<<endl<<str.size()<<endl;
    str.push_back('H');//for the addition of characters into strings
    cout<<str<<endl;
    // str.push_back("hello");  not valid
    str.pop_back();//removal of last character
    cout<<str;
    str=str+" okay";//'+' is used to append an strings or character to a string
    cout<<endl<<str;
    reverse(str.begin(),str.begin()+6);//reverse function
    cout<<endl<<str<<endl;
    cout<<str.substr(1,7);//subset function
    int x=69;
    str=to_string(x);//used to input integer in the strings
    cout<<endl<<str;
    for (int i = 0; i < str.length(); i++)
    {
        cin>>str.at(i);
    }
    cout<<str;
    return 0;
}