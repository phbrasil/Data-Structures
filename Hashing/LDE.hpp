#include <iostream>
using namespace std;

template <typename T>
struct No
{
    T info;
    No <T> *eloA, *eloP;
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
bool vazio(Lde <T> lista){
    return (lista.comeco == NULL) ? true : false;
}

template <typename T>
bool inserir(Lde <T> &lista, T valor)
{
    No <T> *novo = new No <T>;

    if(novo == NULL) return false;

    novo->info = valor;
    novo->eloA = NULL;
    novo->eloP = NULL;

    if (vazio(lista)) //Caso 01
    {
        lista.comeco = novo;
        lista.fim = novo;
    }

    else if (valor > lista.fim->info) //Caso 02
    {
        lista.fim->eloP = novo;
        novo->eloA = lista.fim;
        lista.fim = novo;
    }

    else if (valor < lista.comeco->info) //Caso 03
    {
        lista.comeco->eloA = novo;
        novo->eloP = lista.comeco;
        lista.comeco = novo;
    }

    else //Caso 04
    {
        No <T> *ant, *prox;
        ant = lista.comeco;

        while (ant != NULL)
        {
            prox = ant->eloP;
            if (valor > ant->info && valor < prox->info)
            {
                ant->eloP = novo;
                novo->eloA = ant;

                prox->eloA = novo;
                novo->eloP = prox;
                return true;
            }
            ant = ant->eloP;
        }
    }
    return true;
}

template <typename T>
bool retirar(Lde <T> &lista, T valor)
{
    if (vazio(lista)) return false;

    No <T> *aux;
    if (valor == lista.comeco->info) //Caso 01
    {
        aux = lista.comeco;

        if (valor == lista.fim->info)
        {
            lista.comeco = NULL;
            lista.fim = NULL;
        }
        else
        {
            lista.comeco = aux->eloP;
            lista.comeco->eloA = NULL;
        }
    }

    else
    {
        No <T> *ant;
        aux = lista.comeco->eloP;

        while (aux != NULL)
        {
            ant = aux->eloA;

            if (aux->info == valor)
            {
                if (valor == lista.fim->info)
                {
                    lista.fim = ant;
                    ant->eloP = NULL;
                }
                else
                {
                    No <T> *prox = aux->eloP;
                    ant->eloP = prox;
                    prox->eloA = ant;
                }
                break;
            }
            aux = aux->eloP;
        }

        if (aux == NULL) return false;
    }
    delete aux;
    return true;
}

template <typename T>
bool pesquisar(Lde <T> lista, T valor)
{
    No <T> *aux = lista.comeco;

    while (aux != NULL)
    {
        if (aux->info == valor) return true;
        aux = aux->eloP;
    }
    return false;
}

template <typename T>
void mostrar(Lde <T> lista)
{
    No <T> *aux = lista.comeco;

    while (aux != NULL)
    {
        cout << aux->info << " ";

        aux = aux->eloP;
    }
}
