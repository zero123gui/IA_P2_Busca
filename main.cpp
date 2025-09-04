// main.cpp
#include <iostream>
#include <locale>
#include "AStar.h"
#include "Graph.h"
#include "Greedy.h"

void menu() {
    int option = 0;
    string file;
    Graph labirinto;

    cout << "\n\t--- Bem vindo ao Labirinto ---" << endl;

    do {
        // Menu de opções
        cout << "\nEscolha uma das opcoes para prosseguir" << endl;
        cout << "\tOp 1: Algoritmo A*" << endl;
        cout << "\tOp 2: Algoritmo Guloso (em breve)" << endl;
        cout << "\tOp 3: Sair do Labirinto" << endl;
        cout << "Opcao: ";
        cin >> option;

        if (option == 3) {
            cout << "Saindo do labirinto..." << endl;
            break;
        }
        
        if (option != 1 && option != 2) {
            cout << "Opcao invalida, tente novamente." << endl;
            continue; // Volta para o início do loop
        }

        // Recebe o nome do arquivo
        cout << "Digite o nome do arquivo (ex: teste.txt): ";
        cin >> file;

        // Carrega o labirinto com o arquivo recebido
        bool sucesso = labirinto.loadFromFile(file);

        if (!sucesso) {
            cerr << "arquivo n abriu certo" << endl;
            continue;
        }

        switch (option) {
            case 1: {
                cout << "\n--- Executando Algoritmo A* ---" << endl;
                AStar astar_solver;

                vector<string> path = astar_solver.solve(
                    labirinto,
                    labirinto.getStartNodeId(),
                    labirinto.getEndNodeId()
                );

                if (path.empty()) {
                    cout << "Nao achei o caminho f ):" << endl;
                } else {
                    cout << "Caminho: ";
                    for (size_t i = 0; i < path.size(); ++i) {
                        cout << path[i] << (i == path.size() - 1 ? "" : " -> ");
                    }
                    cout << endl;
                }
                break;
            }
            case 2:{
                cout << "\n--- Executando Algoritmo Guloso ---" << endl;
                Greedy greedy_solver;

                vector<string> path = greedy_solver.solve(
                    labirinto,
                    labirinto.getStartNodeId(),
                    labirinto.getEndNodeId()
                );

                if (path.empty()) {
                    cout << "Nao achei o caminho" << endl;
                } else {
                    cout << "Caminho: ";
                    for (size_t i = 0; i < path.size(); ++i) {
                        cout << path[i] << (i == path.size() - 1 ? "" : " -> ");
                    }
                    cout << endl;
                }
                break;
            }
            default:
                break;
        }
    } while (option != 3);
}

int main() {

    // Chama a função de Menu() que inicia o programa
    menu();

    return 0;
}