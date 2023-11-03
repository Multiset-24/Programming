#include <bits/stdc++.h>
using namespace std;
// binary to decimal and vice versa

int binary_to_decimal(string &binary){
    int n=binary.size();
    int result=0;
    for (int i = n-1; i>=0; i--)
    {
        char ch=binary[i];
        int num=ch-'0';
        result+=num*(1<<n-i-1);
    }
    return result;
}

string decimal_to_binary(int num){
    string result="";
    while(num>0){
        if(num%2==0){
            result="0"+result;//result+="0" is different from this
        }
        else{
            result="1"+result;
        }
        num/=2;
    }
    return result;
}
int main() {
    string s="11000";
    cout<<binary_to_decimal(s)<<endl;
    cout<<decimal_to_binary(64)<<" "<<(2>>1)<<" "<<(2<<1);
    return 0;
}