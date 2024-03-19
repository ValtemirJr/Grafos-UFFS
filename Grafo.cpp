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

bool Grafo::valida_aresta(Aresta e){
    if(e.v1 > num_vertices_ || e.v2 > num_vertices_){
        return false;
    }
    return true;
}

void Grafo::testa_aresta(Aresta e){
    if(!valida_aresta(e))
        throw(invalid_argument("Arasta invalida!"));
    return;
}

bool Grafo::tem_aresta(Aresta e){
    testa_aresta(e);

    if(matriz_adj_[e.v1][e.v2] = 1)
        return true;
    return false;
}

bool Grafo::atualizar_aresta(Aresta e, int num){
    testa_aresta(e);

    if(matriz_adj_[e.v1][e.v2] = num)
        return false;

    matriz_adj_[e.v1][e.v2] = num;    
    return true;
}

void Grafo::colocar_aresta(Aresta e){
    if(atualizar_aresta(e, 1)){
        cout << "Aresta inserida com sucesso!";
        return;
    }
    else{
        cout << "Não foi possivel";
    }
}

void Grafo::retirar_aresta(Aresta e){
    if(atualizar_aresta(e, 0)){
        cout << "Aresta retirada com sucesso!";
        return;
    }
    else{
        cout << "Não foi possivel";
    }
}