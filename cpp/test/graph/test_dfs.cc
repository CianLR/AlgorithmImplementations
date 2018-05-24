#include <vector>

#include <gtest/gtest.h>

#include "../../graph/dfs.cc"

TEST(DFSTest, TestSingleNode) {
  vector<Node> graph;
  graph.emplace_back(10);
  ASSERT_EQ(DFS(1, graph, 0, 10), 0);
  ASSERT_EQ(DFS(1, graph, 0, 11), -1);
}

TEST(DFSTest, TestMultiNodes) {
  vector<Node> graph = {{10}, {20}, {30}, {40}};
  graph[0].AddAdj(1);
  graph[0].AddAdj(2);
  graph[1].AddAdj(3);
  graph[2].AddAdj(3);

  // Start at 0 and traverse normally.
  ASSERT_EQ(DFS(4, graph, 0, 40), 3);
  ASSERT_EQ(DFS(4, graph, 0, 30), 2);

  // Start at 1, node 3 is reachable byt 2 isn't.
  ASSERT_EQ(DFS(4, graph, 1, 40), 3);
  ASSERT_EQ(DFS(4, graph, 1, 30), -1);

  // Start at 3, nothing reachable expect itself.
  ASSERT_EQ(DFS(4, graph, 3, 40), 3);
  ASSERT_EQ(DFS(4, graph, 3, 30), -1);
}

