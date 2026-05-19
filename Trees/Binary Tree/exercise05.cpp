/*
Escreva uma função que realize o caminhamento pré-fixado em uma árvore binária e
coloca o resultado dentro de um vetor.
*/
#include <iostream>
#include "abb.hpp"
using namespace std;

#define TAM 10

template <typename T>
void prefixadoVetor(No <T> *raiz, int vet[TAM], int &pos)
{
    //Raiz-Esq-Dir
    if (raiz == NULL) return;

    vet[pos] = raiz->dado;
    pos++;
    prefixadoVetor(raiz->esq, vet, pos);
    prefixadoVetor(raiz->dir, vet, pos);
}

int main()
{
    No <int> *raiz;
    int chave, pos = 0;
    int vet[TAM];
    inicializar(raiz);

    do
    {
        cout << "Digite o valor que gostaria de inserir (0-fim): ";
        cin >> chave;

        if (chave != 0) inserir(raiz, chave, chave);

    }
    while(chave != 0);

    prefixadoVetor(raiz, vet, pos);

    cout << "Vetor" << endl;

    for (int i = 0; i < pos; i++)
    {
        cout << "[" << i << "] " << vet[i] << endl;
    }
}
