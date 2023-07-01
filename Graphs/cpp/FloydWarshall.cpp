#include <bits/stdc++.h>
using namespace std;
// multi source shortest path algorithm
//  helps in detecting negative cycle as well

// T.C -> O()
// S.C -> O()
std::vector<std::vector<int>> FloydWarshall(std::vector<std::vector<int>> adjMat, int V)
{
    std::vector<std::vector<int>> costs = adjMat;
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (i == j)
                costs[i][j] = 0;
            if (adjMat[i][j] == -1)
                costs[i][j] = INT_MAX;
        }
    }
    for (int via = 0; via < V; via++)
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (costs[i][via] == INT_MAX || costs[via][j] == INT_MAX)
                {
                    continue;
                }
                costs[i][j] = min(costs[i][j], costs[i][via] + costs[via][j]);
            }
        }
    }
    return costs;
}
int main()
{
    int V = 4;
    std::vector<std::vector<int>> adjMat(V, std::vector<int>(V, 0));
}