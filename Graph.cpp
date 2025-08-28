#include "Graph.h"
#include <iostream>
#include <fstream> //leitura de arquivo
#include <sstream> //parse de string



// Adiciona uma aresta/nó no grafo
// Entrada: id de um nó, id de um nó, custo para ir, orientado ou não
// Saída: aresta adiciona entre um par de nós
void Graph::addEdge(const string& from, const string& to, int cost, bool is_oriented){
    // Adiciona a conexão
    adj[from].push_back({to, cost});

    // Se nao orientado ent adiciona a conexão de volta
    if(is_oriented==false){
        adj[to].push_back({from, cost});
    }
}

// Define o valor da heurística de um nó
// Entrada: nó do grafo, valor da heuristica
// Saída: heurística associada ao nó
void Graph::setHeuristic(const string& node, int value){
    heuristics[node] = value;
}

// Retorna o valor da heurística de um nó
// Entrada: nó do grafo
// Saída: valor da heurística de um nó
int Graph::getHeuristic(const string& node) const{
    // Verifica se tem heurística pro nó, senão retorna 0
    if(heuristics.count(node)){
        return heuristics.at(node);
    }

    return 0;
}

// Retorna uma lista de vizinhos de um nó
// Entrada: nó do grafo
// Saída: vetor que contém nome e valor dos nós adjacentes
const vector<pair<string, int>>& Graph::getNeighbors(const string& node) const{
    // Se o nó não existir retorna uma exceção
    return adj.at(node);
}

// Carrega o grafo a partir de um arquivo texto
// Entrada: nome do arquivo
// Saída: boleano que diz se deu certo ou não
bool Graph::loadFromFile(const string& filename){
    ifstream file(filename);
    if(!file.is_open()){
        cerr << "Nao carregou o nome certo"<< filename << endl;
        return false;
    }
    string line;
    while (getline(file, line)){   
        // linha vazia ent continua
        if(line.empty()){
            continue;
        }
        string content = getContent(line);
        if(content.empty()){
            continue;
        }
        // percorre linha por linha verificando oq tá escrito
        if(line.rfind("ponto_inicial", 0) == 0){ // ponto inicial
            this->start_node_id = content;
        } else if(line.rfind("ponto_final", 0) == 0){ // ponto final
            this->end_node_id = content;
        } else if(line.rfind("orientado", 0) == 0){ // orientado ou n
            if(content == "s"){
                this->is_oriented = true;
            } else 
                this->is_oriented = false;
        } else if(line.rfind("pode_ir", 0) == 0){ // conexão entre nós
            stringstream ss(content);
            string from, to, cost_str;

            getline(ss, from, ',');
            getline(ss, to, ',');
            getline(ss, cost_str, ',');

            int cost = stoi(cost_str);
            addEdge(from, to, cost, this->is_oriented);
        } else if(line.rfind("h", 0) == 0){ // heurística de um nó
            stringstream ss(content);
            string node, target, value_str;

            getline(ss, node, ',');
            getline(ss, target, ',');
            getline(ss, value_str, ',');

            int value = stoi(value_str);
            setHeuristic(node, value);
        }
    }

    file.close();
    cout << "Grafo carregado com sucesso" << endl;
    cout << "Ponto inicial: " << this->start_node_id << "\nPonto final: " << this->end_node_id <<endl;

    return true;
}

// Retorna o nó inicial
// Entrada: -------
// Saída: nó inicial do grafo
string Graph::getStartNodeId() const{
    return start_node_id;
}

// Retorna o nó final
// Entrada: -------
// Saída: nó final do grafo
string Graph::getEndNodeId() const{
    return end_node_id;
}

// Retorna o conteúdo de uma string do arquivo 
// Entrada: linha do arquivo
// Saída: retorna o conteúdo dessa linha
string Graph::getContent(const string& line){
    size_t start = line.find('(');
    size_t end = line.rfind(')');
    if(start != string::npos && end != string::npos && start < end){
        return line.substr(start + 1, end - start - 1);
    }

    return ""; //retorna string vazia se n achar os delimitadores
}