#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Node {
  string name;
  vector<Node *> children;
  Node *parent;
};

bool dfs(string &id, Node *file, vector<string> &path) {
  if (file->name == id) {
    for (auto i = path.begin(); i != path.end(); i++) {
      cout << *i;
      if (i + 1 != path.end())
        cout << "->";
      else
        cout << "\n";
    }
    return true;
  }

  bool found = false;
  for (auto &child : file->children) {
    path.push_back(child->name);
    found = found or dfs(id, child, path);  // TODO 这个 or 是不必要的吧
    path.pop_back();

    if (found) return true;
  }

  return false;
}

int main() {
  int N;
  cin >> N;

  cin.get();

  Node *file_tree = nullptr, *cur;
  for (int i = 0, depth = 0; i < N; i++) {
    string s;
    getline(cin, s);

    int indent = 0;
    while (s[indent] == ' ') ++indent;

    s = s.substr(indent);

    if (file_tree == nullptr) {
      file_tree = new Node{s, {}, nullptr};
      cur = file_tree;
    } else {
      while (depth > indent - 1) {
        cur = cur->parent;
        depth--;
      }

      cur->children.push_back(new Node{s, {}, cur});
      cur = cur->children.back();

      depth = indent;
    }
  }

  int K;
  cin >> K;

  for (int i = 0; i < K; i++) {
    string id;
    cin >> id;

    vector<string> path = {file_tree->name};
    if (not dfs(id, file_tree, path)) {
      cout << "Error: " << id << " is not found.\n";
    }
  }
}