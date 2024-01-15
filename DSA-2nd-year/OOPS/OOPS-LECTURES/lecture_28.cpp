#include <bits/stdc++.h>
using namespace std;
//initailisation list and initialisation section
/*
syntax for initiasation llst in constructot:
constructor(argument-list):initialisation-section{

}
*/
class test_marks{
    int physics,maths,chemistry;
    public:
    test_marks(int p,int c,int m):physics(p),maths(m){
        chemistry=c;
        cout<<" This has been called "<<endl;
    }
    void get_marks(void){
        cout<<physics<<" "<<maths<<" "<<chemistry<<endl;
    }
};
int main() {
    test_marks rohini(99,100,98);
    rohini.get_marks();
    return 0;
}