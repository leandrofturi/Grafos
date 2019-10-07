#include <iostream>

#define SWAP(a,b) a^=b^=a^=b;

int main()
{
    int N, V, E, cont;
    char a, b;

    std::cin >> N;
    for (size_t i = 0; i < N; i++)
    {
        cont = 0;
        std::cin >> V >> E;
        int aux[V] = {0};
        for (size_t j = 0; j < E; j++)
        {
            std::cin >> a >> b;
            if((aux[a-'a'] == 0) && (aux[b-'a'] == 0))
            {
                cont ++;
                aux[a-'a'] = aux[b-'a'] = cont;
            }
            else if(aux[a-'a'] == 0)
            {
                aux[a-'a'] = aux[b-'a'];
            }
            else
            {
                aux[b-'a'] = aux[a-'a'];
            }
        }

        std::cout << "Case #" << i+1 << ":" << std::endl;
        for (size_t j = 0; j < V; j++)
        {
            if(aux[j] == 0)
            {
                cont ++;
                std::cout << (char) (j + 'a') << ",";
                std::cout << std::endl;
            }
            else if(aux[j] != -1)
            {
                std::cout << (char) (j + 'a') << ",";
                for (size_t k = j+1; k < V; k++)
                {
                    if((aux[j] == aux[k]) && (aux[k] != -1))
                    {
                        std::cout << (char) (k + 'a') << ",";
                        aux[k] = -1;
                    }
                }
                std::cout << std::endl;
            }
            aux[j] == -1;
        }
        std::cout << cont << " connected components" << std::endl << std::endl;
    }
    std::cout << std::endl;
    return 0;
}