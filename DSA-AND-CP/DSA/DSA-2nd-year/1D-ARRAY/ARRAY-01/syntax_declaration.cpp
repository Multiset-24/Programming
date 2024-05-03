#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[]={2,3,24,13,23,234,234455,9};
    cout<<sizeof(arr)/sizeof(arr[0]);
    cout<<&arr<<" "<<&arr[0]<<" "<<&arr[1];
    return 0;
}