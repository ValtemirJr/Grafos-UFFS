#include "Grafo.h"
#include <exception>
#include <stdexcept>
#include <algorithm>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

Grafo::Grafo(int num_vertices) {
    if (num_vertices <= 0) {
        throw(invalid_argument("Erro no construtor Grafo(int): o numero de "
            "vertices " + to_string(num_vertices) + " eh invalido!"));
    }

    num_vertices_ = num_vertices;
    num_arestas_ = 0;

    matriz_adj_.resize(num_vertices);
    for (int i = 0; i < num_vertices; i++) { // ou i < matriz_adj_.size()
        matriz_adj_[i].resize(num_vertices, 0);
    }
}

int Grafo::num_vertices() {
    return num_vertices_;
}

int Grafo::num_arestas() {
    return num_arestas_;
}

void Grafo::insere_aresta(Aresta e) {
    try {
        valida_aresta(e);
    } catch (...) {
        throw_with_nested(runtime_error("Erro na operacao "
            "insere_aresta(Aresta): a aresta " + e.to_string() + " eh "
            "invalida!"));
    }

    if ((matriz_adj_[e.v1][e.v2] == 0) && (e.v1 != e.v2)) {
        matriz_adj_[e.v1][e.v2] = 1;
        matriz_adj_[e.v2][e.v1] = 1;

        num_arestas_++;
    }
}

void Grafo::remove_aresta(Aresta e) {
    try {
        valida_aresta(e);
    } catch (...) {
        throw_with_nested(runtime_error("Erro na operacao "
            "remove_aresta(Aresta): a aresta " + e.to_string() + " eh "
            "invalida!"));
    }

    if (matriz_adj_[e.v1][e.v2] != 0) {
        matriz_adj_[e.v1][e.v2] = 0;
        matriz_adj_[e.v2][e.v1] = 0;

        num_arestas_--;
    }
}

void Grafo::imprime() {
    for (int v = 0; v < num_vertices_; v++) { // ou v < matriz_adj_.size()
        cout << v << ":";
        for (int u = 0; u < num_vertices_; u++) { // ou u < matriz_adj_.size()
            if (matriz_adj_[v][u] != 0) {
                cout << " " << u;
            }
        }
        cout << "\n";
    }
}

void Grafo::valida_vertice(int v) {
    if ((v < 0) || (v >= num_vertices_)) {
        throw out_of_range("Indice de vertice invalido: " + to_string(v));
    }
}

void Grafo::valida_aresta(Aresta e) {
    valida_vertice(e.v1);
    valida_vertice(e.v2);
}

bool Grafo::ehConexo(){
    vector<int> marcados(num_vertices_, 0);
    return _ehConexo(marcados, 0);
}

void Grafo::busca_em_profudindade(int v, vector<int> &marcados){
    marcados[v] = 1;
        for (int u = 0; u < num_vertices_; u++)
            if (matriz_adj_[v][u] != 0)
                if (marcados[u] == 0)
                    busca_em_profudindade(u, marcados);
}

int Grafo::quantideComponentes(){
    vector<int> marcados(num_vertices_, 0);
    int quant = 1;
    int num = 0;
    while (!_ehConexo(marcados, num))
    {
        for(int i = 0; i < marcados.size(); i++){
            if(marcados[i] == 0){
                num = i;
                break;
            }
        }
        quant++;
    }
    return quant;    
}

bool Grafo::_ehConexo(vector<int> &marcados, int num){
    busca_em_profudindade(num, marcados);
    for(int x : marcados){
        if (x == 0)
            return false;
    }
    
    return true;
}