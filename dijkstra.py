from math import inf


def min_d(d, aberto):
    min_dist = inf
    min_idx = -1
    for i in aberto:
        if d[i] < min_dist:
            min_dist = d[i]
            min_idx = i
    return min_idx

def dijkstra(vini, adj):
    V = range(len(adj))
    d = [inf for _ in V]
    d[vini] = 0
    fechado = set()
    aberto = set(V)
    anterior = [None for _ in V]
    while aberto:
        k = min_d(d, aberto)
        fechado.add(k)
        aberto.remove(k)
        for i in aberto:
            if adj[k][i]:
                custo = min(d[i], d[k] + adj[k][i])
                if custo < d[i]:
                    d[i] = custo
                    anterior[i] = k
    return d
    

def prim(adj):
    V = set(range(len(adj)))
    T = set()
    u = 0
    Vl = {u}
    L = [inf for _ in V]
    for v in V - Vl:
        if adj[u][v]:
            L[v] = adj[u][v]
    while Vl != V:
        w = min_d(L, V - Vl)
        for vl in Vl:
            if adj[vl][w]:
                u = vl
                break
        e = (u, w, L[w])
        T.add(e)
        Vl.add(w)
        for v in V - Vl:
            if adj[v][w] and adj[v][w] < L[v]:
                L[v] = adj[v][w]
    return T


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


def ford_fulkerson(adj):
    V = range(len(adj))
    capacidade_corte = inf
    f0 = 0
    