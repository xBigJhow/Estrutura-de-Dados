/*1)Fa�a um programa que crie uma estrutura para armazenar uma data qualquer com os 
campos num�ricos dia, m�s e ano e que pe�a para o usu�rio digitar a data de anivers�rio 
de duas pessoas e armazenar em dois registros diferentes e depois exibi-los na tela do
computador. Fa�a esse exerc�cio usando aloca��o est�tica de mem�ria.*/
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
    cout << "Digite a data de anivers�rio da primeira pessoa: ";
    cin >> pessoa1.dia;
    cin >> pessoa1.mes;
    cin >> pessoa1.ano;
    cout << "Digite a data de anivers�rio da segunda pessoa: ";
    cin >> pessoa2.dia;
    cin >> pessoa2.mes;
    cin >> pessoa2.ano;
    //IMPRIMINDO
    cout << "Pessoa numero 1: " << endl;
    cout << "Aniversario: " << pessoa1.dia << "/" << pessoa1.mes << "/" << pessoa1.ano << endl;
    cout << "Pessoa numero 2: " << endl;
    cout << "Aniversario: " << pessoa2.dia << "/" << pessoa2.mes << "/" << pessoa2.ano << endl;
         
}

