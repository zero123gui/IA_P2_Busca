#include "Graph.h"

using namespace std;

// Adiciona uma aresta/nó no grafo
void Graph::addEdge(const string& from, const string& to, int cost, bool is_oriented){
    // Adiciona a conexão
    adj[from].push_back({to, cost});

    // Se nao orientado ent adiciona a conexão de volta
    if(is_oriented==false){
        adj[to].push_back({from, cost});
    }
}

// Define o valor da heurística de um nó
void Graph::setHeuristic(const string& node, int value){
    heuristics[node] = value;
}

// Retorna o valor da heurística de um nó
int Graph::getHeuristic(const string& node) const{
    // Verifica se tem heurística pro nó, senão retorna 0
    if(heuristics.count(node)){
        return heuristics.at(node);
    }
    
    return 0;
}

// Retorna uma lista de vizinhos de um nó
const vector<pair<string, int>>& Graph::getNeighbors(const string& node) const{
    // Se o nó não existir retorna uma exceção
    return adj.at(node);
}