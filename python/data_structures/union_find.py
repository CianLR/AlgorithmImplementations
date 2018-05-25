
class UnionFind:
    def __init__(self, N):
        self.N = N
        self.parent = range(N)
        self.size = [0] * N

    def _root(self, a):
        while a != self.parent[a]:
            self.parent[a] = self.parent[self.parent[a]]
            a = self.parent[a]
        return a

    def is_joined(self, a, b):
        return self._root(a) == self._root(b)

    def join(self, a, b):
        a = self._root(a)
        b = self._root(b)
        if a == b:
            return
        if self.size[b] > self.size[a]:
            a, b = b, a  # Ensure a is the bigger tree
        self.size[a] += self.size[b]
        self.parent[b] = a


