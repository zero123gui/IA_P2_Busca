#ifndef GRAPH_H
#define GRAPH_H

#include <string>
#include <vector>
#include <unordered_map>
#include <utility>

class Graph{
public:
    // Adiciona uma aresta/nó no grafo
    void addEdge(const std::string& from, const std::string& to, int cost, bool is_oriented);

    // Define o valor da heurística de um nó
    void setHeuristic(const std::string& node, int value);

    // Retorna o valor da heurística de um nó
    int getHeuristic(const std::string& node) const;

    // Retorna uma lista de vizinhos de um nó
    const std::vector<std::pair<std::string, int>>& getNeighbors(const std::string& node) const;

private:
    // Mapa do grafo, ex:
    // "a0" -> { {"b0", 95}, {"c0", 44} }
    std::unordered_map<std::string, std::vector<std::pair<std::string, int>>> adj;

    // Heurísticas de cada nó, ex:
    // "a0" -> 15
    std::unordered_map<std::string, int> heuristics;
};

#endif //GRAPH_H