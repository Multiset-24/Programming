#include <bits/stdc++.h>
using namespace std;

int main() {
    char str[5]={'1','2','2','3','4'};
    cout<<(str[5])<<endl;
    char c='\0';
    cout<<c<<" "<<int(c);
    cout<<endl;
    for (int i = 0; i < 5; i++)
    {
        cout<<str[i]<<" ";
    }
    cout<<endl;
    for (int i = 0; str[i]!='\0'; i++)
    {
        cout<<str[i]<<" ";
    }
    cout<<endl;
    cout<<str;
    return 0;
}