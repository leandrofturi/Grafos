#include <iostream> 
#include <limits.h> 
#include <string.h> 
#include <queue> 
using namespace std; 

int graph[100][100];
int rGraph[100][100];

bool bfs(int N, int parent[]) {
    bool visited[N];
    memset(visited, 0, sizeof(visited));

    queue <int> q;
    q.push(0);
    visited[0] = true;
    parent[0] = -1;
  
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
  
        for (int v = 0; v < N; v++)
        {
            if (visited[v]==false && rGraph[u][v] > 0)
            {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }

    return (visited[N-1] == true);
}

int fordFulkerson(int N) {
    int u, v;

    for (u = 0; u < N; u++)
        for (v = 0; v < N; v++)
            rGraph[u][v] = graph[u][v];

    int parent[N];

    int max_flow = 0;

    while (bfs(N, parent))
    { 
        int path_flow = INT_MAX;
        for (v = N-1; v != 0; v = parent[v])
        {
            u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }

        for (v = N-1; v != 0; v = parent[v])
        {
            u = parent[v];
            //rGraph[u][v] = rGraph[v][u] = 0;
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }

        max_flow += path_flow;
    } 

    return max_flow;
}

int main() {
    int N, M, A, B, C, D, k;
    std::cin >> N >> M;
    for(int i = 0; i < M; i++) {
        std::cin >> A >> B >> C;
        graph[A-1][B-1] = graph[B-1][A-1] = C;
    }
    std::cin >> D >> k;

    cout << "The maximum possible flow is " << fordFulkerson(N);

    return 0; 
}