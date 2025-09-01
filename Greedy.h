#ifndef GREEDY_H
#define GREEDY_H

#include "Graph.h"
#include "Node.h"
#include <vector>
#include <string>

using namespace std;

class Greedy{
public:
    // Função que realiza a busca
    // Entrada: Grafo, Id nó inicial, Id nó final
    // Saída: Vetor contendo o caminho
    vector<string> solve(const Graph& graph, const string& startId, const string& endId);

private:
    // Função que reconstroi o caminho percorrido
    // Entrada: nó final
    // Saída: Vetor contendo o caminho percorrido
    vector<string> reconstructPath(shared_ptr<Node> endNode);
};


#endif // ASTAR_H