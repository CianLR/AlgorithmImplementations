#include <queue>
#include <functional>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

class Node {
 public:
  Node(int _i) : i(_i) {}
  void AddAdj(int v, int c) {
    adj.emplace_back(v, c);
  }
  vector<pair<int, int>> adj;
  int i;
};

int Dijkstra(int N, const vector<Node> &graph, int s, int t) {
  priority_queue<pair<int, int>,
                 vector<pair<int, int>>,
                 greater<pair<int, int>>> pq;
  vector<int> dist(N, -1);
  pq.emplace(0, s);
  dist[s] = 0;
  int u, d, v, c;
  while (!pq.empty()) {
    tie(d, u) = pq.top();
    pq.pop();
    if (dist[u] < d) continue;
    if (u == t) break;
    for (auto &e : graph[u].adj) {
      tie(v, c) = e;
      if (dist[v] == -1 || dist[v] > d + c) {
        dist[v] = d + c;
        pq.emplace(d + c, v);
      }
    }
  }
  return dist[t];
}

