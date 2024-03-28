#ifndef GRAFO_H

#define GRAFO_H

#include "Aresta.h"
#include <vector>

class Grafo {
public:
    Grafo(int num_vertices);
    
    int num_vertices();
    int num_arestas();

    bool tem_aresta(Aresta e);
    bool valida_aresta(Aresta e);
    void testa_aresta(Aresta e);
    bool atualizar_aresta(Aresta e, int num);
    void colocar_aresta(Aresta e);
    void retirar_aresta(Aresta e);
    void imprimir_vizinhos();
    void imprimir_grafo();
private:
    std::vector<std::vector<int>> matriz_adj_;
    int num_vertices_;
    int num_arestas_;
};

#endif /* GRAFO_H */
