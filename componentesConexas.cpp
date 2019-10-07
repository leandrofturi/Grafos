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
        int cc[V] = {0};
        for (size_t j = 0; j < E; j++)
        {
            std::cin >> a >> b;
            if(a > b)
            {
                SWAP(a, b);
            }
            if((cc[a-'a'] == 0) && (cc[b-'a'] == 0))
            {
                cont ++;
                cc[a-'a'] = cc[b-'a'] = cont;
            }
            else if(cc[a-'a'] == 0)
            {
                cc[a-'a'] = cc[b-'a'];
            }
            else if(cc[b-'a'] == 0)
            {
                cc[b-'a'] = cc[a-'a'];
            }
            else
            {
                for (size_t k = 0; k < b-'a'; k++)
                {
                    if(cc[k] == cc[b-'a'])
                    {
                        cc[k] = cc[a-'a'];
                    }
                }
                for (size_t k = b-'a'+1; k < V; k++)
                {
                    if(cc[k] == cc[b-'a'])
                    {
                        cc[k] = cc[a-'a'];
                    }
                }
                cc[b-'a'] = cc[a-'a'];
            }
        }
        std::cout << "Case #" << i+1 << ":" << std::endl;
        cont = 0;
        for (size_t j = 0; j < V; j++)
        {
            if(cc[j] == 0)
            {
                cont ++;
                std::cout << (char) (j + 'a') << "," << std::endl;
            }
            else if(cc[j] != -1)
            {
                cont ++;
                std::cout << (char) (j + 'a') << ",";
                for (size_t k = j+1; k < V; k++)
                {
                    if((cc[k] == cc[j]))
                    {
                        std::cout << (char) (k + 'a') << ",";
                        cc[k] = -1;
                    }
                }
                std::cout << std::endl;
            }
            cc[j] = -1;
        }
        std::cout << cont << " connected components" << std::endl << std::endl;
    }
    return 0;
}