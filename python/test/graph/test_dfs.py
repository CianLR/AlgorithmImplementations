import unittest

from graph.dfs import Node, DFS

class DFSTest(unittest.TestCase):
    def test_single_node(self):
        n = Node(1)
        self.assertIs(DFS(n, 1), n)
        self.assertIs(DFS(n, 0), None)

