import unittest

from graph.dijkstra import Node, Dijkstra


class DijkstraTest(unittest.TestCase):
    def test_single_node(self):
        n = Node(1)
        self.assertEqual(Dijkstra(n, 1), 0)
        self.assertEqual(Dijkstra(n, 2), -1)

    def test_paths(self):
        nodes = [Node(i) for i in xrange(10, 50, 10)]
        nodes[0].add_adj(nodes[1], 2)
        nodes[0].add_adj(nodes[2], 5)
        nodes[1].add_adj(nodes[3], 3)
        nodes[2].add_adj(nodes[3], 1)

        self.assertEqual(Dijkstra(nodes[0], 40), 5)
        self.assertEqual(Dijkstra(nodes[0], 50), -1)
        self.assertEqual(Dijkstra(nodes[2], 40), 1)
