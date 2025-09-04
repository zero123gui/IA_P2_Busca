#include "AStar.h"
#include <list>
#include <unordered_set>
#include <iostream>
#include <algorithm>

// Função que insere um nó na fronteira a ser explorada
// Entrada: ponteiro pra fronteira, nó a ser inserido
// Saída: nó inserido na fronteira ordenada
void insertSortedAStar(list<shared_ptr<Node>>& frontier, shared_ptr<Node> newNode){
    auto no = frontier.begin();
    while(no != frontier.end() && (*no)->f_cost < newNode->f_cost){
        no++;
    }
    frontier.insert(no, newNode);
}

// Função que realiza a busca
// Entrada: Grafo, Id nó inicial, Id nó final
// Saída: Vetor contendo o caminho
vector<string> AStar::solve(const Graph& graph, const string& startId, const string& endId){
    int iteracao = 1;
    list<shared_ptr<Node>> frontier; // lista encadeada ordenada que contém os nós a serem explorados
    unordered_set<string> visited_nodes; // nós explorados

    // Primeiro nó a ser explorado
    auto start_node = make_shared<Node>(startId, 0, graph.getHeuristic(startId), nullptr);
    frontier.push_back(start_node);

    while (!frontier.empty()){
        shared_ptr<Node> current_node = frontier.front();
        frontier.pop_front();
        cout << "No atual: " << current_node->id << endl;

        // Achou o fim
        if(current_node->id == endId){
            cout << "Cheguei no final" << endl;
            return reconstructPath(current_node);
        }
        
        // Se não for o fim, adiciona na lista de visitados
        if(visited_nodes.count(current_node->id)){
            continue;
        }
        visited_nodes.insert(current_node->id);

        // Explora os vizinhos pra decidir por onde ir
        try{
            for(const auto& neighbor_pair : graph.getNeighbors(current_node->id)){
                const string& neighbor_id = neighbor_pair.first;
                const int edge_cost = neighbor_pair.second;

                if(visited_nodes.count(neighbor_id)){
                    continue;
                }

                int new_g_cost = current_node->g_cost + edge_cost;

                int h_cost = graph.getHeuristic(neighbor_id);
                auto neighbor_node = make_shared<Node>(neighbor_id, new_g_cost, h_cost, current_node);
                insertSortedAStar(frontier, neighbor_node);
            }
            
        } catch(const out_of_range e){
        }
        
        cout << "Iteracao: " << iteracao << endl;
        cout << "Lista: ";
        for (const auto& node : frontier) {
            cout << "(" << node->id << ": " << node->g_cost << " + " << node->h_cost << " = " << node->f_cost << ") ";
        }
        cout << endl;
        cout << "Medida de desempenho: " << endl;
        cout << endl;
        iteracao++;  
    }

    cout << "Deu ruim ein, ve se ta certo isso ai" << endl;
    return {};
}

// Função que reconstroi o caminho percorrido
// Entrada: nó final
// Saída: Vetor contendo o caminho percorrido
vector<string> AStar::reconstructPath(shared_ptr<Node> endNode){
    vector<string> path;
    shared_ptr<Node> currentNode = endNode;
    int total_cost=0;

    // preenche o caminho de trás pra frente
    while (currentNode != nullptr){
        total_cost += currentNode->g_cost;
        path.push_back(currentNode->id);
        currentNode = currentNode->parent;
    }
    cout << "\n--- Resumo da Execucao ---" << endl;
    cout << "Custo total do caminho percorrido: " << total_cost << endl;
    // inverte o vetor para ficar em ordem
    reverse(path.begin(), path.end());

    return path;
}