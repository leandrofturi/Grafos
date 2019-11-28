#include <iostream>

#define INF 1073741823
#define MIN(x,y) (x < y) ? x : y

int main() {
    int N, M, U, V, C;
    scanf(" %d %d", &N, &M);

    int VLinha[N] = {0};
    int L[N] = {0};
    //Acesso a matriz: j + N*(i)
    int adj[N*N] = {0};
    for(int i = 0; i < M; i++) {
        scanf(" %d %d %d", &U, &V, &C);
        adj[(V-1) + N*(U-1)] = adj[(U-1) + N*(V-1)] = C;
    }

    int total = 0;

    int w = 0, u = 0;
    int min;
    VLinha[0] = 1;
    for(int i = 0; i < N; i++)
        L[i] = adj[i];

    for(int faltam = N-1; faltam > 0; faltam--) {
        min = INF;
        for(int i = 0; i < N; i++) {
            if(!VLinha[i] && !adj[u + N*i]) {
                min = MIN(min, L[i]);
                w = (min == L[i]) ? w : i;
            }
        }
        VLinha[w] = 1;

        min = INF;
        for(int i = 0; i < N; i++) {
            if(!VLinha[i] && !adj[i + N*w]) {
                min = MIN(min, adj[w + N*i]);
                u = (min == adj[w + N*i]) ? u : i;
            }
        }

        total += adj[u + N*w];

        for(int i = 0; i < N; i++) {
            if(!VLinha[i] && (adj[i + N*w] < L[i]) && !adj[i + N*w])
                L[i] = adj[i + N*w];
        }
    }

    printf("%d\n", total);
}