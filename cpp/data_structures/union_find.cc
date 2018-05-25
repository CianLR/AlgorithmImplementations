#include <vector>

using namespace std;

class UnionFind {
 public:
  UnionFind(int n) : size(n, 1), parent(n, -1) {
    for (int i = 0; i < n; ++i) parent[i] = i;
  }

  bool IsJoined(int a, int b) {
    return Root(a) == Root(b);
  }

  void Join(int a, int b) {
    a = Root(a), b = Root(b);
    if (a == b) return;
    if (size[a] > size[b]) {
      size[a] += size[b];
      parent[b] = a;
    } else {
      size[b] += size[a];
      parent[a] = b;
    }
  }

 private:
  vector<int> size, parent;

  int Root(int a) {
    while (a != parent[a]) {
      parent[a] = parent[parent[a]];
      a = parent[a];
    }
    return a;
  }
};

