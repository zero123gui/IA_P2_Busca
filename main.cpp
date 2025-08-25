#include <stdio.h>

typedef struct node
{
    int num;
    int custo_chegar;
    int custo_heuristica;
    int custo_total = custo_heuristica + custo_chegar;
    node *parent;
}node;

typedef struct aberta
{
    aberta *prox;
    
}aberta;

typedef struct fechada
{
    /* data */
}fechada;




int main(){

    return 0;
}