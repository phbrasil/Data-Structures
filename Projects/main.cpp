/*Aplicação - Polinômios com Lista Duplamente Encadeada
Feito por: Pedro Brasil e Gustavo Moser
*/

#include <iostream>
#include "LDE.hpp"
#include "OPERACOES.hpp"

using namespace std;

// ─────────────────────────────────────────────
//  Utilitários
// ─────────────────────────────────────────────

void limparTela()
{
    system("cls");
}

void pausar()
{
    cout << "\nPressione ENTER para continuar...";
    cin.ignore();
    cin.get();
}

template <typename T>
void exibirLista(const char *nome, Lde <T> lista)
{
    cout << nome << ": ";

    if (lista.comeco == NULL)
        cout << "(vazia)";
    else
        imprimirLista(lista);

    cout << endl;
}

int lerInteiro(const char *msg)
{
    int val;

    cout << msg;

    while (!(cin >> val))
    {
        cin.clear();
        cin.ignore(1000, '\n');

        cout << "Valor invalido! " << msg;
    }

    return val;
}

// ─────────────────────────────────────────────
//  Entrada de monômio na lista escolhida
// ─────────────────────────────────────────────

template <typename T>
void menuInserirMonomio(Lde <T> &listaA, Lde <T> &listaB)
{
    cout << "\n=== INSERIR MONOMIO ===\n";
    cout << "Qual lista? (A / B): ";

    char op;

    cin >> op;

    op = toupper(op);

    if (op != 'A' && op != 'B')
    {
        cout << "Opcao invalida.\n";
        return;
    }

    int exp  = lerInteiro("Expoente   : ");
    T coef   = lerInteiro("Coeficiente: ");

    if (coef == 0 || exp == 0)
    {
        cout << "Coeficiente ou Expoente zero nao inserido.\n";
        return;
    }

    if (op == 'A')
        inserirNaLista(listaA, exp, coef);
    else
        inserirNaLista(listaB, exp, coef);

    cout << "Monomio inserido com sucesso!\n";
}

// ─────────────────────────────────────────────
//  Remoção de monômio
// ─────────────────────────────────────────────

template <typename T>
void menuRemoverMonomio(Lde <T> &listaA, Lde <T> &listaB)
{
    cout << "\n=== REMOVER MONOMIO ===\n";
    cout << "Qual lista? (A / B): ";

    char op;

    cin >> op;

    op = toupper(op);

    if (op != 'A' && op != 'B')
    {
        cout << "Opcao invalida.\n";
        return;
    }

    int exp = lerInteiro("Expoente a remover: ");

    Lde <T> &lista = (op == 'A') ? listaA : listaB;

    if (!pesquisar(lista, exp))
    {
        cout << "Expoente " << exp << " nao encontrado na lista " << op << ".\n";
        return;
    }

    removerMonomio(lista, exp);

    cout << "Monomio removido com sucesso!\n";
}

// ─────────────────────────────────────────────
//  Pesquisa de expoente
// ─────────────────────────────────────────────

template <typename T>
void menuPesquisar(Lde <T> listaA, Lde <T> listaB)
{
    cout << "\n=== PESQUISAR EXPOENTE ===\n";
    cout << "Qual lista? (A / B): ";

    char op;

    cin >> op;

    op = toupper(op);

    if (op != 'A' && op != 'B')
    {
        cout << "Opcao invalida.\n";
        return;
    }

    int exp = lerInteiro("Expoente a pesquisar: ");

    Lde <T> lista = (op == 'A') ? listaA : listaB;

    if (pesquisar(lista, exp))
        cout << "O termo de expoente " << exp << " EXISTE na lista " << op << ".\n";
    else
        cout << "O termo de expoente " << exp << " NAO existe na lista " << op << ".\n";
}

// ─────────────────────────────────────────────
//  Operações que resultam em C
// ─────────────────────────────────────────────

template <typename T>
void menuSomar(Lde <T> listaA, Lde <T> listaB, Lde <T> &listaC)
{
    cout << "\n=== SOMA (A + B) ===\n";

    inicializar(listaC);

    somarPolinomios(listaA, listaB, listaC);

    cout << "Resultado (C): ";

    if (listaC.comeco == NULL)
        cout << "0";
    else
        imprimirLista(listaC);

    cout << endl;
}

template <typename T>
void menuSubtrair(Lde <T> listaA, Lde <T> listaB, Lde <T> &listaC)
{
    cout << "\n=== SUBTRACAO (A - B) ===\n";

    inicializar(listaC);

    subtrairPolinomios(listaA, listaB, listaC);

    cout << "Resultado (C): ";

    if (listaC.comeco == NULL)
        cout << "0";
    else
        imprimirLista(listaC);

    cout << endl;
}

template <typename T>
void menuMultiplicarEscalar(Lde <T> listaA, Lde <T> &listaC)
{
    cout << "\n=== MULTIPLICAR A POR ESCALAR ===\n";

    int escalar = lerInteiro("Escalar: ");

    inicializar(listaC);

    multiplicarEscalar(listaA, escalar, listaC);

    cout << "Resultado (C): ";

    if (listaC.comeco == NULL)
        cout << "0";
    else
        imprimirLista(listaC);

    cout << endl;
}

template <typename T>
void menuMultiplicarPolinomios(Lde <T> listaA, Lde <T> listaB, Lde <T> &listaC)
{
    cout << "\n=== MULTIPLICACAO (A * B) ===\n";

    inicializar(listaC);

    multiplicarPolinomios(listaA, listaB, listaC);

    cout << "Resultado (C): ";

    if (listaC.comeco == NULL)
        cout << "0";
    else
        imprimirLista(listaC);

    cout << endl;
}

template <typename T>
void menuValorNumerico(Lde <T> listaA, Lde <T> listaB, Lde <T> listaC)
{
    cout << "\n=== VALOR NUMERICO ===\n";
    cout << "Qual lista? (A / B / C): ";

    char op;

    cin >> op;

    op = toupper(op);

    Lde <T> *lista = NULL;

    if      (op == 'A') lista = &listaA;
    else if (op == 'B') lista = &listaB;
    else if (op == 'C') lista = &listaC;
    else
    {
        cout << "Opcao invalida.\n";
        return;
    }

    if (lista->comeco == NULL)
    {
        cout << "Lista " << op << " esta vazia.\n";
        return;
    }

    int x = lerInteiro("Valor de X: ");

    T resultado = valorNumPolinomio(*lista, x);

    cout << "P(" << x << ") = " << resultado << endl;
}

// ─────────────────────────────────────────────
//  Limpar lista
// ─────────────────────────────────────────────

template <typename T>
void limparLista(Lde <T> &lista)
{
    No <T> *atual = lista.comeco;

    while (atual != NULL)
    {
        No <T> *prox = atual->eloP;

        delete atual;

        atual = prox;
    }

    lista.comeco = NULL;
    lista.fim    = NULL;
}

template <typename T>
void menuLimpar(Lde <T> &listaA, Lde <T> &listaB, Lde <T> &listaC)
{
    cout << "\n=== LIMPAR LISTA ===\n";
    cout << "Qual lista? (A / B / C): ";

    char op;

    cin >> op;

    op = toupper(op);

    if (op == 'A')
    {
        limparLista(listaA);
        cout << "Lista A limpa.\n";
    }
    else if (op == 'B')
    {
        limparLista(listaB);
        cout << "Lista B limpa.\n";
    }
    else if (op == 'C')
    {
        limparLista(listaC);
        cout << "Lista C limpa.\n";
    }
    else
    {
        cout << "Opcao invalida.\n";
    }
}

// ─────────────────────────────────────────────
//  Menu principal
// ─────────────────────────────────────────────

template <typename T>
void exibirMenu(Lde <T> listaA, Lde <T> listaB, Lde <T> listaC)
{
    cout << "\n======================================\n";
    cout << "        OPERACOES COM POLINOMIOS      \n";
    cout << "======================================\n";

    cout << " Polinomios atuais:\n";

    cout << " A: ";

    if (listaA.comeco == NULL)
        cout << "(vazia)";
    else
        imprimirLista(listaA);

    cout << endl;

    cout << " B: ";

    if (listaB.comeco == NULL)
        cout << "(vazia)";
    else
        imprimirLista(listaB);

    cout << endl;

    cout << " C: ";

    if (listaC.comeco == NULL)
        cout << "(vazia)";
    else
        imprimirLista(listaC);

    cout << endl;

    cout << "--------------------------------------\n";
    cout << " [1] Inserir monomio (A ou B)\n";
    cout << " [2] Remover monomio (A ou B)\n";
    cout << " [3] Pesquisar expoente\n";
    cout << " [4] Imprimir lista\n";
    cout << "--------------------------------------\n";
    cout << " [5] Somar A + B -> C\n";
    cout << " [6] Subtrair A - B -> C\n";
    cout << " [7] Multiplicar A por escalar -> C\n";
    cout << " [8] Multiplicar A * B -> C\n";
    cout << " [9] Valor numerico de polinomio\n";
    cout << "--------------------------------------\n";
    cout << " [0] Limpar lista\n";
    cout << " [S] Sair\n";
    cout << "======================================\n";
    cout << "Escolha: ";
}

int main()
{
    Lde <double> listaA, listaB, listaC;

    inicializar(listaA);
    inicializar(listaB);
    inicializar(listaC);

    char opcao;

    do
    {
        limparTela();

        exibirMenu(listaA, listaB, listaC);

        cin >> opcao;

        opcao = toupper(opcao);

        switch (opcao)
        {
            case '1':
                menuInserirMonomio(listaA, listaB);
                pausar();
                break;

            case '2':
                menuRemoverMonomio(listaA, listaB);
                pausar();
                break;

            case '3':
                menuPesquisar(listaA, listaB);
                pausar();
                break;

            case '4':
            {
                cout << "\n=== IMPRIMIR LISTA ===\n";
                cout << "Qual lista? (A / B / C): ";

                char lst;

                cin >> lst;

                lst = toupper(lst);

                if (lst == 'A')
                {
                    cout << "A: ";
                    imprimirLista(listaA);
                    cout << endl;
                }
                else if (lst == 'B')
                {
                    cout << "B: ";
                    imprimirLista(listaB);
                    cout << endl;
                }
                else if (lst == 'C')
                {
                    cout << "C: ";
                    imprimirLista(listaC);
                    cout << endl;
                }
                else
                {
                    cout << "Opcao invalida.\n";
                }

                pausar();
                break;
            }

            case '5':
                menuSomar(listaA, listaB, listaC);
                pausar();
                break;

            case '6':
                menuSubtrair(listaA, listaB, listaC);
                pausar();
                break;

            case '7':
                menuMultiplicarEscalar(listaA, listaC);
                pausar();
                break;

            case '8':
                menuMultiplicarPolinomios(listaA, listaB, listaC);
                pausar();
                break;

            case '9':
                menuValorNumerico(listaA, listaB, listaC);
                pausar();
                break;

            case '0':
                menuLimpar(listaA, listaB, listaC);
                pausar();
                break;

            case 'S':
                cout << "\nEncerrando... Ate mais!\n";
                break;

            default:
                cout << "Opcao invalida!\n";
                pausar();
        }

    } while (opcao != 'S');

    limparLista(listaA);
    limparLista(listaB);
    limparLista(listaC);

    return 0;
}
