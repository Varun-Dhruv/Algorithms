#include <bits/stdc++.h>
using namespace std;

// single source
std::vector<int> bfs(std::vector<std::vector<int>> &adjList, int V, int src, std::vector<int> &visited)
{
    std::queue<int> nodeList;
    vector<int> bfsTraversal;
    nodeList.push(src);
    while (!nodeList.empty())
    {
        int currNode = nodeList.front();
        bfsTraversal.push_back(currNode);
        visited[currNode] = true;
        nodeList.pop();
        for (auto connectedNode : adjList[currNode])
        {
            if (!visited[connectedNode])
            {
                nodeList.push(connectedNode);
            }
        }
    }
    return bfsTraversal;
}

// multi source
std::vector<int> bfs(std::vector<std::vector<int>> &adjList, int V, std::vector<int> srcList)
{
    std::queue<int> nodeList;
    std::vector<int> visited(V, 0);
    vector<int> bfsTraversal;
    for (auto src : srcList)
        nodeList.push(src);
    while (!nodeList.empty())
    {
        int currNode = nodeList.front();
        bfsTraversal.push_back(currNode);
        visited[currNode] = true;
        for (auto connectedNode : adjList[currNode])
        {
            if (!visited[connectedNode])
            {
                nodeList.push(connectedNode);
            }
        }
    }
    return bfsTraversal;
}
int main()
{

    return 0;
}
