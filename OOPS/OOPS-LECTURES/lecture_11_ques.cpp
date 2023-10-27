#include <bits/stdc++.h>
using namespace std;
// creata s function which takes 2 point objects and computes the distance between 2 these 2 points.
class point
{
private:
    int x, y;
    friend float distance(point o1, point o2);

public:
    point(int a, int b)
    {
        x = a;
        y = b;
    }
};
float distance(point o1, point o2)
{
    float _distance;
    _distance = sqrt(pow((o1.x - o2.x), 2) + pow((o1.y - o2.y), 2));
     return _distance;
}
int main()
{
    int x1,x2,y1,y2;
    cout<<"Enter the points- ";
    cin>>x1>>y1>>x2>>y2;
point p1(x1,y1),p2(x2,y2);
float res=distance(p1,p2);
cout<<"The distance between the points is - "<<res<<endl;
    return 0;
}
