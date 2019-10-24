#include <iostream>
#include <list>

#define Inf 2147483647
#define MIN(x,y) (x < y) ? x : y

int main()
{
    int N, M, A, B, C, R, E, custo, k, a;
    std::list<int> aberto;
    std::list<int>::iterator it;

    while(!std::cin.eof())
    {
        std::cin >> N >> M;

        int adj[N][N];
        int d[N];
        for(int i = 0; i < N; i++)
        {
            d[i] = Inf;
            aberto.push_back(i);
            for(int j = i; j < N; j++)
                adj[i][j] = adj[j][i] = Inf;
        }
        
        for(int i = 0; i < M; i++)
        {
            std::cin >> A >> B;
            adj[A-1][B-1] = adj[B-1][A-1] = 1;
        }
        std::cin >> C >> R >> E;
        for(int i = 0; i < N; i++)
            adj[E-1][i] = adj[i][E-1] = Inf;
        
        d[C-1] = 0;
        while(!aberto.empty())
        {
            k = 0;
            a = Inf;
            for (it = aberto.begin(); it != aberto.end(); it++) 
            {
                a = MIN(a, d[*it]);
                k = (a == d[*it]) ? (*it) : k;
            }
            if(k == R-1)
            {
                custo = d[R-1];
                aberto.clear();
            }
            else
            {
                aberto.remove(k);
                for (it = aberto.begin(); it != aberto.end(); it++) 
                {
                    custo = MIN(d[*it], d[k] + adj[k][*it]);
                    if(custo < 0) custo = Inf;
                    d[*it] = (custo < d[*it]) ? custo : d[*it];
                }
            }
        }
        std::cout << custo << std::endl;
    }
    return 0;
}