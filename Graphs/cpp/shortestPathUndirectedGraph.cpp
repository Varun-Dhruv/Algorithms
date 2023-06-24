#include <bits/stdc++.h>
using namespace std;

// T.C -> O(V+E)
// S.C -> O(N)

std::vector<int> shortestPath(std::vector<std::vector<int>> adjList, int V, int src)
{
    std::vector<int> dist(V, INT_MAX), vis(V, 0);
    std::queue<int> q;
    q.push(src);
    dist[src] = 0;
    while (!q.empty())
    {
        auto node = q.front();
        q.pop();
        for (auto connectedNode : adjList[node])
        {
            if (dist[node] + 1 < dist[connectedNode])
            {
                dist[connectedNode] = dist[node] + 1;
                q.push(connectedNode);
            }
        }
    }
    return dist;
}
int main()
{
    int V = 9;
    std::vector<vector<int>> adjList = {
        {1, 3}, {0, 2}, {1, 6}, {0, 4}, {3, 5}, {4, 6}, {2, 5, 7, 8}, {6, 8}, {6, 7}};
    std::vector<int> dist = shortestPath(adjList, V, 0);
    for (auto it : dist)
    {
        std::cout << it << " ";
    }
    std::cout << "\n";
    return 0;
}