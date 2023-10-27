#include <bits/stdc++.h>
using namespace std;
//quick select algorithm-- for finding kth smallest element in the code
int partition(int arr[],int startidx,int endidx){
    int pivotele=arr[(startidx+endidx)/2];
    int count=-1;
    for (int i = startidx; i <=endidx; i++)
    {
        if(arr[i]<=pivotele) count++;
     }
     int pivotidx=count+startidx;
     swap(arr[(startidx+endidx)/2],arr[pivotidx]);
     // now we use array's two pointer approach
     int i=startidx;
     int j=endidx;
     while (i<=j)
     {
        if(arr[i]<=arr[pivotidx]) i++;
        if(arr[j]>arr[pivotidx]) j--;
        else if (arr[i]>arr[pivotidx] && arr[j]<arr[pivotidx])
        {
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
        
     }
     return pivotidx;
}
int quickselect(int arr[],int startidx,int endidx,int k){
    int partitionidx=partition(arr,startidx,endidx);
    if(partitionidx+1==k) return arr[partitionidx];
else if(partitionidx+1<k) return  quickselect(arr,partitionidx+1,endidx,k);
 else return quickselect(arr,startidx,partitionidx-1,k);

}
int main() {
   int arr[]={8,7,6,5,4,-3,2,1};
   cout<<quickselect(arr,0,7,3);
    return 0;
}