/*3)Faça um programa que armazene em vetor de registros, os dados de 3 funcionários de uma 
empresa, compostos de: Nome (string), Idade (int), código do Setor onde trabalha (int) e
salário (float). Os dados devem ser digitados pelo usuário, armazenados na estrutura e 
exibidos na tela posteriormente. Utilize alocação dinâmica de memória e 2 funções, 
uma para obter a digitação dos dados de um funcionário e outra para exibição dos dados 
de um funcionário de forma a não deixar todo o código na função main. */

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
