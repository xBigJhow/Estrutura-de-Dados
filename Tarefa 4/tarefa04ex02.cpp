/* Elaborar uma função que gere uma cópia de uma fila e retorne uma nova fila. Elabore também o programa principal (main) demonstrando como a função é utilizada. Segue o protótipo abaixo:
Fila *copia(Fila *l);
*/

#include <iostream>

using namespace std;

typedef struct No{
    int valor;
    No* prox;
} No;

typedef struct Fila{
    No* inicio;
    No* fim;
} Fila;

Fila* cria(){
    Fila* f = new Fila;
    f->inicio = f-> fim = NULL;
}

void insere(Fila* f, int v){
    No* aux = new No;
    aux->valor = v;
    aux->prox = NULL;

    if(f->fim != NULL){
        f->fim->prox = aux;
    }
    f->fim = aux;
    if(f->inicio == NULL){
        f->inicio = f->fim;
    }
}

Fila* copia(Fila* l){
    Fila* copy = new Fila;
    copy->inicio = copy->fim = NULL;
    No* auxiliar = new No;
    while(l != NULL){
        copy->fim = l->fim;
        copy->inicio = l->inicio;
        l->fim = l->fim->prox;
    }
}

Fila* copia(Fila* l){
    Fila* copy = cria(); // cria uma nova fila vazia
    No* auxiliar = l->inicio;
    while(auxiliar != NULL){ // percorre a fila original
        insere(copy, auxiliar->valor); // insere cada nó na fila de cópia
        auxiliar = auxiliar->prox;
    }
    return copy; // retorna a fila de cópia
}

int main(void){

    Fila* l = new Fila;
    l = cria();
    insere(l, 1);
    insere(l, 2);
    insere(l, 3);
    Fila* copy = copia(l);
    

    return 0;
}