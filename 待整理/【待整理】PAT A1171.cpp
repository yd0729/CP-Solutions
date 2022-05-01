#include <iostream>
#include <queue>

using namespace std;

struct Record {
  int val, run;

  bool operator>(const Record &r) const {
    if (run != r.run)
      return run > r.run;
    else
      return val > r.val;
  }
};

priority_queue<Record, vector<Record>, greater<Record>> pq;

int main() {
  int N, M, x;
  cin >> N >> M;

  for (int i = 0; i < M; i++) {
    cin >> x;
    pq.push({x, 1});
  }

  for (int i = 0, cur_run = 0; i < N - M or !pq.empty();) {
    Record top = pq.top();
    pq.pop();

    if (top.run == cur_run) {
      cout << " ";
    } else {
      cur_run = top.run;
      if (cur_run > 1) {
        cout << "\n";
      }
    }

    cout << top.val;

    if (i < N - M) {
      cin >> x;
      i++;
      pq.push({x, x > top.val ? cur_run : cur_run + 1});
    }
  }
}
