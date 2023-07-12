import gzip
import time
import os.path
import requests
from prim import prim
from scipy import sparse
from kruskal import kruskal
from dijkstra import dijkstra
from datetime import timedelta
from ford_fulkerson import ford_fulkerson


def load_adj(url):
    filename = url.split("/")[-1]
    if not os.path.isfile(filename):
        with open(filename, "wb") as f:
            r = requests.get(url)
            f.write(r.content)
    with gzip.open(filename, 'rb') as f:
        file_content = f.read().decode('utf-8')
    la = [tuple([int(i)-1 for i in a.split(" ")[1:]]) for a in file_content.split("\n") if a.startswith("a")]
    n = max(max(i[0] for i in la), max(i[1] for i in la)) + 1
    adj = sparse.lil_matrix((n, n))
    for ed in la:
        adj[(ed[0], ed[1])] = ed[2] + 1
    return adj, la


def load_adj_from_str(str):
    file_content = str
    la = [[int(i)-1 for i in a.split(" ")[1:]] for a in file_content.split("\n") if a.startswith("a")]
    n = max(max(i[0] for i in la), max(i[1] for i in la)) + 1
    adj = [[0 for _ in range(n)] for _ in range(n)]
    for ed in la:
        adj[ed[0]][ed[1]] = ed[2] + 1
    return adj


################################################################################
# TOY 1 ########################################################################
################################################################################

toy1 = [
#    a   b   c   d   e   f   g   h   i   j
    [00, 60, 54, 42, 00, 00, 00, 00, 00, 00], # a
    [60, 00, 00, 71, 00, 29, 00, 00, 00, 00], # b
    [54, 00, 00, 56, 67, 00, 00, 00, 00, 00], # c
    [42, 71, 56, 00, 26, 52, 87, 00, 00, 00], # d
    [00, 00, 67, 26, 00, 00, 70, 00, 73, 00], # e
    [00, 29, 00, 52, 00, 00, 20, 25, 00, 00], # f
    [00, 00, 00, 87, 70, 20, 00, 36, 59, 32], # g
    [00, 00, 00, 00, 00, 25, 36, 00, 00, 25], # h
    [00, 00, 00, 00, 73, 00, 59, 00, 00, 26], # i
    [00, 00, 00, 00, 00, 00, 00, 25, 26, 00]  # j
]
dijkstra(0, toy1)
prim(toy1)
kruskal(toy1)


################################################################################
# TOY 2 ########################################################################
################################################################################

toy2 = [
#    1  2  3  4  5  6
    [0, 3, 3, 0, 0, 0], # 1
    [0, 0, 1, 3, 2, 0], # 2
    [0, 0, 0, 5, 0, 0], # 3
    [0, 0, 0, 0, 0, 6], # 4
    [0, 0, 0, 3, 0, 3], # 5
    [0, 0, 0, 0, 0, 0], # 6
]
ford_fulkerson(0, 5, toy2)


################################################################################
# NY ###########################################################################
################################################################################

url = "http://www.diag.uniroma1.it/challenge9/data/USA-road-d/USA-road-d.NY.gr.gz"
NY, la_NY = load_adj(url)

start = time.time()
d = dijkstra(0, NY, sparse=True)
end = time.time()
print(str(timedelta(seconds=end - start)))

start = time.time()
p = prim(NY, sparse=True)
end = time.time()
print(sum([x[2] for x in p]))
print(str(timedelta(seconds=end - start)))

start = time.time()
k = kruskal(NY, la=la_NY, sparse=True)
end = time.time()
print(sum([x[2] for x in k]))
print(str(timedelta(seconds=end - start)))

################################################################################
# BAY ##########################################################################
################################################################################

url = "http://www.diag.uniroma1.it/challenge9/data/USA-road-d/USA-road-d.BAY.gr.gz"
BAY, la_BAY = load_adj(url)

start = time.time()
d = dijkstra(0, BAY, sparse=True)
end = time.time()
print(str(timedelta(seconds=end - start)))

start = time.time()
p = prim(BAY, sparse=True)
end = time.time()
print(sum([x[2] for x in p]))
print(str(timedelta(seconds=end - start)))

start = time.time()
k = kruskal(BAY, la=la_BAY, sparse=True)
end = time.time()
print(sum([x[2] for x in k]))
print(str(timedelta(seconds=end - start)))


################################################################################
# COL ##########################################################################
################################################################################

url = "http://www.diag.uniroma1.it/challenge9/data/USA-road-d/USA-road-d.COL.gr.gz"
COL, la_COL = load_adj(url)

start = time.time()
d = dijkstra(0, COL, sparse=True)
end = time.time()
print(str(timedelta(seconds=end - start)))

start = time.time()
p = prim(COL, sparse=True)
end = time.time()
print(sum([x[2] for x in p]))
print(str(timedelta(seconds=end - start)))

start = time.time()
k = kruskal(COL, la=la_COL, sparse=True)
end = time.time()
print(sum([x[2] for x in k]))
print(str(timedelta(seconds=end - start)))


################################################################################
# DIMACS_ex ####################################################################
################################################################################

str = """
c This is a simple example file to demonstrate the DIMACS
c input file format for maximum flow problems. The solution
c vector is [5,10,5,0,5,5,10,5] with cost at 15.
c Problem line (nodes, links)
p max 6 8
c source
n 1 s
c sink
n 6 t
c Arc descriptor lines (from, to, capacity)
a 1 2 5
a 1 3 15
a 2 4 5
a 2 5 5
a 3 4 5
a 3 5 5
a 4 6 15
a 5 6 5
c
c End of file
"""

DIMACS_ex = load_adj_from_str(str)

ford_fulkerson(0, 5, DIMACS_ex)
