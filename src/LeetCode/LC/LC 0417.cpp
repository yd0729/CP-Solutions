#include "leetcode.hpp"
#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights) {
        m = heights.size();
        n = heights[0].size();

        q = queue<array<int, 2>>();
        visit1 = vector<vector<bool>>(m, vector<bool>(n, 0));
        visit2 = vector<vector<bool>>(m, vector<bool>(n, 0));
        res.clear();

        for (int i = 0; i < m; i++) {
            visit1[i][0] = true;
            q.push({i, 0});
        }

        for (int i = 1; i < n; i++) {
            visit1[0][i] = true;
            q.push({0, i});
        }

        bfs(heights, visit1);

        for (int i = 0; i < m; i++) {
            visit2[i][n - 1] = true;
            q.push({i, n - 1});
        }

        for (int i = 0; i < n - 1; i++) {
            visit2[m - 1][i] = true;
            q.push({m - 1, i});
        }

        bfs(heights, visit2);

        return res;
    }

  private:
    int m, n;

    const int dx[4] = {0, 0, 1, -1};
    const int dy[4] = {1, -1, 0, 0};

    queue<array<int, 2>> q;
    vector<vector<bool>> visit1, visit2;
    vector<vector<int>> res;

    void bfs(vector<vector<int>> &heights, vector<vector<bool>> &visit) {
        while (not q.empty()) {
            auto front = q.front();
            q.pop();

            int &x = front[0];
            int &y = front[1];

            if (visit1[x][y] and visit2[x][y]) {
                res.push_back({x, y});
            }

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx < 0 or nx >= m or ny < 0 or ny >= n or visit[nx][ny]) {
                    continue;
                }

                if (heights[nx][ny] >= heights[x][y]) {
                    visit[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
    }
};