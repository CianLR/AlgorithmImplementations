import unittest

from graph.bfs import Node, BFS

class TestBFS(unittest.TestCase):
    def test_empty(self):
        n = Node(0)
        self.assertIs(BFS(n, 1), None)
        self.assertIs(BFS(n, 0), n)

