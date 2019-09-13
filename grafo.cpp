#include "grafo.hpp"

grafo::grafo() {}

grafo::~grafo()
{
    for(size_t i = 0; i < E.size(); i++)
    {
        delete E[i];
    }
}

void grafo::addV(int v)
{
    this->V.push_back(v);
}

void grafo::addE(int e[2])
{
    this->E.push_back(e);
}

void grafo::setMatrizAdj(std::vector<std::vector<int>> matrizAdj)
{
    this->matrizAdj = matrizAdj;
}

/*
void grafo::setListaInc(std::vector<std::vector<int> listaInc)
{
    this->listaInc = listaInc;
}
*/