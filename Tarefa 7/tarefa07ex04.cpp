/*4)Elabore uma segunda versão do algoritmo Quick Sort utilizando algum outro critério para a seleção do pivô como o último elemento ou o elemento do meio.  Execute o mesmo, compare o tempo de execução com o algoritmo original e coloque seus resultados na forma de comentários no código fonte a ser entregue:*/

#include <iostream>
#define TAM 1000

using namespace std;

void imprimeVetor(int vetor[]){
    for(int i=0; i<TAM; i++){
        cout << "| " << vetor[i];
    }
}

void quickSortPivoFim(int vetor[], int inicio, int fim) {
    if (inicio < fim) {
        int pivo = fim;
        int esq = inicio - 1;
        
        for (int dir = inicio; dir < fim; dir++) {
            if (vetor[dir] <= vetor[pivo]) {
                esq++;
                swap(vetor[esq], vetor[dir]);
            }
        }
        
        esq++;
        swap(vetor[esq], vetor[pivo]);
        
        quickSortPivoFim(vetor, inicio, esq - 1);
        quickSortPivoFim(vetor, esq + 1, fim);
    }
}

void quickSort(int vetor[], int inicio, int fim){

    int meio, pivo, esq, dir, aux;
    //limites da esquerda e direita da região analisada
    esq = inicio;
    dir = fim;
    //ajustando os valores do meio
    meio = (int) (esq + dir) / 2;
    pivo = vetor[meio];

    while(dir > esq){
        
        while(vetor[esq] < pivo) {
        esq = esq + 1;

        }
        while(vetor[dir] > pivo) {
            dir = dir - 1;
        }

        if(esq <= dir) {
            //realiza troca
            aux = vetor[esq];
            vetor[esq] = vetor[dir];
            vetor[dir] = aux;
            //faz os limites laterais caminharem para o centro
            esq = esq+1;
            dir = dir-1;
        }
    }
    
    if(inicio < dir){
        quickSort(vetor, inicio, dir);
    }
    if(esq < fim){
        quickSort(vetor, esq, fim);
    }
    imprimeVetor(vetor);
}

int main(void){

    int vetor[1000];
    for(int i = 0, j = TAM; i < TAM; i++, j--) {
        vetor[i] = j;
    }
    quickSortPivoFim(vetor, 0, TAM);
    imprimeVetor(vetor);
    return 0; 

    /* Utilizando o quickSort normal, durou 0,69s e com o pivo trocado pro elemento do fim durou 0,66S*/
}
