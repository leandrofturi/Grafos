#ifndef _GRAFO_HPP_
#define _GRAFO_HPP_

#include <iostream>
#include <vector>
#include <list>

class grafo
{
public:
    std::vector<int> V;
    std::vector<int*> E;
    std::vector<std::vector<int> > matrizAdj;
    std::vector<std::list<int> > listaInc;

    grafo();
    ~grafo();

    void addV(int v);
    void addE(int v1, int v2);
    void setMatrizAdj(std::vector<std::vector<int> > matrizAdj);
    void setListaInc(std::vector<std::list<int> > listaInc);
};

#endif