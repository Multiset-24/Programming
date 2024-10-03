#include <bits/stdc++.h>
using namespace std;
//array of objects using pointers
 class shop_item{
    int  id ;
    float price;
    public:
    void set_data(int i,float p){
        id=i;
        price=p;
    }
    void get_data(){
        cout<<"The id of the item is "<<id<<endl;
        cout<<"The price of the item is "<<price<<endl;
    }
 };
int main() {
    int size=3;
    int *s= new int[10];//we can use increment operator to move from one element to another
    shop_item *ptr=new shop_item[size];//this dynamically creates an array of objects having size n

    return 0;
}