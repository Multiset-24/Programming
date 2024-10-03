#include <bits/stdc++.h>
using namespace std;
class MaxHeap
{
    vector<int> v;
    void downheapify(int idx,int &bound)
    {
        while (idx <=bound)
        {

            int lc_idx = 2 * idx + 1;
            int rc_idx = 2 * idx + 2;
            int max_idx = idx;
            if (lc_idx <=bound && v[max_idx] < v[lc_idx])
            {
                max_idx = lc_idx;
            }

            if (rc_idx <=bound && v[max_idx] < v[rc_idx])
            {
                max_idx = rc_idx;
            }
            if (max_idx != idx)
            {
                swap(v[max_idx], v[idx]);
                idx = max_idx;
            }
            else
                break;
        }
    }
    void upheapify(int child_idx)
    {
        int parent_idx = floor((child_idx - 1) / 2);
        while (v[parent_idx] < v[child_idx] && child_idx > 0)
        {
            swap(v[parent_idx], v[child_idx]);
            child_idx = parent_idx;
            parent_idx = floor((child_idx - 1) / 2);
        }
    }

public:
    MaxHeap(int val)
    {
        v.push_back(val);
    }

    void insert(int val)
    {
        v.push_back(val);
        int n = v.size();
        int child_idx = n - 1;
        upheapify(child_idx);
    }

    void display()
    {
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i] << " ";
        }
        cout << endl;
    }

    void pop(int i)
    {
        if (v.empty())
            return;
        swap(v[i], v[0]);
        i--;
        if (!v.empty())
        {
            downheapify(0,i);
        }
    }

    void delete_idx(int idx)
    {
        v[idx] = INT_MAX;
        upheapify(idx);
        pop(v.size());
    }
    MaxHeap(vector<int> &a)
    {
        v = a;
        int j=a.size()-1;
        for (int i = a.size() / 2; i >= 0; i--)
        {
            // now the time complexity is O(n) approximately
            downheapify(i,j);
        }
    }

    vector<int>HeapSort(){
        int n=v.size()-1;
        while(n!=0){
            int s=0;
            swap(v[0],v[n]);
            n--;
            downheapify(0,n);
        }
        return v;
    }

};

vector<int>heapsort(vector<int>&v){
    MaxHeap* ans=new MaxHeap(v);
    v=ans->HeapSort();
    return v;
}
//implementation of heap sort

//this is just the modifies version of selection sort having time complexity of O(nlogn)
int main() {
    vector<int>v={10,2,4,-1,0,-100,99};
    v=heapsort(v);
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    
    return 0;
}