#include "Aresta.h"
#include "Grafo.h"
#include <iostream>

using namespace std;

int main() {
    try {
        Grafo Grafo(5);

        cout << Grafo.num_vertices() << "\n";
        cout << Grafo.num_arestas() << "\n";;

        Aresta aresta(6, 1);
        bool tem = Grafo.tem_aresta(aresta);

        if(tem)
            cout << "tem";
        else
            cout << "não tem";
    }
    catch (const exception &e) {
        cerr << "exception: " << e.what() << "\n";
    }

    return 0;
}
