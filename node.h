#ifndef NODE_H
#define NODE_H

#include <string>
#include <memory>

using namespace std;

struct Node {
    
    string id; //id do nó atual
    int g_cost; //custo pra chegar (g(n))
    int h_cost; //custo da heurística (h(n))
    int f_cost; //custo total (f(n) = g(n) + h(n))

    shared_ptr<Node> parent; //ponteiro pro no pai

    // Construtor do nó
    // Entrada: id do nó, custo para chegar g, heurística h, ponteiro para o pai
    // Saída: nó preenchido
    Node(string id, int g, int h, shared_ptr<Node> p = nullptr)
        : id(id), g_cost(g), h_cost(h), f_cost(g+h), parent(p) {}
    
};

#endif //NODE_H