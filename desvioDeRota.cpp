#include <iostream>
#include <vector>

// g++ desvioDeRota.cpp -o desvioDeRota

class Problema;

int main()
{
    return 0;
}

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
    int dykstra();
};

void Problema::preencheAtributos()
{
    std::cin >> this->N >> this->M >> this->C >> this->K;
    for (size_t i = 0; i < this->N; i++)
    {
        this->matAdj[i].resize(this->N);
    }
}

void Problema::preencheMatAdj()
{
    int i, j, p;
    for (size_t i = 0; i < this->M; i ++)
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
    return this->dykstra();
}

int Problema::dykstra()
{

}