import heapq

class Node:
    def __init__(self, i):
        self.i = i
        self.adj = []

    def add_adj(self, v, c):
        self.adj.append((v, c))


def Dijkstra(start, end):
    pq = [(0, start)]
    dist = {start: 0}
    while pq:
        d, u = heapq.heappop(pq)
        if dist[u] < d:
            continue
        if u.i == end:
            return d
        for v, c in u.adj:
            if v in dist and dist[v] <= d + c:
                continue
            dist[v] = d + c
            heapq.heappush(pq, (d + c, v))
    return -1

