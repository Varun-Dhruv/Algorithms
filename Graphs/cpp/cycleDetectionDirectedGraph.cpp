#include <bits/stdc++.h>
using namespace std;

bool isCycle(std::vector<std::vector<int>> &adjList, std::vector<int> &visited,
             std::vector<int> &pathVisited, int src, int parent)
{
    visited[src] = 1;
    pathVisited[src] = 1;
    for (auto node : adjList[src])
    {
        if (!visited[node])
        {
            if (isCycle(adjList, visited, pathVisited, node, src))
            {
                return true;
            }
        }
        else if (pathVisited[node])
        {
            return true;
        }
    }
    pathVisited[src] = 0;
    return false;
}
int main()
{
    return 0;
}