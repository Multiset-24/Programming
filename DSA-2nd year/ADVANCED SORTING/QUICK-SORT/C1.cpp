#include <bits/stdc++.h>
using namespace std;
//algorithm and code of the quick sort
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
void quicksort(int arr[],int startidx,int endidx){
    if(startidx>=endidx) return;
    int partitionidx=partition(arr,startidx,endidx);
    quicksort(arr,startidx,partitionidx-1);
    quicksort(arr,partitionidx+1,endidx);
}
int main() {
   int arr[]={8,7,6,5,4,3,2,1};
   quicksort(arr,0,7);
   for (int i = 0; i < 8; i++)
   {
    cout<<arr[i]<<" ";
   }
    return 0;
}