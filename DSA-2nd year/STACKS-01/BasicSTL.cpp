#include <bits/stdc++.h>
using namespace std;

int main() {
 stack<int>st;
 cout<<st.size()<<endl;
 st.push(4);
 st.push(10);
 st.push(40);
 st.push(30);
cout<<st.size()<<endl;
// st.pop();
cout<<st.size()<<endl;
cout<<st.top()<<endl;
//print array elemenst in reverse order

/*--------------> method 01
while (st.size()>0)
{
    cout<<st.top()<<" ";
    st.pop();
} 
*/
//after this stack is empty
/*---------------> method 02 */
stack<int>temp;
while (st.size()>0)
{
    cout<<st.top()<<" ";
    int x=st.top();
    st.pop();
    temp.push(x);
} 
//puttings leements from back to original stack
while (temp.size()>0)
{
    int x=temp.top();
    st.push(x);
    temp.pop();
} 
cout<<st.top();
    return 0;
}