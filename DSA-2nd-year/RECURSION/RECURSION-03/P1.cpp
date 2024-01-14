#include <bits/stdc++.h>
using namespace std;
//Tower of hanoi 
void hanoi(int n,char S,char H,char D){
    if(n==0) return;
    hanoi(n-1,S,D,H);
    cout<<S<<"->"<<D<<endl;
    hanoi(n-1,H,S,D);
}
int main() {
    int n;
    cout<<"Enter the number of towers in the source rod- ";
    cin>>n;
    hanoi(n,'S','H','D');
    return 0;
}