#include <bits/stdc++.h>
using namespace std;
//find sqrt using binary search
//leetcode 69
 int mySqrt(int x) {
        if(x==0) return x;
        long long first=1;
        long long last=x;
        long long mid;
        while(first<=last){
                    mid=first+(last-first)/2;
                    if(mid==x/mid) return mid;
                    else if( mid*mid>x) last=mid-1;
                    else if( mid*mid<x) first=mid+1;
        }
        return last;
    }
int main() {
    int x;
    cin>>x;
    cout<<mySqrt(x);
    return 0;
}