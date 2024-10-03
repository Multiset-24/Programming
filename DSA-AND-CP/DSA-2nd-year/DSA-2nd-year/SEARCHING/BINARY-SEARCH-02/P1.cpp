#include <bits/stdc++.h>
using namespace std;
//leetcode 852 mountain peak problem
int peakIndexInMountainArray(vector<int>& arr) {
        int n=arr.size();
        int lo=1;
        int hi=n-2;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
              if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]) return mid;
              else if(arr[mid]>arr[mid-1]) lo=mid+1;
              else if(arr[mid]<arr[mid-1]) hi=mid-1;
        }
        return 0;
    }
int main() {
 int n;
 cin>>n;
 vector<int>v(n);
 peakIndexInMountainArray(v);
    return 0;
}