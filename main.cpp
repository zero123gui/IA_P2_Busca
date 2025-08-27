// main.cpp
#include <iostream>
#include <locale>
#include "Graph.h" // Inclui a definição da nossa classe Graph

void menu(){
    int option = 0;
    string file;
    cout << "\n\t--- Bem vindo ao Labirinto ---" << endl;

    do
    {
        // Menu de opções
        cout << "Escolha umas das opcoes abaixo para chegar no centro" <<endl;
        cout << "\tOp 1: Algoritmo A*" << endl;
        cout << "\tOp 2: Algoritmo Guloso" << endl;
        cout << "\tOp 3: Sair do Labirinto" << endl;
        cin >> option;
        if (option == 3)
            break;

        // Recebe o nome do arquivo
        cout << "Para continuar, digite o nome do arquivo" << endl;
        cin >> file;

        // Inicializa o labirinto com o arquivo recebido
        Graph labirinto;
        bool sucesso = labirinto.loadFromFile(file);

        // Verifica se carregou o arquivo corretamente
        if(sucesso)
            cout << "Carregou certinho" << endl;
        else
            cout << "Deu ruim" << endl;

        // Switch-case para execução dos Algoritmos
        switch (option)
        {
        case 1:
            cout << "Voce escolheu o Algoritmo A*" << endl;
            cout << "Pena que ainda ta em desenvolvimento" << endl;
            break;
        case 2:
            cout << "Voce escolheu o Algoritmo Guloso" << endl;
            cout << "Pena que ainda ta em desenvolvimento" << endl;
            break;
        default:
            cout << "Saindo do labirinto" << endl;
            break;
        }
    } while (option!=1 || option!=2);
}

int main() {

    // Chama a função de Menu() que inicia o programa
    menu();

    return 0;
}