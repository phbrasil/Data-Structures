/*
Faça uma função que compare se duas árvores binárias de busca são iguais (mesmo
conteúdo) e outra para testar se elas são estritamente iguais (o mesmo conteúdo e na
mesma posição).
*/
#include <iostream>
#include "abb.hpp"
using namespace std;

template <typename T>
bool existe(No <T> *raiz, int chave)
{
    if (raiz == NULL) return false;

    if (raiz->chave == chave) return true;
    return (existe(raiz->esq, chave) || existe(raiz->dir, chave));
}

template <typename T>
bool saoIguais(No <T> *raizA, No <T> *raizB)
{
    if (raizA == NULL && raizB == NULL) return true;
    if (raizA == NULL || raizB == NULL) return false;

    if (raizA->chave != raizB->chave) return false;
    return (saoIguais(raizA->esq, raizB->esq) && saoIguais(raizA->dir, raizB->dir));
}

template <typename T>
bool mesmoConteudo(No <T> *raizA, No <T> *raizB)
{
    if (raizA == NULL) return true;

    if (!existe(raizB, raizA->chave)) return false;
    return (mesmoConteudo(raizA->esq, raizB) && mesmoConteudo(raizA->dir, raizB));
}

int main()
{
    No <int> *raizA, *raizB;
    int chave;
    inicializar(raizA);

    do
    {
        cout << "Digite o valor que gostaria de inserir A(0-fim): ";
        cin >> chave;

        if (chave != 0) inserir(raizA, chave, chave);

    }
    while(chave != 0);

    inicializar(raizB);

    do
    {
        cout << "Digite o valor que gostaria de inserir B(0-fim): ";
        cin >> chave;

        if (chave != 0) inserir(raizB, chave, chave);

    }
    while(chave != 0);

    cout << "Mesmo conteudo: " << (mesmoConteudo(raizA, raizB) ? "SIM" : "NAO");

    cout << endl;

    cout << "Estritamente iguais: " << (saoIguais(raizA, raizB) ? "SIM" : "NAO");
}
