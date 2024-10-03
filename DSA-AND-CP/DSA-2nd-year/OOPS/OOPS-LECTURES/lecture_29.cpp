#include <bits/stdc++.h>
using namespace std;
//revisiting pointers and new keywords
int main() {
    int *p=new int(40);//dynamic allocation 
cout<<"The value at address p is "<<*(p)<<endl;
int *arr=new int[3];
arr[0]=12;
arr[1]=13;
arr[2]=14;
// delete arr;
delete[] arr;//this is used to delete dynamically alloted memory like array 
for (int i = 0; i < 3; i++)
{
    cout<<"The value at "<<i<<" is "<<arr[i]<<endl;
}
    return 0;
}