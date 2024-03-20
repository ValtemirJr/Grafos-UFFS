#include "Aresta.h"
#include "Grafo.h"
#include <iostream>

using namespace std;

int main() {
    try {
        Grafo Grafo(5);

        cout << Grafo.num_vertices() << endl;
        cout << Grafo.num_arestas() << endl;

        Aresta aresta(0, 1);
        Aresta aresta1(3, 1);
        Aresta aresta2(3, 2);
        // Aresta aresta3(3, 1);

        Grafo.colocar_aresta(aresta);
        Grafo.colocar_aresta(aresta1);
        Grafo.colocar_aresta(aresta2);
        // Grafo.colocar_aresta(aresta3);

        Grafo.imprimir_grafo();

        Grafo.imprimir_vizinhos(aresta2);
        Grafo.imprimir_vizinhos(aresta1);
        Grafo.imprimir_vizinhos(aresta);
    }
    catch (const exception &e) {
        cerr << "exception: " << e.what() << endl;
    }

    return 0;
}
