#include <gtest/gtest.h>

#include "../../data_structures/union_find.cc"

using namespace std;

TEST(UnionFindTest, TestAllDisjoint) {
  const int n = 10;
  UnionFind uf(n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      ASSERT_EQ(uf.IsJoined(i, j), i == j);
    }
  }
}

TEST(UnionFindTest, TestSimpleJoins) {
  UnionFind uf(10);
  uf.Join(1, 3);
  ASSERT_TRUE(uf.IsJoined(1, 3));
  ASSERT_TRUE(uf.IsJoined(3, 1));
  ASSERT_FALSE(uf.IsJoined(1, 2));
  uf.Join(6, 7);
  ASSERT_TRUE(uf.IsJoined(6, 7));
  ASSERT_FALSE(uf.IsJoined(1, 7));
}

TEST(UnionFindTest, TestChainedJoins) {
  UnionFind uf(10);
  uf.Join(1, 2);
  uf.Join(2, 3);
  uf.Join(3, 4);
  ASSERT_TRUE(uf.IsJoined(1, 4));
  ASSERT_TRUE(uf.IsJoined(3, 1));
  uf.Join(8, 3);
  ASSERT_TRUE(uf.IsJoined(1, 8));
  ASSERT_TRUE(uf.IsJoined(4, 8));
}

