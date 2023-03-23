/*1)Faça um programa que crie uma estrutura para armazenar uma data qualquer com os 
campos numéricos dia, mês e ano e que peça para o usuário digitar a data de aniversário 
de duas pessoas e armazenar em dois registros diferentes e depois exibi-los na tela do
computador. Faça esse exercício usando alocação estática de memória.*/
#include <iostream>
#include <stdlib.h>
using namespace std;
typedef struct {
    int dia;
    int mes;
    int ano;
} data_aniversario;

int main() {
    //DECLARANDO
    data_aniversario pessoa1, pessoa2;
    //INSERINDO
    cout << "Digite a data de aniversário da primeira pessoa: ";
    cin >> pessoa1.dia;
    cin >> pessoa1.mes;
    cin >> pessoa1.ano;
    cout << "Digite a data de aniversário da segunda pessoa: ";
    cin >> pessoa2.dia;
    cin >> pessoa2.mes;
    cin >> pessoa2.ano;
    //IMPRIMINDO
    cout << "Pessoa numero 1: " << endl;
    cout << "Aniversario: " << pessoa1.dia << "/" << pessoa1.mes << "/" << pessoa1.ano << endl;
    cout << "Pessoa numero 2: " << endl;
    cout << "Aniversario: " << pessoa2.dia << "/" << pessoa2.mes << "/" << pessoa2.ano << endl;
         
}

