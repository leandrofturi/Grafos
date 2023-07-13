import sys
from math import inf


def min_d(d, aberto):
    min_dist = inf
    min_idx = -1
    for i in aberto:
        if d[i] < min_dist:
            min_dist = d[i]
            min_idx = i
    return min_idx


def prim(adj, sparse=False):
    print("prim")
    if sparse:
        V = set(range(adj.shape[0]))
    else:
        V = set(range(len(adj)))
    T = set()
    u = 0
    Vl = {u}
    L = [inf for _ in V]
    for v in V - Vl:
        if sparse:
            if adj[(u, v)]:
                L[v] = adj[(u, v)]
        else:
            if adj[u][v]:
                L[v] = adj[u][v]
    iter = 0
    n = len(V)
    while Vl != V:
        sys.stdout.write("\r%f" % (iter*100.0 / n))
        sys.stdout.flush()
        iter = iter+1
        w = min_d(L, V - Vl)
        for vl in Vl:
            if sparse:
                if adj[(vl, w)]:
                    u = vl
                    break
            else:
                if adj[vl][w]:
                    u = vl
                    break
        e = (u, w, L[w])
        T.add(e)
        Vl.add(w)
        for v in V - Vl:
            if sparse:
                if adj[(v, w)] and adj[(v, w)] < L[v]:
                    L[v] = adj[(v, w)]
            else:
                if adj[v][w] and adj[v][w] < L[v]:
                    L[v] = adj[v][w]
    sys.stdout.write("\n\n")
    return T
