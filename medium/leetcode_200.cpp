// 200. Number of Islands
// https://leetcode.com/problems/number-of-islands/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <utility>

class Solution
{
public:
    int numIslands(std::vector<std::vector<char>>& grid)
    {
        int count = 0;
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        int r = grid.size(), c = grid[0].size();
        bool visited[300][300] = {false};

        for (int i = 0; i < r; ++i)
        {
            for (int j = 0; j < c; ++j)
            {
                if (grid[i][j] == '0' || visited[i][j]) { continue; }
                ++count;
                std::cout << count << ' ' << i << ' ' << j << '\n';
                std::queue<std::pair<int, int>> q;
                visited[i][j] = true;
                q.push({i, j});

                while (!q.empty())
                {
                    std::pair<int, int> curLoc = q.front(); q.pop();

                    for (int dir = 0; dir < 4; ++dir)
                    {
                        int x = curLoc.first + dx[dir];
                        int y = curLoc.second + dy[dir];
                        if (x < 0 || y < 0 || x >= r || y >= c) { continue; }
                        if (visited[x][y] || grid[x][y] != '1') { continue; }
                        visited[x][y] = true;
                        q.push({x, y});
                    }
                }
            }
        }
        return count;
    }
};