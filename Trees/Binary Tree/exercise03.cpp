/*
Escreva uma função que recebe uma árvore binária de busca e dois valores A e B. Essa
função deve listar todos os itens dessa árvore entre A e B, inclusive, de forma ordenada
*/
#include <iostream>
#include "abb.hpp"
using namespace std;

template <typename T>
void listarItens(No <T> *raiz, int a, int b)
{
    if (raiz == NULL) return;

    if (raiz->chave > a) listarItens(raiz->esq, a, b);
    if (raiz->chave > a && raiz->chave < b) cout << raiz->chave << " ";
    if (raiz->chave < b) listarItens(raiz->dir, a, b);
}

int main()
{
    No <int> *raiz;
    int chave, a, b;
    inicializar(raiz);

    do
    {
        cout << "Digite o valor que gostaria de inserir (0-fim): ";
        cin >> chave;

        if (chave != 0) inserir(raiz, chave, chave);

    }
    while(chave != 0);

    cout << "\nDigite o valor de A: ";
    cin >> a;

    cout << "Digite o valor de B: ";
    cin >> b;

    cout << "Os valores entre A e B sao: ";
    listarItens(raiz, a, b);
}
