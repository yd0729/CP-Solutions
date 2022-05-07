class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        if (start == end) {
            return 0;
        }
        
        bank.push_back(start);
        int start_id = bank.size() - 1;
        int end_id = -1;
        for (int i = 0, size = bank.size(); i < size; ++i) {
            for (int j = i + 1; j < size; ++j) {
                if (is_adj(bank[i], bank[j])) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
            if (bank[i] == end) {
                end_id = i;
            }
        }

        if (end_id == -1) {
            return -1;
        }

        queue<array<int, 2>> q;

        q.push({start_id, 0});
        visit[start_id] = true;
        
        while (not q.empty()) {
            auto [id, step] = q.front();
            q.pop();

            for (auto &e : adj[id]) {
                if (not visit[e]) {
                    if (e == end_id) {
                        return step + 1;
                    }
                    visit[e] = true;
                    q.push({e, step + 1});
                }
            }
        }

        return -1;    
    }
private:
    unordered_map<int, bool> visit;
    unordered_map<int, vector<int>> adj;

    bool is_adj(string &s1, string &s2) {
        int cnt = 0;
        
        for (int i = 0, j = 0, size = s1.size(); i < size; ++i, ++j) {
            if (s1[i] != s2[j]) {
                ++cnt;
            }
            if (cnt > 1) {
                return false;
            }
        }

        return cnt == 1;
    }
};