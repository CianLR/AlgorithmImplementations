#include <vector>

#include <gtest/gtest.h>

#include "../../graph/dijkstra.cc"

using namespace std;

TEST(DijkstraTest, TestSingleNode) {
  vector<Node> graph = {{0}};
  ASSERT_EQ(Dijkstra(1, graph, 0, 0), 0);
}

TEST(DijkstraTest, TestPaths) {
  vector<Node> graph = {{10}, {20}, {30}, {40}};
  graph[0].AddAdj(1, 2);
  graph[0].AddAdj(1, 2);
  graph[1].AddAdj(3, 3);
  graph[2].AddAdj(3, 1);

  ASSERT_EQ(Dijkstra(4, graph, 0, 3), 5);
  ASSERT_EQ(Dijkstra(4, graph, 2, 3), 1);
  ASSERT_EQ(Dijkstra(4, graph, 1, 2), -1);
}

