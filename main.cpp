// main.cpp
#include <iostream>
#include "Graph.h" // Inclui a definição da nossa classe Graph

using namespace std;

int main() {
    Graph labirinto;

    bool sucesso = labirinto.loadFromFile("teste.txt");

    if (sucesso) {
        cout << "\n--- Verificacao dos Dados Carregados ---" << endl;

        cout << "ID do No Inicial: " << labirinto.getStartNodeId() << endl;
        cout << "ID do No Final: " << labirinto.getEndNodeId() << endl;

        cout << "\n--- Testando Heuristicas ---" << endl;
        cout << "Heuristica de 'a0': " << labirinto.getHeuristic("a0") << endl;
        cout << "Heuristica de 'b0': " << labirinto.getHeuristic("b0") << endl;
        cout << "Heuristica de 'x_inexistente': " << labirinto.getHeuristic("x") << endl;

        cout << "\n--- Testando Vizinhos ---" << endl;
        cout << "Vizinhos de 'a0':" << endl;
        try {
            for (const auto& vizinho : labirinto.getNeighbors("a0")) {
                cout << "  - Para " << vizinho.first << " com custo " << vizinho.second << endl;
            }
        } catch (const out_of_range& e) {
            cout << "  - No 'a0' nao tem vizinhos registrados ou nao existe." << endl;
        }

        cout << "Vizinhos de 'f0':" << endl;
        try {
            for (const auto& vizinho : labirinto.getNeighbors("f0")) {
                cout << "  - Para " << vizinho.first << " com custo " << vizinho.second << endl;
            }
        } catch (const out_of_range& e) {
            cout << "  - No 'f0' nao tem vizinhos registrados ou nao existe." << endl;
        }

    } else {
        cout << "Falha ao carregar o grafo. Verifique o nome do arquivo e suas permissoes." << endl;
    }

    return 0;
}