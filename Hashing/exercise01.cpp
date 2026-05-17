/*
Usando algum conjunto de chaves (por exemplo, nomes de cidades do estado de SC), faça o seguinte:
a) Escreva e teste um programa que carregue as chaves em uma tabela Hash com M=20 e colisão tratada por
encadeamento;
b) Escreva um programa para gerenciar inserções e remoções na tabela. Faça um menu que ofereça as opções
de inserir, retirar, localizar e mostrar a tabela.
*/

#include <iostream>
#include "LDE.hpp"
using namespace std;

#define TAM 20

int hashing(int chave)
{
    return (chave%TAM);
}
int calcular(string cidade)
{
    int chave = 0;

    for (int i = 0; i < cidade.length(); i++)
    {
        chave += (int)cidade[i];
    }

    return (hashing(chave));
}

void menuInserir(Lde <string> tabela[TAM])
{
    string cidade;
    cout << "Digite a cidade a ser inserida: ";
    getline(cin, cidade);

    inserir(tabela[calcular(cidade)], cidade);


}
void menuRetirar(Lde <string> tabela[TAM])
{
    string cidade;
    cout << "Digite a cidade a ser retirada: ";
    getline(cin, cidade);

    retirar(tabela[calcular(cidade)], cidade);
}
void menuLocalizar(Lde <string> tabela[TAM])
{
    string cidade;
    cout << "Digite a cidade a ser localizada: ";
    getline(cin, cidade);

    if (pesquisar(tabela[calcular(cidade)], cidade))
    {
        cout << "A Cidade esta na lista" << endl;
    }
    else
    {
        cout << "Cidade nao encontrada na lista" << endl;
    }

    system("pause");
}
void menuMostrar(Lde <string> tabela[TAM])
{
    cout << "Cidades Armazenadas:" << endl;

    for (int i = 0; i < TAM; i++)
    {
        cout << "[" << (i < 10 ? "0" : "") << i << "] ";
        mostrar(tabela[i]);
        cout << endl;
    }
    system("pause");
}

void menu(Lde <string> tabela[TAM])
{
    int resposta;
    do
    {
        system("cls");
        cout << R"(
+======================================+
|          TABELA HASH / MENU          |
+======================================+
|  [1] Inserir elemento                |
|  [2] Retirar elemento                |
|  [3] Localizar elemento              |
|  [4] Mostrar tabela                  |
|  [0] Sair                            |
+======================================+
)";
        cout << "   Escolha uma opcao: ";
        cin >> resposta;
        cin.ignore();
        system("cls");
        switch (resposta)
        {
        case 1:
            menuInserir(tabela);
            break;
        case 2:
            menuRetirar(tabela);
            break;
        case 3:
            menuLocalizar(tabela);
            break;
        case 4:
            menuMostrar(tabela);
            break;
        }

    } while(resposta != 0);
}

int main()
{
    Lde <string> tabela[TAM];
    for (int i = 0; i < TAM; i++)
    {
        inicializar(tabela[i]);
    }

    menu(tabela);

}
