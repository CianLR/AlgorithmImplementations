import unittest

from graph.dfs import Node, DFS

class DFSTest(unittest.TestCase):
    def test_single_node(self):
        n = Node(1)
        self.assertIs(DFS(n, 1), n)
        self.assertIs(DFS(n, 0), None)

    def test_multi_node(self):
        graph = [Node(i) for i in xrange(10, 50, 10)]
        graph[0].add_adj(graph[1])
        graph[0].add_adj(graph[2])
        graph[1].add_adj(graph[3])
        graph[2].add_adj(graph[3])

        # Start at 0 and traverse normally.
        self.assertIs(DFS(graph[0], 40), graph[3])
        self.assertIs(DFS(graph[0], 30), graph[2])
        # Start at 1, node 3 is reachable byt 2 isn't
        self.assertIs(DFS(graph[1], 40), graph[3])
        self.assertIs(DFS(graph[1], 30), None)
        # Start at 3, nowhere reachable except itself.
        self.assertIs(DFS(graph[3], 40), graph[3])
        self.assertIs(DFS(graph[3], 30), None)

