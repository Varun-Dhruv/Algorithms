#include <bits/stdc++.h>
using namespace std;

// T.C -> O(E(Log(V)))

// S.C -> O(V+E)
std::vector<int> dijkstra(std::vector<std::vector<std::pair<int, int>>> adjList, int V, int src)
{
    std::vector<int> dist(V, INT_MAX);
    std::priority_queue<pair<int, int>, std::vector<pair<int, int>>, std::greater<pair<int, int>>> pq;
    dist[src] = 0;
    pq.push({0, src});
    while (!pq.empty())
    {
        auto node = pq.top().second;
        auto dis = pq.top().first;
        pq.pop();
        for (auto it : adjList[node])
        {

            if (dis + it.second < dist[it.first])
            {
                dist[it.first] = dist[node] + it.second;
                pq.push({dist[node] + it.second, it.first});
            }
        }
    }
    return dist;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::vector<std::vector<std::pair<int, int>>> adjList = {{{1, 1}, {2, 6}},
                                                             {{0, 1}, {2, 3}},
                                                             {{0, 6}, {1, 3}}};

    int src = 2, V = 3;
    std::vector<int> dist = dijkstra(adjList, V, src);
    for (auto it : dist)
    {
        std::cout << it << " ";
    }
    std::cout << "\n";
    return 0;
}