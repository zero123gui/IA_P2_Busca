#include "Graph.h"
#include <iostream>
#include <fstream> //leitura de arquivo
#include <sstream> //parse de string



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

// Carrega o grafo a partir de um arquivo texto
bool Graph::loadFromFile(const string& filename){
    ifstream file(filename);
    if(!file.is_open()){
        cerr << "Esse erro é sacanagem, abertura de arquivo n da"<< filename << endl;
        return false;
    }
    string line;
    while (getline(file, line))
    {   
        // linha vazia ent continua
        if(line.empty()){
            continue;
        }


        if(line.rfind("ponto_inicial",0) == 0){

        } else if(line.rfind("ponto_final")){

        }
    }
    

}

// Retorna o nó inicial
string Graph::getStartNodeId() const{
    return start_node_id;
}

// Retorna o nó final
string Graph::getEndNodeId() const{
    return end_node_id;
}