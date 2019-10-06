#include <iostream>
#include <vector>

#define SWAP(a,b) a^=b^=a^=b;

int main()
{
    int N = 1, V, E, cont;
    char a, b;

    std::cin >> N;
    for (size_t i = 0; i < N; i++)
    {
        cont = 0;
        std::cin >> V >> E;
        std::vector<int> adj[V];
        int aux[V];
        
        for(size_t j = 0; j < E; j++)
        {
            std::cin >> a >> b;
            if(a > b)
                SWAP(a,b);
            adj[(a-'a')].push_back((b-'a'));
            aux[(b-'a')] = 1;
        }
        std::cout << "Case #" << i+1 << ":" << std::endl;
        for(size_t k = 0; k < V; k++)
        {
            if(aux[k] != 1)
            {
                cont ++;
                std::cout << (char) (k+'a') << ",";
            
                for(size_t l = 0; l < adj[k].size(); l++)
                {
                    std::cout << (char) (adj[k][l]+'a') << ",";
                }
                std::cout << std::endl;
            }
        }
        std::cout << cont << " connected components" << std::endl;
        std::cout << std::endl;
    }
    
    return 0;
}