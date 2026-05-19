/*
Escreva um algoritmo que conta o número de nós de uma árvore binária.
*/
#include <iostream>
#include "abb.hpp"
using namespace std;

template <typename T>
int numNos(No <T> *raiz)
{
    if (raiz == 0) return 0;
    return (1 + numNos(raiz->esq) + numNos(raiz->dir));
}

int main()
{
    No <int> *raiz;
    int chave;
    inicializar(raiz);

    do
    {
        cout << "Digite o valor que gostaria de inserir (0-fim): ";
        cin >> chave;

        if (chave != 0) inserir(raiz, chave, chave);

    } while(chave != 0);

    cout << "A arvore contem " << numNos(raiz) << " nos";
}
