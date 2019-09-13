#ifndef _GRAFO_HPP_
#define _GRAFO_HPP_

#include <iostream>
#include <vector>

class grafo
{
public:
    std::vector<int> V;
    std::vector<int*> E;
    std::vector<std::vector<int>> matrizAdj;
    //std::vector<int*> listaInc;

    grafo();
    ~grafo();

    void addV(int v);
    void addE(int e[2]);
    void setMatrizAdj(std::vector<std::vector<int>> matrizAdj);
    //void setListaInc(std::vector<int*> listaInc);
};

#endif