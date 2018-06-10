#include <vector>
#include <gtest/gtest.h>

#include "../../data_structures/fenwick_tree.cc"

using namespace std;

TEST(FenwickTreeTest, TestAllEmpty) {
  FenwickTree ft(10);
  for (int i = 0; i < 10; ++i) {
    ASSERT_EQ(ft.SumTo(i), 0);
    for (int j = i + 1; j < 10; ++j)
      ASSERT_EQ(ft.SumRange(i, j), 0);
  }
}

TEST(FenwickTreeTest, TestEndElements) {
  FenwickTree ft(10), ft2(10);
  ft.Add(9, 1);
  ASSERT_EQ(ft.SumTo(9), 1);
  ft2.Add(0, 1);
  ASSERT_EQ(ft2.SumTo(0), 1);
}

TEST(FenwickTreeTest, TestSumTo) {
  FenwickTree ft(10);
  vector<int> eg_array = {1, 4, -5, 2, 7, 4};
  for (size_t i = 0; i < eg_array.size(); ++i) {
    ft.Add(i, eg_array[i]);
  }
  int sum = 0;
  for (size_t i = 0; i < eg_array.size(); ++i) {
    sum += eg_array[i];
    ASSERT_EQ(ft.SumTo(i), sum);
  }
}

TEST(FenwickTreeTest, TestSumRange) {
  FenwickTree ft(10);
  vector<int> eg_array = {-17, 12, 39, 11, 26, -18};
  for (size_t i = 0; i < eg_array.size(); ++i) {
    ft.Add(i, eg_array[i]);
  }
  for (size_t i = 0; i < eg_array.size(); ++i) {
    int sum = 0;
    for (size_t j = i + 1; j < eg_array.size(); ++j) {
      sum += eg_array[j];
      ASSERT_EQ(ft.SumRange(i, j), sum);
    }
  }
}

