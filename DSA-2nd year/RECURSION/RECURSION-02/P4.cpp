#include <bits/stdc++.h>
using namespace std;
//maze path
//using 4 varibles
int maze(int sr,int sc,int er,int ec){
    if (sr>er || sc>ec)
    {
        return 0;
    }
    if(sr==er||sc==ec){
        return 1;
    }
    return maze(sr+1,sc,er,ec)+maze(sr,sc+1,er,ec);
}
//using 2 variables
int maze2(int row ,int column){
    if(row<1||column<1) return 0;
    if(row==1||column==1) return 1;
    return maze2(row-1,column)+maze2(row,column-1);
}
//print ways in the form of left and right 
void printpath(int row,int column,string s){
    if(row<1||column<1) return ;
    if(row==1&&column==1){
        cout<<s<<endl;
    }
    printpath(row-1,column,s+"Down ");
    printpath(row,column-1,s+"Right ");
}
int main() {
    cout<<maze2(3,3)<<endl;
    cout<<maze(1,1,3,3)<<endl;
    printpath(3,3,"");
    return 0;
}