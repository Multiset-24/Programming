#include <bits/stdc++.h>
using namespace std;
// single inheritence
class students
{
private:
    int _class;
    int roll_no;
    int admission_no;

public:
    int setclass(int c);
    int setrollno(int r);
    int setadmsnno(int an);
};
int students::setclass(int c)
{
    return _class = c;
}
int students::setrollno(int r)
{
    return roll_no = r;
}
int students::setadmsnno(int an)
{
    return admission_no = an;
}
class monitors : public students
{
    int class_strength;
    int position;

public:
    void getcs(){
        cin>>class_strength;
    }
    void getps(){
        cin>>position;
    }
    void display(int c, int r, int an)
    {
        cout << setrollno(r) << " " << setclass(c) << " " << setadmsnno(an);
        cout << " The class strength is " << class_strength << "and monitor's position is " << position << endl;
    }
};
int main()
{
monitors m1,m2;
m1.getcs();
m1.getps();
m1.display(12,35,1930);

m2.getcs(); 
m2.getps();
m2.display(11,43,2023);
    return 0;

}