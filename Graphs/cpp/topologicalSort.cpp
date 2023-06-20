#include <bits/stdc++.h>
using namespace std;

void dfs(std::vector<std::vector<int>> &adjList, std::vector<int> &vis, std::stack<int> st, int src)
{
    vis[src] = 1;
    for (auto node : adjList[src])
    {
        if (!vis[node])
        {
            dfs(adjList, vis, st, node);
        }
    }
    st.push(src);
}
std::vector<int> topologicalSort(std::vector<vector<int>> adjList, int V)
{
    std::vector<int> vis(V, 0), topoSort;
    std::stack<int> st;
    for (int node = 0; node < V; node++)
    {
        if (!vis[node])
        {
            dfs(adjList, vis, st, 0);
        }
    }
    while (!st.empty())
    {
        topoSort.push_back(st.top());
        st.pop();
    }
    return topoSort;
}
int main()
{
    return 0;
}