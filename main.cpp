#include <iostream>
#include "Node.h"

using namespace std;

int main(){
    auto start_node = make_shared<Node>("a0", 0, 10, nullptr);

    cout << "Projeto de Algoritmos de Busca" << endl;
    cout << "No inicial criado: " << start_node->id << endl;
    cout << "Custo Total: " << start_node->f_cost << endl;

    return 0;
}