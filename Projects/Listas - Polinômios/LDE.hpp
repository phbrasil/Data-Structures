/*Lista Duplamente Encadeada
Feito por: Pedro Brasil e Gustavo Moser*/
#include <iostream>
using namespace std;

#ifndef LDE_HPP
#define LDE_HPP

template <typename T>
struct No
{
    int expoente;
    T coeficiente;
    No <T> *eloP, *eloA;
};

template <typename T>
struct Lde
{
    No <T> *comeco;
    No <T> *fim;
};

template <typename T>
void inicializar(Lde <T> &lista)
{
    lista.comeco = NULL;
    lista.fim = NULL;
}

template <typename T>
void removerMonomio(Lde <T> &lista, int exp)
{
    No <T> *posAtual = lista.comeco;

    while (posAtual != NULL)
    {
        if (posAtual->expoente == exp)
        {
            No <T> *ant = posAtual->eloA;
            No <T> *prox = posAtual->eloP;

            if (ant != NULL)
                ant->eloP = prox;
            else
                lista.comeco = prox;

            if (prox != NULL)
                prox->eloA = ant;
            else
                lista.fim = ant;

            delete posAtual;
            return;
        }

        posAtual = posAtual->eloP;
    }
}

template <typename T>
bool pesquisar(Lde <T> lista, int exp)
{
    No <T> *posAtual = lista.comeco;

    while (posAtual != NULL)
    {
        if (posAtual->expoente == exp)
        {
            return true;
        }

        posAtual = posAtual->eloP;
    }

    return false;
}

template <typename T>
bool inserirNaLista(Lde <T> &lista, int exp, T coef)
{
    No <T> *posAtual = lista.comeco;

    while (posAtual != NULL)
    {
        if (posAtual->expoente == exp)
        {
            posAtual->coeficiente += coef;
            return true;
        }

        posAtual = posAtual->eloP;
    }

    No <T> *novo = new No<T>;

    if (novo == NULL)
        return false;

    novo->expoente = exp;
    novo->coeficiente = coef;
    novo->eloA = NULL;
    novo->eloP = NULL;

    if (lista.comeco == NULL)
    {
        lista.comeco = novo;
        lista.fim = novo;
    }
    else if (lista.fim->expoente > exp)
    {
        novo->eloA = lista.fim;
        lista.fim->eloP = novo;
        lista.fim = novo;
    }
    else if (lista.comeco->expoente < exp)
    {
        novo->eloP = lista.comeco;
        lista.comeco->eloA = novo;
        lista.comeco = novo;
    }
    else
    {
        No <T> *ant, *prox;

        ant = lista.comeco;

        while (ant != NULL)
        {
            prox = ant->eloP;

            if (ant->expoente > exp && prox->expoente < exp)
            {
                ant->eloP = novo;
                prox->eloA = novo;
                novo->eloA = ant;
                novo->eloP = prox;

                return true;
            }

            ant = ant->eloP;
        }
    }

    return true;
}

template <typename T>
void imprimirLista(Lde <T> lista, int constante = 0)
{
    No <T> *posAtual;

    posAtual = lista.comeco;

    while (posAtual != NULL)
    {
        if (posAtual != lista.comeco || constante != 0)
        {
            if (posAtual->coeficiente >= 0)
            {
                cout << " + ";
            }
            else
            {
                cout << " ";
            }
        }

        if (posAtual->expoente == 0)
        {
            cout << posAtual->coeficiente;
        }
        else
        {
            cout << posAtual->coeficiente << "X^" << posAtual->expoente;
        }

        posAtual = posAtual->eloP;
    }

    if (constante != 0)
    {
        if (constante > 0)
        {
            cout << " + " << constante;
        }
        else
        {
            cout << " " << constante;
        }
    }
}

#endif
