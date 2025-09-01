#include "Greedy.h"
#include <list>
#include <unordered_set>
#include <iostream>
#include <algorithm>

// Função que insere um nó na fronteira a ser explorada
// Entrada: ponteiro pra fronteira, nó a ser inserido
// Saída: nó inserido na fronteira ordenada
void insertSortedGreedy(list<shared_ptr<Node>>& frontier, shared_ptr<Node> newNode){
    auto no = frontier.begin();
    while(no != frontier.end() && (*no)->f_cost < newNode->f_cost){
        no++;
    }
    frontier.insert(no, newNode);
}

// Função que realiza a busca
// Entrada: Grafo, Id nó inicial, Id nó final
// Saída: Vetor contendo o caminho
vector<string> Greedy::solve(const Graph& graph, const string& startId, const string& endId){
    list<shared_ptr<Node>> frontier; // lista encadeada ordenada que contém os nós a serem explorados
    unordered_set<string> visited_nodes; // nós explorados

    // Primeiro nó a ser explorado
    auto start_node = make_shared<Node>(startId, 0, graph.getHeuristic(startId), nullptr);
    start_node->f_cost = start_node->h_cost;
    frontier.push_back(start_node);

    while (!frontier.empty()){
        shared_ptr<Node> current_node = frontier.front();
        frontier.pop_front();
        cout << "No atual: " << current_node->id << endl;

        // Achou o fim
        if(current_node->id == endId){
            cout << "Cheguei no final";
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
                neighbor_node->f_cost = neighbor_node->h_cost;

                cout << "(" << neighbor_node->id << ": " << neighbor_node->g_cost << " + " << neighbor_node->h_cost << " = " << neighbor_node->f_cost << ")" << endl;

                insertSortedGreedy(frontier, neighbor_node);
            }
            
        } catch(const out_of_range e){
        }
    }

    cout << "Deu ruim ein, ve se ta certo isso ai" << endl;
    return {};
}

// Função que reconstroi o caminho percorrido
// Entrada: nó final
// Saída: Vetor contendo o caminho percorrido
vector<string> Greedy::reconstructPath(shared_ptr<Node> endNode){
    vector<string> path;
    shared_ptr<Node> currentNode = endNode;

    // preenche o caminho de trás pra frente
    while (currentNode->parent != nullptr){
        path.push_back(currentNode->id);
        currentNode = currentNode->parent;
    }

    // inverte o vetor para ficar em ordem
    reverse(path.begin(), path.end());

    return path;
}