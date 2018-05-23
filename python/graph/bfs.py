from collections import deque

class Node:
    def __init__(self, i):
        self.i = i
        self.adj = []

    def add_adj(self, a):
        self.adj.append(a)


def BFS(start, find):
    q = deque([start])
    seen = set([start])
    while q:
        u = q.popleft()
        if u.i == find:
            return u
        for v in u.adj:
            if v.i not in seen:
                seen.add(v.i)
                q.append(v)
    return None

