#include <bits/stdc++.h>
using namespace std;

// T.C -> O(Elog(E))
// S.C -> O(E)
//  Prims Algorithm
/*
 It returns a vector that contains the list of edges of MST in the form {u,v,wt}
*/
std::vector<std::vector<int>> primsMST(std::vector<std::vector<std::pair<int, int>>> &adjList, int V)
{
    std::vector<int> visited(V, 0);
    priority_queue<
        pair<int, pair<int, int>>,
        vector<pair<int, pair<int, int>>>,
        greater<pair<int, pair<int, int>>>>
        pq; // {edgeWt,{currNode,parent}}
    pq.push({0, {0, -1}});
    int mstSum = 0;
    std::vector<std::vector<int>> mst;
    while (!pq.empty())
    {
        auto it = pq.top();
        int currNode = it.second.first;
        int edW = it.first;
        int parent = it.second.second;
        pq.pop();
        if (visited[currNode]) // if the node is already visited ignore it
            continue;
        mstSum += edW;                          // add the edge wt to mst sum
        mst.push_back({parent, currNode, edW}); // add the edge to MST
        visited[currNode] = 1;                  // mark the node as visited;
        for (auto edge : adjList[currNode])
        {
            int neigNode = edge.first;
            int wt = edge.second;
            if (visited[neigNode])
                continue;
            pq.push({wt, {neigNode, currNode}}); /*ig the neighbouring node is not visited
                                                    add it to priority queue*/
        }
    }
    return mst;
}

// Kruskals Algorithm
// T.C ->O()
// S.C ->O()
// edges =={wt,{u,v}}
std::vector<std::vector<int>> kruskals(std::vector<vector<int>> edges, int V)
{
    
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}