/* Implemente uma função que retorna a posição de um elemento. Será preciso percorrer a lista até que se encontre o elemento cujos campos sejam iguais ao do elemento passado
como parâmetro. Retorna -1 caso a lista não contenha o elemento. Elabore também o programa principal (main) demonstrando como a função é utilizada. Segue o protótipo abaixo:
int posicaoDoElemento(Fila *f, float dado);*/

#include <iostream>

using namespace std;

typedef struct No{
    float info;
    No* prox;
} No;

typedef struct Fila{
    No* inicio;
    No* fim;
} Fila;

Fila* cria(){
    Fila* f = new Fila;
    f->inicio = f->fim = NULL;
    return f;
}

void insere(Fila* f, float v){
    No* aux = new No;
    aux->info = v;
    aux->prox = NULL;
    if(f->fim != NULL){
        f->fim->prox = aux;
    }
    f->fim = aux;
    if(f->inicio == NULL){
        f->inicio = f->fim;
    }
}

int posicaoDoElemento(Fila* f, float dado){
    No* auxiliar = f->inicio;
    //comecei com a variavel na posicao 1 para demarcar posicoes 
    //normais, mas caso voce com etores ou matriz, começaria com 0
    //para demarcar posicoes de variaveis compostas (vetor e matriz)
    int position = 1;
    while(auxiliar != NULL && auxiliar->info != dado){
        auxiliar = auxiliar->prox;
        position++;
    }
    if(auxiliar != NULL && auxiliar->info == dado){
        cout << "VALOR ENCONTRADO NA POSICAO " << position << endl;
        return position;
    } else{
        cout << "VALOR NAO ENCONTRADO!" << endl;
        return -1;
    }
}

int main(void){

    Fila* f = cria();
    insere(f, 6.2);
    insere(f, 7.8);
    insere(f, 9.3);
    insere(f, 4.5);
    float valorProcurado;
    cout << "Digite o valor desejado para ser procurado: ";
    cin >> valorProcurado;
    posicaoDoElemento(f, valorProcurado);


    return 0;
}