#include "Grafo.h"
#include <iostream>

using namespace std;

Grafo::Grafo(int num_vertices) {
    if (num_vertices <= 0) {
        throw(invalid_argument("Erro no construtor Grafo(int): o raio " +
            to_string(num_vertices) + " eh invalido!"));
    }

    matriz_adj_.resize(num_vertices);
    for (int i = 0; i < num_vertices; i++) {
        matriz_adj_[i].resize(num_vertices, 0);
    }
    num_vertices_ = num_vertices;
    num_arestas_ = 0;
}

int Grafo::num_vertices() {
    return num_vertices_;
}

int Grafo::num_arestas() {
    return num_arestas_;
}

bool Grafo::tem_aresta(Aresta aresta){
    if(aresta.v1 > num_vertices_ || aresta.v2 > num_vertices_){
        throw(invalid_argument("Aresta Inválida!"));
    }

    if(matriz_adj_[aresta.v1][aresta.v2] = 1)
        return true;
    return false;
}