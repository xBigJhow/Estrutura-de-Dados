#include <iostream>

using namespace std;

typedef struct Lista{
    int valor;
    Lista* prox;
} Lista;

Lista* inicializa() {
    return NULL;
}

Lista* insere(Lista* lista, int valor) {
    Lista* novo = new Lista;
    novo->valor = valor;
    novo->prox = NULL;
    if(lista == NULL){
        lista = novo;
    } else {
        Lista* percorrer = lista;
        while(percorrer->prox != NULL) {
            percorrer = percorrer->prox;
        }
        percorrer->prox = novo;
    }

}


int main(void){
    Lista* lista = new Lista;

    lista = insere(lista, 1);
    lista = insere(lista, 2);
    lista = insere(lista, 3);
    lista = insere(lista, 4);

    return 0;
    
}