#include <bits/stdc++.h>
using namespace std;
/*You have n coins and you want to build a staircase with these coins. The staircase consists of k
rows where the ith row has exactly i coins. The last row of the staircase may be incomplete.
Given the integer n, return the number of complete rows of the staircase you will build.*/
int seedhinumber(int n)
{
    int i=1;
    int num=0;
    while (n>0)
    {
        if(n>=i){
            n-=i;
            num++;
        }
        else{
            n=0;
        }
        i++;
    }
    return num;
}
int main()
{
    int n;
    cin >> n;
    cout << seedhinumber(n);
    return 0;
}