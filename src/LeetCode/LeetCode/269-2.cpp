class Solution {
  public:
    string alienOrder(vector<string> &words) {

        for (string &word : words) {
            for (auto &e : word) {
                if (!edges.count(e)) {
                    edges[e] = vector<char>();
                }
            }
        }

        int len = words.size();
        for (int i = 1; i < len && valid; i++) {
            add_edge(words[i - 1], words[i]);
        }

        if (!valid) {
            return "";
        }

        queue<char> q;
        for (auto [u, _] : edges) {
            if (not in_degrees.count(u)) {
                q.emplace(u);
            }
        }

        string order;
        while (!q.empty()) {
            char u = q.front();
            q.pop();

            order.push_back(u);

            for (char v : edges[u]) {
                in_degrees[v] -= 1;
                if (in_degrees[v] == 0) {
                    q.emplace(v);
                }
            }
        }
        return order.size() == edges.size() ? order : "";
    }

  private:
    unordered_map<char, vector<char>> edges;
    unordered_map<char, int> in_degrees;

    bool valid = true;

    void add_edge(string &a, string &b) {
        int len_a = a.size();
        int len_b = b.size();
        int len = min(len_a, len_b);

        int index = 0;
        while (index < len) {
            char &c1 = a[index];
            char &c2 = b[index];
            if (c1 != c2) {
                edges[c1].emplace_back(c2);
                in_degrees[c2] += 1;
                break;
            }
            index++;
        }

        if (index == len and len_a > len_b) {
            valid = false;
        }
    }
};