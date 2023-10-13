#include <bits/stdc++.h>
using namespace std;
//dynamic initialisation of objects
class BankDeposit{
    int principal;
    int years;
    float interestRate;
    float returnValue;

    public:
        BankDeposit(){}
        BankDeposit(int p, int y, float r); // r can be a value like 0.04
        BankDeposit(int p, int y, int r); // r can be a value like 14
        void show();
};

BankDeposit :: BankDeposit(int p, int y, float r)
{
    principal = p;
    years = y;
    interestRate = r;
    returnValue = principal;
    for (int i = 0; i < y; i++)
    {
        returnValue = returnValue * (1+interestRate);
    }
}

BankDeposit :: BankDeposit(int p, int y, int r)
{
    principal = p;
    years = y;
    interestRate = float(r)/100;
    returnValue = principal;
    for (int i = 0; i < y; i++)
    {
        returnValue = returnValue * (1+interestRate);
    }
}

void BankDeposit :: show(){
    cout<<endl<<"Principal amount was "<<principal
        << ". Return value after "<<years
        << " years is "<<returnValue<<endl;
}

int main() {
    BankDeposit bd1,bd2,bd3;
    float p,y,r;
    cout<<"Enter the principle, years and rate respectively:";
    cin>>p>>y>>r;
    bd1=BankDeposit(p,y,r);
    bd1.show();
    float P,Y,R;
    cout<<"Enter the principle, years and rate in percentage respectively:";
    cin>>P>>Y>>R;
    bd2=BankDeposit(P,Y,R);
    bd2.show();
    return 0;
}