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
        Aresta aresta3(3, 2);

        Grafo.colocar_aresta(aresta);
        Grafo.colocar_aresta(aresta1);
        Grafo.colocar_aresta(aresta2);
        Grafo.retirar_aresta(aresta2);

        Grafo.imprimir_grafo();

        Grafo.imprimir_vizinhos();

        cout << endl <<Grafo.num_arestas() << endl;
    }
    catch (const exception &e) {
        cerr << "exception: " << e.what() << endl;
    }

    return 0;
}
