// #include <bits/stdc++.h>
// using namespace std;
// // find the value of k for which if that gets subtracted form each element of the array then the array gets sorted
float min(float a ,float b){
    if(a>b) return b;
    else return a;
}
float max(float a ,float b){
    if(a>b) return a;
    else return b;
}
// void kvalue(vector<int> &v)
// {
//     int n = v.size();
//     bool flag=true;
//     float Kmax=float(INT_MIN), Kmin=float(INT_MAX);
//         for (int i = 0; i < n-1; i++)
//         {
//             if(v[i+1]-v[i]>0){
//                 Kmax=min(Kmax,(v[i+1]+v[i])/2.0);
//             }
//             else{
//                 Kmin=max(Kmin,(v[i+1]+v[i])/2.0);
//             }
//              if (Kmax<Kmin) {
//                 flag=false;
//                 break;
//              }
//         }
//        if(flag==false) cout<<" no value of k exists";
//        else cout<<"The value of k is greater than "<<Kmin<<" and less than "<<Kmax;
// }
// int main()
// {
// int n;
// cin>>n;
// vector<int>v(n);
// for (int i = 0; i < n; i++)
// {
//     cin>>v[i];
// }
// kvalue(v);
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;

void kvalue(vector<int> &v) {
    int n = v.size();
    float Kmax = 0, Kmin = 0;

    for (int i = 0; i < n - 1; i++) {
        if (v[i + 1] - v[i] > 0) {
            Kmax = max(Kmax, float(v[i + 1] + v[i]) / 2.0);
        }
        else {
            Kmin = min(Kmin, float(v[i + 1] + v[i]) / 2.0);
        }
    }

    if (Kmax < Kmin) {
        cout << "No valid value of k exists" << endl;
    }
    else {
        cout << "The value of k is greater than " << Kmin << " and less than " << Kmax << endl;
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    kvalue(v);

    return 0;
}
