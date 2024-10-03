#include <iostream>
using namespace std;
//class templates
template<class T>
class vector{
    public:
    T* arr;
    int size;
    vector(int m){;
    size=m;
    arr=new int[size];
    }
    T dotproduct(vector &v){
        T d=0;
        for (int i = 0; i < size; i++)
        { 
            d+=this->arr[i]*v.arr[i];
        }
            return d;
    }
};
int main() {
   vector<int>v(3);
   for (int i = 0; i < 3; i++)
   {
    cin>>v.arr[i];
   }
   vector<int>v1(3);
   for (int i = 0; i < 3; i++)
   {
    cin>>v1.arr[i];
   }
   cout<<v.dotproduct(v1);
    return 0;
}