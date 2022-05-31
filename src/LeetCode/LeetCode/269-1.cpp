class Solution {
  public:
    string alienOrder(vector<string> &words) {
        edges.clear();
        states.clear();

        for (string &word : words) {
            for (auto &e : word) {
                if (!edges.count(e)) {
                    edges[e] = vector<char>();
                }
            }
        }

        valid = true;
        int len = words.size();

        for (int i = 1; i < len && valid; i++) {
            add_edge(words[i - 1], words[i]);
        }

        order = string(edges.size(), ' ');
        index = edges.size() - 1;

        for (auto [u, _] : edges) {
            if (not states.count(u)) {
                dfs(u);
            }
        }

        if (not valid) {
            return "";
        }
        return order;
    }

  private:
    unordered_map<char, vector<char>> edges;
    unordered_map<char, int> states;

    bool valid;
    string order;
    int index;

    void add_edge(string &a, string &b) {
        int len_a = a.size();
        int len_b = b.size();
        int len = min(len_a, len_b);

        int i = 0;
        while (i < len) {
            char &c1 = a[i];
            char &c2 = b[i];

            if (c1 != c2) {
                edges[c1].emplace_back(c2);
                break;
            }
            
            i++;
        }

        if (i == len and len_a > len_b) { // 后一项是前一项的前缀
            valid = false;
        }
    }

    static const int VISITING = 1;
    static const int VISITED = 2;

    void dfs(char u) {
        states[u] = VISITING;

        for (char v : edges[u]) {
            if (not states.count(v)) { // 未访问 UNVISITED
                dfs(v);
                if (not valid) {
                    return;
                }
            } else if (states[v] == VISITING) { // 出现环
                valid = false;
                return;
            }
        }

        states[u] = VISITED;

        order[index--] = u;
    }
};