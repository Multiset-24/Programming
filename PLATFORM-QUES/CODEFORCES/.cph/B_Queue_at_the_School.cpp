#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,t;
    cin>>n>>t;

    vector<char>input(n);

    for(int i=0;i<n;i++){
        cin>>input[i];
    }

    while(t--){
        for(int i=0;i<n-1;i++){
            if(input[i]<input[i+1]){
                swap(input[i],input[i+1]);
                i++;
            }
        }
    }

    for(int i=0;i<n;i++){
        cout<<input[i];
    }
    return 0;
    
}