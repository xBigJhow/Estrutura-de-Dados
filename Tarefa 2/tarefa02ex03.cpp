/*3)Fa�a um programa que armazene em vetor de registros, os dados de 3 funcion�rios de uma 
empresa, compostos de: Nome (string), Idade (int), c�digo do Setor onde trabalha (int) e
sal�rio (float). Os dados devem ser digitados pelo usu�rio, armazenados na estrutura e 
exibidos na tela posteriormente. Utilize aloca��o din�mica de mem�ria e 2 fun��es, 
uma para obter a digita��o dos dados de um funcion�rio e outra para exibi��o dos dados 
de um funcion�rio de forma a n�o deixar todo o c�digo na fun��o main. */

#include <iostream>
#include <stdlib.h>
#define QTD 3 

using namespace std;

typedef struct {
    string nome;
    int idade;
    int cod_setor;
} funcionario;

void inserir_dados(funcionario *funcionarios) {
    cout << "Nome: ";
    cin >> funcionarios->nome;
    cout << "Idade: ";
    cin >> funcionarios->idade;
    cout << "Codigo do Setor: ";
    cin >> funcionarios->cod_setor;
}

void imprimir_dados(funcionario funcionarios) {
    cout << "Nome: " << funcionarios.nome << endl;
    cout << "Idade: " << funcionarios.idade << endl;
    cout << "Codigo Setor: " << funcionarios.cod_setor << endl;
}

int main() {
    //DECLARANDO E ALOCANDO MEMORIA
    funcionario *funcionarios;
    funcionarios = new funcionario[QTD];
    //INSERINDO DADOS
    cout << "----------DIGITE OS DADOS DOS FUNCIONARIOS--------------" << endl;
    for(int i=0; i<QTD;i++) {
        cout << "Dados do funcionario numero " << i+1 << endl;
        inserir_dados(&funcionarios[i]);
    }
    //IMPRIMINDO DADOS
    cout << "----------MOSTRANDO OS DADOS DOS FUNCIONARIOS--------------" << endl;
    for(int i=0; i<QTD;i++) {
        cout << "Dados do funcionario numero " << i+1 << endl;
        imprimir_dados(funcionarios[i]);
    }
}
