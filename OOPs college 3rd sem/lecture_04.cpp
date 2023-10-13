#include <bits/stdc++.h>
using namespace std;
class shop{
    int itemId[100];
    int itemPrice[100];
    int counter;
    public:
    void initcounter(void){counter=0;}
    void setprice(void);
    void displayprice(void);
};
void shop:: setprice(void){
    cout<<"enter ID of your item no "<<counter+1<<endl;
    cin>>itemId[counter];
    cout<<"enter the price of your item"<<endl;
    cin>>itemPrice[counter];
    counter++;
}
void shop::displayprice(void){
    for (int i = 0; i < counter; i++)
    {
        cout<<"the price of item with id "<<itemId[i]<<" is"<<itemPrice[i]<<endl;
    }
    
}
int main() {
    shop dukaan;
    dukaan.initcounter();
    int n;
    cout<<"enter the number of items:";
    cin>>n;
   cout<<endl;
   for (int i = 0; i < n; i++)
   {
    dukaan.setprice();
   }
   dukaan.displayprice();
    return 0;
}