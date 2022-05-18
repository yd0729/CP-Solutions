class TarjanSCC {
  private:
    const vector<vector<int>> &edges;
    vector<int> low, dfn, fa;
    int timestamp = -1;
    int n;

  private:
    // Tarjan 算法求解割点模板
    void getCuttingVertex(int u, int parent, vector<int> &ans) {
        low[u] = dfn[u] = ++timestamp;
        fa[u] = parent;
        int child = 0;
        bool iscv = false;
        for (int v : edges[u]) {
            if (dfn[v] == -1) {
                ++child;
                getCuttingVertex(v, u, ans);
                low[u] = min(low[u], low[v]);
                if (!iscv && parent != -1 && low[v] >= dfn[u]) {
                    ans.push_back(u);
                    iscv = true;
                }
            } else if (v != fa[u]) {
                low[u] = min(low[u], dfn[v]);
            }
        }
        if (!iscv && parent == -1 && child >= 2) {
            ans.push_back(u);
        }
    }

  public:
    TarjanSCC(const vector<vector<int>> &_edges)
        : edges(_edges), n(_edges.size()) {}

    int check() {
        low.assign(n, -1);
        dfn.assign(n, -1);
        fa.assign(n, -1);
        timestamp = -1;

        // cutting vertices 存储割点
        vector<int> cvs;
        // connected components count 存储连通分量个数
        int cccnt = 0;
        for (int i = 0; i < n; ++i) {
            if (dfn[i] == -1) {
                ++cccnt;
                getCuttingVertex(i, -1, cvs);
            }
        }
        // 如果连通分量个数大于 1，答案为 0
        if (cccnt > 1) {
            return 0;
        }
        // 如果存在割点，答案为 1
        if (!cvs.empty()) {
            return 1;
        }
        return 2;
    }
};

class Solution {
  private:
    static constexpr int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

  public:
    int minDays(vector<vector<int>> &grid) {
        int m = grid.size();
        int n = grid[0].size();

        // 节点重标号
        int landCount = 0;
        unordered_map<int, int> relabel;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    relabel[i * n + j] = landCount;
                    ++landCount;
                }
            }
        }
        if (!landCount) {
            return 0;
        }
        if (landCount == 1) {
            return 1;
        }

        // 添加图中的边
        vector<vector<int>> edges(landCount);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    for (int d = 0; d < 4; ++d) {
                        int ni = i + dirs[d][0];
                        int nj = j + dirs[d][1];
                        if (ni >= 0 && ni < m && nj >= 0 && nj < n &&
                            grid[ni][nj] == 1) {
                            edges[relabel[i * n + j]].push_back(
                                relabel[ni * n + nj]);
                        }
                    }
                }
            }
        }

        auto scc = TarjanSCC(edges);
        return scc.check();
    }
};