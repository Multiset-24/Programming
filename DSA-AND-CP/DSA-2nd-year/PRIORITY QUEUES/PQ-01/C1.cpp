#include <bits/stdc++.h>
using namespace std;
// implementation of priority queues
class MaxHeap
{
    vector<int> v;
    void downheapify(int idx)
    {
        while (idx < v.size())
        {

            int lc_idx = 2 * idx + 1;
            int rc_idx = 2 * idx + 2;
            int max_idx = idx;
            if (lc_idx < v.size() && v[max_idx] < v[lc_idx])
            {
                max_idx = lc_idx;
            }

            if (rc_idx < v.size() && v[max_idx] < v[rc_idx])
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

    void pop()
    {
        if (v.empty())
            return;
        swap(v[v.size() - 1], v[0]);
        v.pop_back();
        if (!v.empty())
        {
            downheapify(0);
        }
    }

    void delete_idx(int idx){
        v[idx]=INT_MAX;
        upheapify(idx);
        pop();
    }
    MaxHeap(vector<int>&a){
        v=a;
        for (int i = 0; i < a.size(); i++)
        {
            upheapify(i);
        }
    }
};
int main()
{
    MaxHeap *Mheap = new MaxHeap(200);
    Mheap->display();
    Mheap->insert(400);
    Mheap->display();
    Mheap->insert(600);
    Mheap->display();
    Mheap->insert(800);
    Mheap->display();
    Mheap->insert(250);
    Mheap->display();
    Mheap->insert(1000);
    Mheap->display();
    Mheap->insert(900);
    Mheap->display();
    Mheap->pop();
    Mheap->display();
    Mheap->delete_idx(2);
    Mheap->display();
    Mheap->delete_idx(1);
    Mheap->display();
    vector<int>arr={400,200,900,250};
    MaxHeap* v2=new MaxHeap(arr);
    v2->display();
    return 0;
}