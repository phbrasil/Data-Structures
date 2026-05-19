#include <iostream>
using namespace std;

template <typename T>
struct No
{
    int chave;
    T dado;
    No *esq, *dir;
};

template <typename T>
void inicializar(No <T> *&raiz)
{
    raiz = NULL;
}

template <typename T>
bool inserir(No<T>*&raiz, int chave, T valor)
{
    if (raiz == NULL)
    {
        No <T> *novo = new No<T>;
        if( novo == NULL ) return false;

        novo->chave = chave;
        novo->dado = valor;
        novo->dir = NULL;
        novo->esq = NULL;
        raiz = novo;
        return true;
    }

    if (raiz->chave == chave) return false;

    if (chave < raiz->chave)
    {
        return(inserir(raiz->esq, chave, valor));
    }
    else
    {
        return(inserir(raiz->dir, chave, valor));
    }
}

template <typename T>
bool pesquisar(No<T> *raiz, int chave, T &valor)
{
    if (raiz == NULL) return false;

    if (raiz->chave == chave)
    {
        valor = raiz->dado;
        return true;
    }

    if (chave < raiz->chave)
    {
        return(pesquisar(raiz->esq, chave, valor));
    }
    else
    {
        return(pesquisar(raiz->dir, chave, valor));
    }
}

template <typename T>
No <T> *maiorValor(No <T> *raiz)
{
    if (raiz->dir == NULL)
    {
        return raiz;
    }

    return(maiorValor(raiz->dir));
}

template <typename T>
bool retirar(No<T> *&raiz, int chave)
{
    if (raiz == NULL) return false;

    if (raiz->chave == chave)
    {
        No <T> *aux = raiz;
        if (aux->esq && aux->dir == NULL)
        {
            raiz = NULL;
            delete aux;
            return true;
        }

        if(aux->esq != NULL && aux->dir == NULL)
        {
            raiz = aux->esq;
            delete aux;
            return true;
        }

        if (aux->dir != NULL && aux->esq == NULL)
        {
            raiz = aux->dir;
            delete aux;
            return true;
        }

        aux = maiorValor(raiz->esq);
        raiz->chave = aux->chave;
        raiz->dado = aux->dado;
        return(retirar(raiz, aux->chave));
    }
    if(chave < raiz->chave)
    {
        return(retirar(raiz->esq, chave));
    }
    else
    {
        return(retirar(raiz->dir, chave));
    }
}

template <typename T>
void prefixado(No<T> *raiz)
{
    //Raiz-Esq-Dir
    if (raiz == NULL) return;

    cout << raiz->dado << endl;
    (raiz->esq);
    (raiz->dir);
}

template <typename T>
void infixado(No<T> *raiz)
{
    //Esq-Raiz-Dir
    if (raiz == NULL) return;

    (raiz->esq);
    cout << raiz->dado << endl;
    (raiz->dir);
}

template <typename T>
void posfixado(No<T> *raiz)
{
    //Esq-Dir-Raiz
    if (raiz == NULL) return;

    (raiz->esq);
    (raiz->dir);
    cout << raiz->dado << endl;
}

template <typename T>
void liberar(No<T> *raiz)
{
    if (raiz == NULL) return;

    liberar(raiz->esq);
    liberar(raiz->dir);
    delete raiz;
}

template <typename T>
void mostrar_arvore(No<T> *raiz, int tab = 0)
{
    if (raiz == NULL) return;
    for (int i = 0; i < tab; i++) cout << " ";

    cout << raiz->dado << "-" << raiz->chave << endl;
    (mostrar_arvore(raiz->esq, tab + 3));
    (mostrar_arvore(raiz->dir, tab + 3));
}
