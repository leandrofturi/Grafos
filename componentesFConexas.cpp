#include <iostream>

void buscaProfundidade(int adj[][2000], int N, int Vini, int* visitado)
{
    if(visitado[Vini] == 1) return;

    visitado[Vini] = 1;
    for(int i = 0; i < N; i++)
        if(adj[Vini][i] != 0)
            if(visitado[i] == 0)
                buscaProfundidade(adj, N, i, visitado);
}

int main()
{
    int N, M, V, W, P, conex;

    while(1)
    {
        std::cin >> N >> M;

        if((N == 0) && (M == 0)) return 0;
        
        int adj[N][2000] = {0};
        conex = 1;

        int visitado[N] = {0};
        for(int i = 0; i < M; i++)
        {
            std::cin >> V >> W >> P;
            if(P == 1)
                adj[V-1][W-1] = 1;
            else if(P == 2)
                adj[W-1][V-1] = adj[V-1][W-1] = 1;
        }

        for(int i = 0; (i < N) && (conex == 1); i++)
        {
            buscaProfundidade(adj, N, i, visitado);
            for(int j = 0; (j < N) && (conex == 1); j++)
            {
                if(visitado[j] == 0)
                    conex = 0;
                visitado[j] = 0;
            }
        }
        std::cout << conex << std::endl;
    }

    return 0;
}