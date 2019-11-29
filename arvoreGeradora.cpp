#include <iostream>

#define INF 623754001
#define MIN(x,y) (x < y) ? x : y

int main() {
    int N, M, U, V, C;
    std::cin >> N >> M;

    int VLinha[N] = {0};
    int L[N];
    //Acesso a matriz: j + N*(i)
    int adj[N*N] = {0};
    for(int i = 0; i < M; i++) {
        std::cin >> U >> V >> C;
        adj[(V-1) + N*(U-1)] = adj[(U-1) + N*(V-1)] = C;
    }

    int total = 0;

    int w, u = 0;
    int min;
    for(int i = 1; i < N; i++) {
        L[i] = (adj[i] != 0) ? adj[i] : INF-1;
    }
    VLinha[u] = 1;

    for(int faltam = N-1; faltam > 0; faltam--) {
        min = INF;
        for(int i = 0; i < N; i++) {
            if(!VLinha[i]) {
                min = MIN(min, L[i]);
                w = (min == L[i]) ? i : w;
            }
        }

        VLinha[w] = 1;
        min = INF;
        for(int i = 1; i < N; i++) {
            if(VLinha[i] && adj[i + N*w]) {
                min = MIN(min, adj[w + N*i]);
                u = (min == adj[w + N*i]) ? i : u;
            }
        }

        total += adj[u + N*w];

        for(int i = 0; i < N; i++) {
            if(!VLinha[i])
                if((L[i] > adj[i + N*w]) && adj[i + N*w])
                    L[i] = adj[i + N*w];
        }
    }

    std::cout << total << std::endl;

    return 0;
}