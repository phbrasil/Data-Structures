/*
Faça uma função que retorne altura de uma árvore binária.
*/
#include <iostream>
#include "abb.hpp"
using namespace std;

template <typename T>
int alturaArvore(No <T> *raiz)
{
    if (raiz == NULL) return 0;

    return (1 + max(alturaArvore(raiz->esq),alturaArvore(raiz->dir)));
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

    cout << "A arvore tem altura de " << alturaArvore(raiz) << " nos";
}
