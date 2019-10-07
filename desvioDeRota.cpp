#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

#define Inf 2147483647/2
#define MIN(x, y) (x < y) ? x : y
#define SWAP(a,b) a^=b^=a^=b;

int main()
{
    int N, M, C, K, a, b, k, custo;
    std::list<int> aberto;
    std::list<int>::iterator it;

    while(1)
    {
        std::cin >> N >> M >> C >> K;
        if((N == 0) && (M == 0) && (C == 0) && (K == 0))
            return 0;

        int adj[N][N];
        int d[N];
        for (size_t i = 0; i < N; i++)
        {
            d[i] = Inf;
            aberto.push_back(i);
            for (size_t j = 0; j < N; j++)
            {
                adj[i][j] = Inf;
            }
        }
        
        for (size_t i = 0; i < M; i++)
        {
            std::cin >> a >> b >> k;
            if(a > b)
            {
                SWAP(a,b);
            }
            if((a >= C-1) && (b >= C-1))
            {
                adj[a][b] = adj[b][a] = k;
            }
            else if(b == a+1)
            {
                adj[a][b] = k;
            }
            else if(b >= C-1)
            {
                adj[b][a] = k;
            }
        }
        
        if(K == C-1)
        {
            custo = 0;
            aberto.clear();
        }
        else if(K < C-1)
        {
            custo = 0;
            for (size_t i = K; i < C; i++)
            {
                custo += adj[i][i+1];
            }
            aberto.clear();
        }
        else
        {
            d[K] = 0;
            while (!aberto.empty())
            {
                k = 0;
                a = Inf;
                for (it = aberto.begin(); it != aberto.end(); it++) 
                {
                    a = MIN(a, d[*it]);
                    k = (a == d[*it]) ? (*it) : k;
                }
                if(k == C-1)
                {
                    custo = d[C-1];
                    aberto.clear();
                }
                else
                {
                    aberto.remove(k);
                    for (it = aberto.begin(); it != aberto.end(); it++) 
                    {
                        custo = MIN(d[*it], d[k] + adj[k][*it]);
                        d[*it] = (custo < d[*it]) ? custo : d[*it];
                    }
                }
            }
        }
        std::cout << custo << std::endl;
    }
    return 0;
}