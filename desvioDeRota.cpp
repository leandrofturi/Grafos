#include <iostream>
#include <vector>
#include <list>

#define MIN(x, y) (x < y) ? x : y

#define Inf 250

// g++ desvioDeRota.cpp -o desvioDeRota

class Problema
{
public:
    int N;
    int M;
    int C;
    int K;
    std::vector<std::vector<int> > matAdj;

    void preencheAtributos();
    void preencheMatAdj();
    int resolucao();
    int Dijkstra(int Vini);
    int minDistancia(int V);
};


void Problema::preencheAtributos()
{
    std::cin >> this->N >> this->M >> this->C >> this->K;
    this->matAdj.resize(this->N);
    for (size_t i = 0; i < this->N; i++)
    {
        this->matAdj[i].resize(this->N);
    }
}

void Problema::preencheMatAdj()
{
    int i, j, p;
    for (size_t k = 0; k < this->M; k ++)
    {
        std::cin >> i >> j >> p;
        this->matAdj[i][j] = p;
    }
}

int Problema::resolucao()
{
    int d = 0;
    if (this->K < (C-1))
    {
        for (size_t i = this->K; i < this->C; i++)
        {
            d += this->matAdj[i][i+1];
        }
        return d;
    }
    return this->Dijkstra(K);
}

int Problema::Dijkstra(int Vini)
{
    std::vector<int> d (this->N, Inf);
    d[Vini] = 0;
    std::list<int> aberto;
    for (size_t i = 0; i < this->N; i++)
    {
        aberto.push_back(i);
    }
    aberto.remove(Vini);
    int k, custo;
    while(!aberto.empty())
    {
        k = this->minDistancia(Vini);
        aberto.remove(k);
        for (size_t i = 0; i < this->N; i++)
        {
            custo = MIN(d[i], d[k] + this->matAdj[k][i]);
            if(custo < d[i])
            {
                d[i] = custo;
            }
        }
    }
    return d[C-1];
}

int Problema::minDistancia(int V)
{
    int min = this->matAdj[V][0];
    for (size_t i = 1; i < this->N; i++)
    {
        if(min > this->matAdj[V][i])
        {
            min = this->matAdj[V][i];
        }
    }
    return min;
}

int main()
{
    Problema p;
    p.preencheAtributos();
    p.preencheMatAdj();
    std::cout << p.resolucao() << std::endl;
    return 0;
}