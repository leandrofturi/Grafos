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

def dijkstra(vini, adj, sparse=False):
    print("dijkstra")
    if sparse:
        V = range(adj.shape[0])
    else:
        V = range(len(adj))
    d = [inf for _ in V]
    d[vini] = 0
    fechado = set()
    aberto = set(V)
    anterior = [None for _ in V]
    iter = 0
    n = len(V)
    while aberto:
        sys.stdout.write("\r%f" % (iter*100.0 / n))
        sys.stdout.flush()
        iter = iter+1
        k = min_d(d, aberto)
        fechado.add(k)
        aberto.remove(k)
        for i in aberto:
            if sparse:
                if adj[(k, i)]:
                    custo = min(d[i], d[k] + adj[(k, i)])
                    if custo < d[i]:
                        d[i] = custo
                        anterior[i] = k
            else:
                if adj[k][i]:
                    custo = min(d[i], d[k] + adj[k][i])
                    if custo < d[i]:
                        d[i] = custo
                        anterior[i] = k
    sys.stdout.write("\n\n")
    return d
