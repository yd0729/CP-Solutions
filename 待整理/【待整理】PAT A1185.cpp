/* PAT A1185.cpp
 * 
 * Author: Author
 * Created: Thu Mar 03 2022
 */

#ifdef YD_DEBUG
#include <cstdio>
#define debug(x) cout << #x << " = " << (x) << endl;
#else
#define debug(x)
#endif

#include <bits/stdc++.h>

using namespace std;

#define MAX_SIZE 10005

struct Node{
  int val, rank, id;
} hat[MAX_SIZE], person[MAX_SIZE];

void sort_by_val(Node x[], int n) {
  sort(x, x + n, [](Node &a, Node &b) { return a.val < b.val; });

  for (int i = 0; i < n; i++) {
    x[i].rank = i;
  }
}

void sort_by_id(Node x[], int n) {
  sort(x, x + n, [](Node &a, Node &b) { return a.id > b.id; });
}

int main() {
#ifdef YD_DEBUG
  // 这种方法不能重定向 scanf 和 printf
  // ifstream fin("../in.txt");
  // ofstream fout("../out.txt");

  // streambuf *old_cin;
  // old_cin = cin.rdbuf(fin.rdbuf());
  // streambuf *old_cout;
  // old_cout = cout.rdbuf(fout.rdbuf());

  freopen("../in.txt", "r", stdin);
  freopen("../out.txt", "w", stdout);
#endif

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> hat[i].val;
    hat[i].id = i + 1;
  }

  for (int i = 0; i < n; i++) {
    cin >> person[i].val;
    person[i].id = i + 1;
  }

  sort_by_val(hat, n);
  sort_by_id(hat, n);

  sort_by_val(person, n);

  for (int i = 0; i < n; i++) {
    cout << person[hat[i].rank].id << (i == n - 1 ? "" : " ");
  }

#ifdef YD_DEBUG
  // cin.rdbuf(old_cin);
  // cout.rdbuf(old_cout);
  // fin.close();
  // fout.close();
#endif
}