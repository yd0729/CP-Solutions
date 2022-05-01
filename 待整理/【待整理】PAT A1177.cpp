#include <iostream>

using namespace std;

int main() {
  string s, p;
  cin >> s >> p;

  int start = 0, len = s.length();

  for (int i = 0; i < s.length(); i++) {  // 枚举起始位置
    if (s[i] == p[0]) {
      int j = i, k = 0;
      for (; j < s.length(); j++) {
        if (s[j] == p[k]) k++;
        if (k == p.length()) break;
      }
      if (k == p.length()) {
        if (j - i + 1 < len) {
          len = j - i + 1;
          start = i;
        }
      }
    }
  }

  cout << s.substr(start, len);
}