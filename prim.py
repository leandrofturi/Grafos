from math import inf


def min_d(d, aberto):
    min_dist = inf
    min_idx = -1
    for i in aberto:
        if d[i] < min_dist:
            min_dist = d[i]
            min_idx = i
    return min_idx


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
