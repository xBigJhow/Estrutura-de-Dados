/* 1)Dada a sequência de números: 3 4 9 2 5 8 2 1, ordene-a em ordem crescente utilizando algoritmo Bubble Sort, apresentando a sequência obtida após cada passo do algoritmo, assim como foi feito na aula. */

#include <iostream>
#define TAM 8

using namespace std;

void imprimeVetor(int vetor[], int cont){
    cout << "\nPasso numero " << cont << endl;
    for(int i=0; i<TAM; i++){
        cout << " | " << vetor[i];
    }
}

void bubbleSort(int vetor[]){
    //variaveis
    int y, x, aux, cont = 0;
    //primeiro loop para primeiro elemento
    for(x=0; x<TAM; x++){
        //segundo loop para elemento sucessor do primeiro elemento
        for(y=(x+1); y<TAM; y++){
            /*verioficacao, se caso o primeiro elemento comparado for
            maior que o segundo elemento, faz a troca, utilizando
            variavel auxiliar */
            if(vetor[x] > vetor[y]){
                aux = vetor[x];
                vetor[x] = vetor[y];
                vetor[y] = aux;
            }
        }
        cont++; // utilizando para mostrar os numeros de passos.
        imprimeVetor(vetor, cont);
    }
}

int main(void){

    int vetor[TAM] = {3,4,9,2,5,8,2,1};

    bubbleSort(vetor);
}