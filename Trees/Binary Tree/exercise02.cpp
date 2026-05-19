/*
Escreva uma função que conta o número de folhas de uma árvore binária.
*/
#include <iostream>
#include "abb.hpp"
using namespace std;

template <typename T>
int numFolhas(No <T> *raiz)
{
    if (raiz->esq == NULL && raiz->dir == NULL) return 1;

    return (numFolhas(raiz->esq) + numFolhas(raiz->dir));
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

    cout << "A arvore contem " << numFolhas(raiz) << " folhas";
}
