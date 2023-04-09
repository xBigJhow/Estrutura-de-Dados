/*Elaborar uma função que concatene duas filas e retorne uma nova fila. Elabore também o programa principal (main) demonstrando como a função é utilizada. Segue o protótipo abaixo: 
Fila *concatena(Fila *l1, Fila *l2);*/

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

Fila* concatena(Fila* l1, Fila* l2){
    //primeiro criei uma nova lista
    Fila* l3 = cria();
    No* aux = l1->inicio;
    //depois percorri todos os elementos da l1, e adicionando com a
    //funcao insere, todos os valores na l3,
    while(aux != NULL){
        insere(l3, aux->info);
        aux = aux->prox;
    }
    //repeti o mesmo com a l2
    aux = l2->inicio;
    while(aux != NULL){
        insere(l3, aux->info);
        aux = aux->prox;
    }
    //retorno a l3, com todos elementos da l1 e l2
    return l3;
}

int main(void){

    Fila* l1 = cria();
    Fila* l2 = cria();
    insere(l1, 6.2);
    insere(l1, 7.8);
    insere(l2, 9.3);
    insere(l2, 4.5);

    Fila* l3 = concatena(l1, l2);

    return 0;
}