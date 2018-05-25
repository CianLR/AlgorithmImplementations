import unittest

from data_structures.union_find import UnionFind

class UnionFindTest(unittest.TestCase):
    def test_all_disjoint(self):
        n = 10
        uf = UnionFind(n)
        for i in xrange(n):
            for j in xrange(n):
                # Must only be joined if i == j
                self.assertEqual(uf.is_joined(i, j), i == j)

    def test_simple_joins(self):
        uf = UnionFind(10)
        uf.join(1, 3)
        self.assertTrue(uf.is_joined(1, 3))
        self.assertFalse(uf.is_joined(1, 2))
        uf.join(6, 7)
        self.assertTrue(uf.is_joined(6, 7))
        self.assertFalse(uf.is_joined(1, 7))

    def test_chained_joins(self):
        uf = UnionFind(10)
        uf.join(1, 2)
        uf.join(2, 3)
        uf.join(3, 4)
        self.assertTrue(uf.is_joined(1, 4))
        self.assertTrue(uf.is_joined(3, 1))
        self.assertFalse(uf.is_joined(0, 1))
        uf.join(8, 3)
        self.assertTrue(uf.is_joined(1, 8))
        self.assertTrue(uf.is_joined(4, 8))

