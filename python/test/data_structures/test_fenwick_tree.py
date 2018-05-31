import unittest

from data_structures.fenwick_tree import FenwickTree


class FenwickTreeTest(unittest.TestCase):
    def test_all_empty(self):
        ft = FenwickTree(10)
        for i in xrange(10):
            self.assertEqual(ft.sum_to(i), 0)
            for j in xrange(i + 1, 10):
                self.assertEqual(ft.sum_range(i, j), 0)

    def test_sum_to(self):
        ft = FenwickTree(6)
        eg_array = [1, 4, -5, 2, 7, 4]
        for i, v in enumerate(eg_array):
            ft.add(i, v)
        for i in xrange(6):
            self.assertEqual(ft.sum_to(i), sum(eg_array[:i + 1]))

    def test_sum_range(self):
        ft = FenwickTree(6)
        eg_array = [23, 12, -43, 21, 2, 9]
        for i, v in enumerate(eg_array):
            ft.add(i, v)
        for i in xrange(6):
            for j in xrange(i + 1, 6):
                self.assertEqual(ft.sum_range(i, j),
                                 sum(eg_array[i + 1:j + 1]))

    def test_random_insertion_order(self):
        ft1, ft2 = FenwickTree(6), FenwickTree(6)
        eg_array = [-17, 12, 39, 11, 26, -18]
        # Insert in order
        for i, v in enumerate(eg_array):
            ft1.add(i, v)
        # Insert in random order
        random_order = [2, 0, 5, 1, 4, 3]
        for i in random_order:
            ft2.add(i, eg_array[i])
        # Check that order doesn't matter
        for i in xrange(6):
            self.assertEqual(ft1.sum_to(i), ft2.sum_to(i))
