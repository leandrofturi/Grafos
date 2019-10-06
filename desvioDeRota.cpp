#include <iostream>
#include <list>

#define Inf 251
#define MIN(x, y) (x < y) ? x : y

// g++ desvioDeRota.cpp -o desvioDeRota

int main()
{
    int N, M, C, K, i, j, k, aux, custo, sair;
    while(1)
    {
        sair = 1;
        scanf(" %d %d %d %d", &N, &M, &C, &K);
        if(!((4 <= N <= 250) && (3 <= M <= N*(N-1)/2) && (2 <= C <= N-1) && (C <= K <= N-1)))
            return 0;

        int matAdj[N][N], d[N];
        for(i = 0; i < N; i ++)
            for(j = 0; j < i; j ++)
                matAdj[i][j] = matAdj[j][i] = Inf;

        for(aux = 0; aux < M; aux ++)
        {
            scanf(" %d %d %d", &i, &j, &k);
            if(!((0 <= i) && (j <= N-1) && (i != j) && (0 <= k <= 250)))
                return 0;
            matAdj[i][j] = matAdj[j][i] = k;
        }
        if(K < C-1)
        {
            d[C-1] = 0;
            for(aux = K; aux < C; aux ++)
                d[C-1] += matAdj[aux][aux+1];
            std::cout << d[C-1] << std::endl;
            sair = 0;
        }
        else
        {
            for(aux = 0; aux < N; aux ++)
                d[aux] = Inf; 
            d[K] = 0;
            std::list<int> aberto;
            std::list<int>::iterator itr;
            for(aux = 0; aux < N; aux ++)
                aberto.push_back(aux);
            while((!aberto.empty()) && sair)
            {
                k = 0;
                aux = Inf;
                for (itr = aberto.begin(); itr != aberto.end(); itr++) 
                {
                    aux = MIN(aux, d[*itr]);
                    k = (aux == d[*itr]) ? (*itr) : k;
                }
                if(k == C-1)
                {
                    std::cout << d[C-1] << std::endl;
                    sair = 0;
                }
                else
                {
                    aberto.remove(k);
                    for (itr = aberto.begin(); itr != aberto.end(); itr++) 
                    {
                        custo = MIN(d[*itr], d[k] + matAdj[k][*itr]);
                        d[*itr] = (custo < d[*itr]) ? custo : d[*itr];
                        if(*itr < C-1)
                        {
                            for(aux = (*itr)+1; aux < C-1; aux ++)
                                d[*itr] += matAdj[aux-1][aux];
                        }
                    }
                }
            }
        }
    }
    return 0;
}