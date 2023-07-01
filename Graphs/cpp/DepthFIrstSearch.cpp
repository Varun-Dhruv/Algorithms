#include <bits/stdc++.h>
using namespace std;

// T.C -> O(E+V)
std::vector<int> dfs(std::vector<std::vector<int>> &adjList, int V, int curr, std::vector<int> &dfsTraversal, std::vector<int> &visited)
{
    visited[curr] = 1;
    dfsTraversal.push_back(curr);
    for (auto connectedNode : adjList[curr])
    {
        if (!visited[connectedNode])
        {
            dfs(adjList, V, connectedNode, dfsTraversal, visited);
        }
    }
    return;
}
int main()
{
    return 0;
}