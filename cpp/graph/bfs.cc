#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

class Node {
 public:
  Node(int i_) : i(i_) {}

  void AddAdj(int u) {
    adj.push_back(u);
  }
  
  int i;
  vector<int> adj;
};

int BFS(const vector<Node> &graph, int start, int find) {
  queue<int> q;
  unordered_set<int> seen;
  q.push(start);
  seen.insert(start);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    if (graph[u].i == find) return u;
    for (auto &v : graph[u].adj) {
      if (seen.find(v) == seen.end()) {
        seen.insert(v);
        q.push(v);
      }
    }
  }
  return -1;
}

