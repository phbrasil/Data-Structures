#include <iostream>
using namespace std;

#define TAM 25

struct Item
{
    int valor;
    bool ocupado;
};

int hashing(int chave)
{
    return (chave%TAM);
}

void inicializar(Item tabela[TAM])
{
    for (int i = 0; i < TAM; i++)
    {
        tabela[i].ocupado = false;
    }
}

bool inserir(Item tabela[TAM], int chave)
{
    for (int i = 0; i < TAM; i++)
    {
        int pos = (hashing(chave) + i) % TAM;
        if (!tabela[pos].ocupado)
        {
            tabela[pos].valor = chave;
            tabela[pos].ocupado = true;
            return true;
        }
    }
    return false;
}

bool retirar(Item tabela[TAM], int chave)
{
    for (int i = 0; i < TAM; i++)
    {
        int pos = (hashing(chave) + i) % TAM;
        if (tabela[pos].ocupado && tabela[pos].valor == chave)
        {
            tabela[pos].ocupado = false;
            return true;
        }
    }
    return false;
}

bool pesquisar(Item tabela[TAM], int chave)
{
    for (int i = 0; i < TAM; i++)
    {
        int pos = (hashing(chave) + i) % TAM;
        if (!tabela[pos].ocupado) return false;
        if (tabela[pos].valor == chave) return true;
    }
    return false;
}

void mostrar(Item tabela[TAM])
{
    for (int i = 0; i < TAM; i++)
    {
        cout << "[" << (i < 10 ? "0" : "") << i << "] ";

        if (tabela[i].ocupado)
        {
            cout << tabela[i].valor;
        }
        cout << endl;
    }
    system("pause");
}

void menuInserir(Item tabela[TAM])
{
    int chave;
    cout << "Digite o num a ser inserido: ";
    cin >> chave;
    inserir(tabela, chave);
}

void menuRetirar(Item tabela[TAM])
{
    int chave;
    cout << "Digite o num a ser retirado: ";
    cin >> chave;
    retirar(tabela, chave);
}

void menuPesquisar(Item tabela[TAM])
{
    int chave;
    cout << "Digite o num a ser pesquisado: ";
    cin >> chave;

    if (pesquisar(tabela, chave))
    {
        cout << "Valor esta na lista" << endl;
    }
    else
    {
        cout << "Valor nao esta na lista" << endl;
    }

    system("pause");
}

void menu(Item tabela[TAM])
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
            menuPesquisar(tabela);
            break;
        case 4:
            mostrar(tabela);
            break;
        }

    } while(resposta != 0);
}

int main()
{
    Item tabela[TAM];
    inicializar(tabela);
    menu(tabela);
}
