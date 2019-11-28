#include <iostream>

int INF = 1073741823;

int fixo[500];
int custo[500];

int main() {
    int N, M, U, V, C;
    scanf(" %d %d", &N, &M);

    int adj[N][N] = {0};
    for(int i = 0; i < M; i++) {
        scanf(" %d %d %d", &U, &V, &C);
        adj[U-1][V-1] = adj[V-1][U-1] = C;
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }

    int total = 0;

    for(int i=0; i<N; i++) {
        fixo[i] = 0;
        custo[i] = INF;
    }
    custo[0] = 0;

    for(int faltam = N; faltam > 0; faltam --) {
        int no = -1;
        for(int i = 0; i < N; i ++)
            if(!fixo[i] && (no == -1 || custo[i] < custo[no]))
                no = i;
        fixo[no] = 1;

        if(custo[no] == INF) {
            total = INF;
            break;
        }
        total += custo[no];

        for(int i=0; i<N; i++)
            if(custo[i] > adj[no][i])
            custo[i] = adj[no][i];
        }

    printf("%d\n", total);
}