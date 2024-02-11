#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/clone-graph/
#define mod 1000000007


// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution {
public:

    Node* dfs(Node* node,unordered_map<Node*,Node*>&mp){
        vector<Node*>neighbour;
        Node* clone=new Node(node->val);
        mp[node]=clone;

        for(auto mem:node->neighbors){
            if(mp.find(mem)!=mp.end()){
                neighbour.push_back(mp[mem]);
            }
            else{
                neighbour.push_back(dfs(mem,mp));
            }
        }
        clone->neighbors=neighbour;

        return clone;
    }

    Node* cloneGraph(Node* node) {
        if(node==nullptr) return nullptr;
       
        if(node->neighbors.size()==0){
            Node* clone=new Node(node->val);
            return clone;
        }
        unordered_map<Node*,Node*>mp;
        return dfs(node,mp);
    }
};


int main() {
 
    return 0;
}