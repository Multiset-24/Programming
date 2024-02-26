#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define F(i, a, b) for (int i = (int)(a); i <= (int)(b); i++)
#define RF(i, a, b) for (int i = (int)(a); i >= (int)(b); i--)

int main()
{
    string str1;
    string str2;

    cin>>str1>>str2;


    string result;

    F(i,0,str1.size()-1){
        int x=-48+str1[i];
        int y=-48+str2[i];

        int z=x^y;

        if(z==0){
            result.push_back('0');
        }
        else{
            result.push_back('1');
        }
    }

    cout<<result;

    return 0;
}