#include <bits/stdc++.h>
using namespace std;
//https://www.hackerrank.com/challenges/primsmstsub/problem
#define mod 1000000007
#define ll long long
/*
------------------------------------------------>EXPLANATION<----------------------------------------------                                                                          
MAIN DATA STRUCTURE USED->PRIORITY QUEUE
ALOGIRTHM TYPE->GREEDY+BFS
ALGORITHM NAME->PRIM'S ALGORITHM

QUESTION->WE HAVE GIVEN A WEIGHTED UNDIRECTED GRAPH WHICH IS CONNECTED AND WE HAVE TO FIND THE SUBGRAPH HAVING MINIMUM SUM OF IT'S WEIGHTS AMONG ALL OTHER SUBGRAPHS ,THIS GRAPH IS ALSO KNOWN AS MINIMUM SPANNING TREE HAVING N-1 EDGES AND N EDGES ?

                                      1. PRIM'S ALGROTHM   
                                    /
THERE CAN BE TWO ALGORITHM TO SOLVE 
                                    \
                                      2. KRUSKAL'S ALGORITHM(ALREADY DONE IS PREVIOUS FILE)

SOLUTION USING PRIM'S ALGORITHM->WE SOMEHOW WANT TO HAVE MINIMUM COST REQUIRED TO REACH A NODE THUS WE NEED TO HAVE DS WHICH CAN INPUT TWO NODES AND ONE IS THEIR COSTS , AND AN VISITED VECTOR WHICH WILL TAKE CARE OF THE NODES WHICH HAVE BEEN VISITED SO THAT ONE NODES DOES NOT GO AGAIN TO IT'S PARENT NODE.

FIRST  START WITH A NODE SAY 0th NODE THEN WE WILL USE A QUEUE WHICH TAKE CARE OF NODE AND COST TO REACH IT AND WE WILL ALSO USE VISITOR ARRAY , INPUT THE START NODE INTO PRIORITY QUEUE OF MIN HEAP AND THEN WE WILL START A LOOP WHICH RUNS UNTIL THE LOOP AGAIN GETS EMPTY NOW FOR INSIDE LOOP POP THE FRONT ELEMENT AND THEN EXPLORE IT'S NEIGHBOUT FROM THE ADJENCENCY LIST IF IT IS VISITED THEN LEAVE IT OR IF IT'S COST IS LESS THEN THE PREVIOUS COST THAN UPDATE IT AND MARK IT AS VISITED.

------------------------------------------------------------------>THE END<------------------------------------------------------------------------------
*/
int main() {
    int n;
    cin>>n;
    vector<unordered_map<int,int>>graph(n,unordered_map<int>());

    int e;
    cin>>e;
    while(e--){
        int a,b,c;
        cin>>a>>b>>c;

        graph[a][b]=c;
        graph[b][a]=c;

    }


    return 0;
}