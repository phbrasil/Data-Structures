/*
Escreva uma função que retorna verdadeiro se uma árvore é binária de busca e falso
caso contrário.
*/
#include <iostream>
#include "abb.hpp"
using namespace std;

template <typename T>
bool ehBinaria(No <T> *raiz, No <T> *anterior)
{
    if (raiz == NULL) return true;

    if (!ehBinaria(raiz->esq, anterior)) return false;
    if (anterior != NULL && raiz->chave < anterior->chave) return false;
    return (ehBinaria(raiz->dir, raiz));
}

int main()
{
    No <int> *raiz;
    No <int> *anterior = NULL;
    int chave;
    inicializar(raiz);

    do
    {
        cout << "Digite o valor que gostaria de inserir (0-fim): ";
        cin >> chave;

        if (chave != 0) inserir(raiz, chave, chave);

    }
    while(chave != 0);

    cout << "A arvore " << (ehBinaria(raiz, anterior) ? "e binaria" : "nao e binaria");
}
