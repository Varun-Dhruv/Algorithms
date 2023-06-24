#include <bits/stdc++.h>
using namespace std;

// T.C -> O(V+E)
// S.C -> O(    N)

std::vector<int> topologicalSort(std::vector<std::vector<int>>& adjList, int V)
{
    std::vector<int> topoSort;
    std::vector<int> indegree(V, 0);
    std::queue<int> q;
    for (auto connectedNodes : adjList)
    {
        for (auto node : connectedNodes)
        {
            indegree[node]++;
        }
    }
    for (int node = 0; node < V; node++)
    {
        if (indegree[node] == 0)
        {
            q.push(node);
        }
    }
    while (!q.empty())
    {
        auto node = q.front();
        q.pop();
        for (auto it : adjList[node])
        {
            indegree[it]--;
            if (indegree[it] == 0)
            {
                q.push(it);
            }
        }
        topoSort.push_back(node);
    }
    return topoSort;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::vector<std::vector<int>> adj = {{}, {}, {3}, {1}, {0, 1}, {0, 2}};
    int V = 6;
    std::vector<int> topoSort = topologicalSort(adj, V);
    for (auto node : topoSort)
    {
        std::cout << node << std::endl;
    }
    return 0;
}