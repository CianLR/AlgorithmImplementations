#include <deque>
#include <unordered_set>
#include <vector>

using namespace std;

class Node {
 public:
  Node(int _i) : i(_i) {}
  void AddAdj(int v) {
    adj.push_back(v);
  }
  int i;
  vector<int> adj;
};

int DFS(int N, const vector<Node> &graph, int start, int find) {
  vector<bool> seen(N, false);
  deque<int> q;
  q.push_front(start);
  seen[start] = true;
  while (!q.empty()) {
    int u = q.front();
    q.pop_front();
    if (graph[u].i == find) return u;
    for (auto &v : graph[u].adj) {
      if (!seen[v]) {
        seen[v] = true;
        q.push_front(v);
      }
    }
  }
  return -1;
}

