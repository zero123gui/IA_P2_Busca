#ifndef GRAPH_H
#define GRAPH_H

#include <string>
#include <vector>
#include <unordered_map>
#include <utility>

using namespace std;

class Graph{
private:
    // Mapa do grafo, ex:
    // "a0" -> { {"b0", 95}, {"c0", 44} }
    unordered_map<string, vector<pair<string, int>>> adj;

    // Heurísticas de cada nó, ex:
    // "a0" -> 15
    unordered_map<string, int> heuristics;

    // Nó de inicio do grafo
    string start_node_id;
    
    // Nó final do grafo
    string end_node_id;

    // Orientação do grafo
    bool is_oriented = false;

public:
    // Adiciona uma aresta/nó no grafo
    void addEdge(const string& from, const string& to, int cost, bool is_oriented);

    // Define o valor da heurística de um nó
    void setHeuristic(const string& node, int value);

    // Retorna o valor da heurística de um nó
    int getHeuristic(const string& node) const;

    // Retorna uma lista de vizinhos de um nó
    const vector<pair<string, int>>& getNeighbors(const string& node) const;

    // Carrega o grafo a partir de um arquivo texto
    bool loadFromFile(const string& filename);

    // Retorna o nó inicial
    string getStartNodeId() const;

    // Retorna o nó final
    string getEndNodeId() const;

    // Retorna o conteúdo de uma string do arquivo 
    string getContent(const string& line);
};

#endif //GRAPH_H