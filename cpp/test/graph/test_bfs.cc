#include <vector>

#include <gtest/gtest.h>

#include "../../graph/bfs.cc"

using namespace std;

TEST(BFSTest, TestSingleNode) {
  vector<Node> graph;
  graph.emplace_back(10);
  ASSERT_EQ(BFS(graph, 0, 100), -1);
  ASSERT_EQ(BFS(graph, 0, 10), 0);
}

