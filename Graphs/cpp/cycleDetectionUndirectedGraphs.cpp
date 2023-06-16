#include <bits/stdc++.h>
using namespace std;

// cycle detection using bfs
bool isCycle(std::vector<std::vector<int>> adjList, int V, int src, std::vector<int> &visited)
{
    queue<pair<int, int>> nodeList;
    nodeList.push({src, -1});
    while (!nodeList.empty())
    {
        int node = nodeList.front().first;
        int parent = nodeList.front().second;
        visited[node] = 1;
        nodeList.pop();
        for (auto connectedNode : adjList[node])
        {
            if (!visited[connectedNode])
            {
                nodeList.push({connectedNode, node});
            }
            else
            {
                if (connectedNode == parent)
                    return true;
            }
        }
    }
    return false;
}
int main()
{
    int V = 8;
    std::vector<std::vector<int>> adjList = {{}, {2, 3}, {1, 5}, {1, 4, 6}, {3}, {2, 7}, {3, 7}, {5, 6}};
    std::vector<int> visited(V, 0);
    bool cycleExists = false;
    for (int start = 0; start < V; start++)
    {
        if (!visited[start])
        {
            if (isCycle(adjList, V, start, visited))
            {
                cycleExists = true;
                break;
            }
        }
    }
    if (cycleExists)
        std::cout << "Cycle exists" << std::endl;
    else
        std::cout << "No Cycle Exists" << std::endl;

    return 0;
}