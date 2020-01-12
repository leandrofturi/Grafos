#include <iostream>

#define INF 500001

int caminhoMax(int N, int M, int G[][100]) {
    int v, w, wAnt[M] = {0}, i, j, max, fluxoMin, tabu[N] = {0}, nTabu = 0, fluxoTabu[M];
    fluxoTabu[0] = fluxoMin = 0;
    wAnt[0] = w = 0;
        for(j = 1; j < M; j++) {
            v = 0;
            max = -1;
            for(i = 0; i < N; i++) {
                if((G[w][i] != INF) && (G[w][i] > max) && !tabu[i]) {
                    v = i;
                    max = G[w][v];
                }
            }
            
            if(v == 0) {
                j--;
                if(j < 0)
                    return 0;
                tabu[v] = 1;
                nTabu++;
                v = w;
                w = wAnt[j];
                fluxoMin = fluxoTabu[j];
                if(nTabu == N)
                    return 0;
            }

            else {
                fluxoTabu[j] = fluxoMin;
                fluxoMin += G[w][v];
                G[w][v] -= fluxoMin;
                G[v][w] -= fluxoMin;
                tabu[v] = 1;
                wAnt[j] = w;
                w = v;

                if(v == N-1)
                    return fluxoMin;
            }
        }

    return 0;
}

int main() {
    int N, M, A, B, C, D, k, i, j, f, d, instancia = 1, sobram;
    long precoFinal;

    while(!std::cin.eof()) {
        std::cin >> N >> M;
        if(std::cin.eof()) break;

        int G[N][100];
        int fluxoMin[N];
        for(i = 0; i < N; i++)
            for(j = i; j < N; j++)
                G[i][j] = G[j][i] = INF;
        
        for(i = 0; i < M; i++) {
            std::cin >> A >> B >> C;
            G[A-1][B-1] = G[B-1][A-1] = C;
        }
        std::cin >> D >> k;

        precoFinal = 0;
        f = -1;
        while(1) {
            f++;
            fluxoMin[f] = caminhoMax(N, M, G);
            if(!fluxoMin[f])
                break;
        }
        sobram = D;
        for (i = f-1; i >= 0; i--) {
            if(sobram > k) {
                precoFinal += fluxoMin[i]*k;
                sobram -= k;
            }
            else {
                precoFinal += fluxoMin[i]*sobram;
                if(precoFinal > 1000000000000000) {
                    printf("Instancia %d\nimpossivel\n\n", instancia);
                }
                else
                    printf("Instancia %d\n%d\n\n", instancia, precoFinal);
                break;
            }
        }
        if(((sobram > 0) && (i == -1)) || (precoFinal > 1000000000000000)) {
            printf("Instancia %d\nimpossivel\n\n", instancia);
        }

        instancia++;
    }

    return 0; 
}