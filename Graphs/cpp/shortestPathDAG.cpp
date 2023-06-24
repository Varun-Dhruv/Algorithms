#include <bits/stdc++.h>
using namespace std;

// here adjList is denoted by a  2d vector of a pairs where the first denotes node and second denotes edge wt;
std::vector<int> topologicalSort(std::vector<std::vector<std::pair<int, int>>> &adjList, int V)
{
    std::vector<int> topoSort;
    std::vector<int> indegree(V, 0);
    std::queue<int> q;
    for (int node = 0; node < V; node++)
    {
        for (auto it : adjList[node])
        {
            indegree[it.first]++;
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
            indegree[it.first]--;
            if (indegree[it.first] == 0)
            {
                q.push(it.first);
            }
        }
        topoSort.push_back(node);
    }
    return topoSort;
}
std::vector<int> shortestPath(std::vector<vector<std::pair<int, int>>> &adjList, int V, int src)
{
    std::vector<int> dist(V, INT_MAX);
    dist[src] = 0;
    std::vector<int> topoSort = topologicalSort(adjList, V);
    for (auto node : topoSort)
    {
        for (auto it : adjList[node])
        {
            int v = it.first;
            int wt = it.second;
            if (dist[node] + wt < dist[v])
                dist[v] = dist[node] + wt;
        }
    }
    return dist;
}
int main()
{
    int V = 7;
    std::vector<std::vector<std::pair<int, int>>> graphSampleFirst = {{{1, 2}, {4, 1}}, {{2, 3}}, {{3, 6}}, {}, {{2, 2}, {5, 4}}, {{3, 1}}};
    std::vector<std::vector<std::pair<int, int>>> graphSampleSecond = {{{4, 2}, {5, 3}}, {{3, 1}}, {{3, 3}}, {}, {{2, 1}, {6, 3}}, {{4, 1}}, {{1, 2}}};
    vector<int> dist = shortestPath(graphSampleSecond, V, 0);
    for (auto it : dist)
    {
        std::cout << it << " ";
    }
    std::cout << "\n";
    return 0;
}