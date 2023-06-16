#include <bits/stdc++.h>
using namespace std;

// this is for flood fill in 4 directions

vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
void dfs(vector<vector<int>> &image, vector<vector<int>> &visited, pair<int, int> curr,
         int finalColor, int initialColor, vector<vector<int>> &ans, int m, int n) // m and n are dimensions of matrix on which flood fill is carried
{
    int i = curr.first, j = curr.second;
    visited[i][j] = 1;
    ans[i][j] = finalColor;
    for (auto dir : directions)
    {
        int newI = i + dir[0];
        int newJ = j + dir[1];
        if (newI >= 0 && newI < m && newJ >= 0 && newJ < n && !visited[newI][newJ] && image[newI][newJ] == initialColor)
        {
            dfs(image, visited, {newI, newJ}, finalColor, initialColor, ans, m, n);
        }
    }
}
vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
{
    vector<vector<int>> ans = image;
    int m = image.size();
    int n = image[0].size();
    vector<vector<int>> visited(m, vector<int>(n, 0));
    int initialColor = image[sr][sc];
    dfs(image, visited, {sr, sc}, color, initialColor, ans, m, n);
    return ans;
}
int main()
{

    return 0;
}