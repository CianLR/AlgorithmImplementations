import unittest

from graph.bfs import Node, BFS


class TestBFS(unittest.TestCase):
    def test_single_node(self):
        n = Node(0)
        self.assertIs(BFS(n, 1), None)
        self.assertIs(BFS(n, 0), n)

    def test_multi_node(self):
        graph = [Node(i) for i in xrange(10, 50, 10)]
        graph[0].add_adj(graph[1])
        graph[0].add_adj(graph[2])
        graph[1].add_adj(graph[3])
        graph[2].add_adj(graph[3])

        # Start at 0 and traverse normally.
        self.assertIs(BFS(graph[0], 40), graph[3])
        self.assertIs(BFS(graph[0], 30), graph[2])
        # Start at 1, node 3 is reachable byt 2 isn't
        self.assertIs(BFS(graph[1], 40), graph[3])
        self.assertIs(BFS(graph[1], 30), None)
        # Start at 3, nowhere reachable except itself.
        self.assertIs(BFS(graph[3], 40), graph[3])
        self.assertIs(BFS(graph[3], 30), None)
