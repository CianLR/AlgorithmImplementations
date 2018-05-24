#include <vector>

#include <gtest/gtest.h>

#include "../../graph/dfs.cc"

TEST(DFSTest, TestSingleNode) {
  vector<Node> graph;
  graph.emplace_back(10);
  ASSERT_EQ(DFS(1, graph, 0, 10), 0);
  ASSERT_EQ(DFS(1, graph, 0, 11), -1);
}

