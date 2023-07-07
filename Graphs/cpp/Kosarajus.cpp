#include <bits/stdc++.h>
using namespace std;

void finishTime(std::vector<std::vector<int>> &adjList, int idx, std::vector<int> &vis, std::stack<int> st)
{
    if (vis[idx])
        return;
    vis[idx] = 1;
    for (auto it : adjList[idx])
    {
        finishTime(adjList, it, vis, st);
    }
    st.push(idx);
}
std::vector<int> dfs(std::vector<std::vector<int>> &adjList, int idx, std::vector<int> vis, std::vector<int> &traversal)
{
    if (vis[idx])
        return;
    vis[idx] = 1;
    traversal.push_back(idx);
    for (auto it : adjList[idx])
    {
        dfs(adjList, it, vis, traversal);
    }
}
std::vector<std::vector<int>> reverseGraph(std::vector<std::vector<int>> &adjList, int V)
{
    std::vector<std::vector<int>> reversedGraph(V, std::vector<int>());
    for (int node = 0; node < V; node++)
    {
        for (auto it : adjList[node])
        {
            reversedGraph[it].push_back(node);
        }
    }
    return reversedGraph;
}
std::vector<std::vector<int>> kosajaru(std::vector<std::vector<int>> &adjList, int V)
{
    std::vector<std::vector<int>> stronglyConnectedComponents, reversedAdjList;
    std::vector<int> visited(V, 0);
    std::stack<int> finTime;

    // sort all the edges according to finishing time
    for (int node = 0; node < V; node++)
    {
        if (visited[node])
            continue;
        finishTime(adjList, node, visited, finTime);
    }
    // reverse the edges of the graph
    reversedAdjList = reverseGraph(adjList, V);

    fill(visited.begin(), visited.end(), 0);
    // Perform a dfs traversal
    while (!finTime.empty())
    {
        int currNode = finTime.top();
        if (!visited[currNode])
        {
            vector<int> tmp;
            dfs(reversedAdjList, currNode, visited, tmp);
            stronglyConnectedComponents.push_back(tmp);
        }
    }
    return stronglyConnectedComponents;
}
int main()
{

    return 0;
}