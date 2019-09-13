#include "grafo.hpp"

grafo::grafo() {}

void grafo::addV(int v)
{
    this->V.push_back(v);
}

void grafo::addE(int v1, int v2)
{
    int e[2];
    e[0] = v1;
    e[1] = v2;
    this->E.push_back(e);
}

void grafo::setMatrizAdj(std::vector<std::vector<int> > matrizAdj)
{
    this->matrizAdj = matrizAdj;
}

void grafo::setListaInc(std::vector<std::list<int> > listaInc)
{
    this->listaInc = listaInc;
}