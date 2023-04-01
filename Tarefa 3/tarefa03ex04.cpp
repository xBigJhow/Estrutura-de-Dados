/*) Elabore uma versão da função inicializa que já faça a inserção de um elemento 
no início da lista encadeada (sem usar a função insere). 
Faça um programa principal demonstrando como ela é usada.
Lista *inicializa(int valor);*/
#include <iostream>

using namespace std;

typedef struct Lista {
    int valor;
    Lista* prox;
} Lista;

Lista* inicializa(int valor){  
    Lista* novo = new Lista;
    novo->valor = valor;
    novo->prox = NULL;
    return novo;

}

int main(void){
    Lista* lista = new Lista;

    lista = inicializa(5);

    return 0;

}

