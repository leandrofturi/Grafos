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
