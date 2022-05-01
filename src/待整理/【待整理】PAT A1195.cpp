// map 是 n * m 的
// x 是救助点
// # 不能走
// 一条指令是一个数字
// 0123 代表 北东南西
// 如果目的地不能到达，必须等待下一条指令

// 一种贪心算法
// 1. 找到 x 的单源最短路径，然后选一个最远的 A ，这个 A 是人可能在的位置
// 2. 生成从 A 到 x 的最短路径，如果最短路不唯一，就生成最小的
// 3. 计算人目前可能的位置
// 4. 如果 x 是人唯一可能在的位置，停止，否则回到 1

// 思路
// 1. bfs 计算 x 到每个点的距离，同时生成最小距离树
// 2. 更新人可能的位置，如果人只能在 x 结束。
// 3. 找到其中所有距离大的位置，生成序列。
// 4. 选择其中最小的序列，回到 2 .

#include <bits/stdc++.h>

using namespace std;

int n, m, xx, xy;

vector<vector<int>> dist(105, vector<int>(105, -1));
vector<vector<int>> next_step(105, vector<int>(105, 0));

vector<vector<bool>> possible(105, vector<bool>(105, true));
vector<vector<bool>> block(105, vector<bool>(105, false));

const int direction[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

bool is_vaild(int x, int y) {
  if (x < 0 or y < 0 or x >= n or y >= m) {
    return false;
  }

  if (block[x][y]) {
    return false;
  }

  return true;
}

vector<int> seqence(int x, int y) {
  vector<int> s;

  while (x != xx or y != xy) {
    s.push_back(next_step[x][y]);

    x += direction[s.back()][0];
    y += direction[s.back()][1];
  }

  return s;
}

void move(int &x, int &y, vector<int> &s) {
  for (auto &e : s) {
    int nx = x + direction[e][0];
    int ny = y + direction[e][1];

    if (not is_vaild(nx, ny)) {
      continue;
    }

    x = nx;
    y = ny;

    if (x == xx and y == xy) {
      return;
    }
  }
}

int main() {
#ifdef YD_DEBUG
  freopen("../in.txt", "r", stdin);
  freopen("../out.txt", "w", stdout);
#endif

  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;

    for (int j = 0; j < m; j++) {
      if (s[j] == '#') {
        possible[i][j] = false;
        block[i][j] = true;
      } else if (s[j] == 'X') {
        possible[i][j] = false;
        dist[i][j] = 0;

        xx = i;
        xy = j;
      }
    }
  }

  queue<array<int, 3>> q;
  q.push({xx, xy, 0});

  while (not q.empty()) {
    auto front = q.front();
    q.pop();

    int &x = front[0];
    int &y = front[1];
    int &d = front[2];

    for (int i = 0; i < 4; i++) {
      int nx = x + direction[i][0];
      int ny = y + direction[i][1];

      if (not is_vaild(nx, ny)) {
        continue;
      }

      if (dist[nx][ny] == -1 or dist[nx][ny] > d + 1) {
        dist[nx][ny] = d + 1;
        next_step[nx][ny] = (i + 2) % 4;

        q.push({nx, ny, d + 1});
      } else if (dist[nx][ny] == d + 1 and next_step[nx][ny] > (i + 2) % 4) {
        next_step[nx][ny] = (i + 2) % 4;
      }
    }
  }

#ifdef YD_DEBUG
  cout << "dist:\n";
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << dist[i][j] << " ";
    }
    cout << "\n";
  }
  cout << "\n";

  int test[6][2] = {{3, 0}, {3, 2}, {3, 4}, {0, 0}, {0, 4}, {1, 4}};

  for (int i = 0; i < 6; i++) {
    auto s = seqence(test[i][0], test[i][1]);
    cout << "from " << test[i][0] << "," << test[i][1] << ":";
    for (auto &e : s) {
      cout << e;
    }
    cout << "\n";
  }
#endif

  vector<int> ans;

  while (true) {
    // 检查是否应该退出
    bool has_poss = false;
    for (int i = 0; i < n and not has_poss; i++) {
      for (int j = 0; j < m and not has_poss; j++) {
        if (possible[i][j]) {
          has_poss = true;
        }
      }
    }
    if (not has_poss) {
      break;
    }

    // 找到距离最远的点，并生成最小的最短路径
    int furthest_dist = 0;
    array<int, 2> furthest_pos;
    vector<int> path, tmp_path;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (not possible[i][j]) {
          continue;
        }

        if (furthest_dist < dist[i][j]) {
          furthest_dist = dist[i][j];

          furthest_pos[0] = i;
          furthest_pos[1] = j;

          path = seqence(i, j);
        } else if (furthest_dist == dist[i][j]) {
          tmp_path = seqence(i, j);

          if (path.empty() or path > tmp_path) {
            path = tmp_path;

            furthest_pos[0] = i;
            furthest_pos[1] = j;
          }
        }
      }
    }

    // 更新答案
    for (auto &e : path) {
      ans.push_back(e);
    }

    // 更新可能的位置
    vector<vector<bool>> next_poss(105, vector<bool>(105, false));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (not possible[i][j]) {
          continue;
        }

        int x = i;
        int y = j;
        
        move(x, y, path);

        if (x == xx and y == xy) {
          continue;
        }

        next_poss[x][y] = true;
      }
    }

    possible = next_poss;
  }

  for (auto &e : ans) {
    cout << e;
  }
}
