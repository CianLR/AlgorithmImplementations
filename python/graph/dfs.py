from collections import deque

class Node:
    def __init__(self, i):
        self.i = i
        self.adj = []

    def add_adj(self, v):
        self.adj.append(v)


def DFS(start, find):
    q = deque([start])
    seen = set([start])
    while q:
        u = q.pop()
        if u.i == find:
            return u
        for v in u.adj:
            if v not in seen:
                seen.add(v)
                q.append(v)
    return None

