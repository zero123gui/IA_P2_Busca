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
    // Entrada: id de um nó, id de um nó, custo para ir, orientado ou não
    // Saída: aresta adiciona entre um par de nós
    void addEdge(const string& from, const string& to, int cost, bool is_oriented);

    // Define o valor da heurística de um nó
    // Entrada: nó do grafo, valor da heuristica
    // Saída: heurística associada ao nó
    void setHeuristic(const string& node, int value);

    // Retorna o valor da heurística de um nó
    // Entrada: nó do grafo
    // Saída: valor da heurística de um nó
    int getHeuristic(const string& node) const;

    // Retorna uma lista de vizinhos de um nó
    // Entrada: nó do grafo
    // Saída: vetor que contém nome e valor dos nós adjacentes
    const vector<pair<string, int>>& getNeighbors(const string& node) const;

    // Carrega o grafo a partir de um arquivo texto
    // Entrada: nome do arquivo
    // Saída: boleano que diz se deu certo ou não
    bool loadFromFile(const string& filename);

    // Retorna o nó inicial
    // Entrada: -------
    // Saída: nó inicial do grafo
    string getStartNodeId() const;

    // Retorna o nó final
    // Entrada: -------
    // Saída: nó final do grafo
    string getEndNodeId() const;

    // Retorna o conteúdo de uma string do arquivo 
    // Entrada: linha do arquivo
    // Saída: retorna o conteúdo dessa linha
    string getContent(const string& line);
};

#endif //GRAPH_H