#include <iostream>
#include "Node.h"

int main(){
    auto start_node = std::make_shared<Node>("ao", 0, 10, nullptr);

    std::cout << "Projeto de Algoritmos de Busca" << std::endl;
    std::cout << "Nó inicial criado: " << start_node->id << std::endl;
    std::cout << "Custo Total: " << start_node->f_cost << std::endl;

    return 0;
}