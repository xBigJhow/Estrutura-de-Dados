/*Elaborar uma função que compare duas filas e retorne 1 ou true se elas forem iguais ou 0 ou false se forem diferentes. Duas filas são iguais se os elementos forem iguais, nas mesmas posições e tiverem o mesmo tamanho. Faça um programa principal demonstrando como ela é usada.
int *compara(Lista *l1, Lista *l2);*/

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

int compara(Fila* l1, Fila* l2){
    No* auxiliar1 = l1->inicio;
    No* auxiliar2 = l2->inicio;

    while(auxiliar1 != NULL && auxiliar2 != NULL){
        if (auxiliar1->info != auxiliar2->info) {
            cout << "LISTAS DIFERENTES" << endl;
        }
        auxiliar1 = auxiliar1->prox;
        auxiliar2 = auxiliar2->prox;
    }
    if (auxiliar1 == NULL && auxiliar2 == NULL) {
        cout << "LISTAS IGUAIS" << endl;
        return 1;
    } else{
        return 0;
    }
}

int main(void){

    Fila* l1 = cria();
    Fila* l2 = cria();
    insere(l1, 6.2);
    insere(l1, 7.8);
    insere(l2, 6.2);
    insere(l2, 7.8);
    compara(l1, l2);

    return 0;
}