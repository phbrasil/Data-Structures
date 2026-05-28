/*Biblioteca de Operações
Feito por: Pedro Brasil e Gustavo Moser*/
#include <iostream>
#include <cmath>
#include "LDE.hpp"

using namespace std;

template <typename T>
void somarPolinomios(Lde <T> A, Lde <T> B, Lde <T> &C)
{
    No <T> *posA = A.comeco;

    while (posA != NULL)
    {
        No <T> *posB = B.comeco;
        bool encontrou = false;

        while (posB != NULL)
        {
            if (posB->expoente == posA->expoente)
            {
                T soma = posA->coeficiente + posB->coeficiente;

                inserirNaLista(C, posA->expoente, soma);

                encontrou = true;
                break;
            }

            posB = posB->eloP;
        }

        if (!encontrou)
        {
            inserirNaLista(C, posA->expoente, posA->coeficiente);
        }

        posA = posA->eloP;
    }

    No <T> *posB = B.comeco;

    while (posB != NULL)
    {
        No <T> *posA2 = A.comeco;
        bool encontrou = false;

        while (posA2 != NULL)
        {
            if (posA2->expoente == posB->expoente)
            {
                encontrou = true;
                break;
            }

            posA2 = posA2->eloP;
        }

        if (!encontrou)
        {
            inserirNaLista(C, posB->expoente, posB->coeficiente);
        }

        posB = posB->eloP;
    }
}

template <typename T>
void subtrairPolinomios(Lde <T> A, Lde <T> B, Lde <T> &C)
{
    No <T> *posA = A.comeco;

    while (posA != NULL)
    {
        No <T> *posB = B.comeco;
        bool encontrou = false;

        while (posB != NULL)
        {
            if (posB->expoente == posA->expoente)
            {
                T sub = posA->coeficiente - posB->coeficiente;

                inserirNaLista(C, posA->expoente, sub);

                encontrou = true;
                break;
            }

            posB = posB->eloP;
        }

        if (!encontrou)
        {
            inserirNaLista(C, posA->expoente, posA->coeficiente);
        }

        posA = posA->eloP;
    }

    No <T> *posB = B.comeco;

    while (posB != NULL)
    {
        No <T> *posA2 = A.comeco;
        bool encontrou = false;

        while (posA2 != NULL)
        {
            if (posA2->expoente == posB->expoente)
            {
                encontrou = true;
                break;
            }

            posA2 = posA2->eloP;
        }

        if (!encontrou)
        {
            inserirNaLista(C, posB->expoente, -posB->coeficiente);
        }

        posB = posB->eloP;
    }
}

template <typename T>
void multiplicarEscalar(Lde <T> listaA, int escalar, Lde <T> &listaC)
{
    No <T> *posAtual = listaA.comeco;

    while (posAtual != NULL)
    {
        T valFinal = posAtual->coeficiente * escalar;

        inserirNaLista(listaC, posAtual->expoente, valFinal);

        posAtual = posAtual->eloP;
    }
}

template <typename T>
void multiplicarPolinomios(Lde <T> listaA, Lde <T> listaB, Lde <T> &listaC)
{
    No <T> *posA = listaA.comeco;

    while (posA != NULL)
    {
        No <T> *posB = listaB.comeco;

        while (posB != NULL)
        {
            int expoente = posA->expoente + posB->expoente;

            T coeficiente = posA->coeficiente * posB->coeficiente;

            inserirNaLista(listaC, expoente, coeficiente);

            posB = posB->eloP;
        }

        posA = posA->eloP;
    }
}

template <typename T>
T valorNumPolinomio(Lde <T> lista, int num)
{
    No <T> *posAtual = lista.comeco;

    T valorFinal = 0;

    while (posAtual != NULL)
    {
        T potencia = pow(num, posAtual->expoente);

        valorFinal += posAtual->coeficiente * potencia;

        posAtual = posAtual->eloP;
    }

    return valorFinal;
}
