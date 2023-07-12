class DisjointSet:
    def __init__(self, n):
        self.parent = list(range(n))
        self.rank = [0 for _ in range(n)]
    def find(self, v):
        if self.parent[v] != v:
            self.parent[v] = self.find(self.parent[v])
        return self.parent[v]
    def union(self, v1, v2):
        root1 = self.find(v1)
        root2 = self.find(v2)
        if self.rank[root1] < self.rank[root2]:
            self.parent[root1] = root2
        elif self.rank[root1] > self.rank[root2]:
            self.parent[root2] = root1
        else:
            self.parent[root2] = root1
            self.rank[root1] += 1


def kruskal(adj):
    V = set(range(len(adj)))
    E = []
    for i in V:
        for j in V:
            if adj[i][j]:
                E.append((i, j, adj[i][j]))
    E = sorted(E, key=lambda x: x[-1])
    ds = DisjointSet(len(adj))
    T = set()
    for e in E:
        if ds.find(e[0]) != ds.find(e[1]):
            ds.union(e[0], e[1])
            T.add(e)
    return T
