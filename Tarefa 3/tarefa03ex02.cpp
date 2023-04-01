/* Elabore uma função chamada busca que encontre um elemento em uma lista 
encadeada e retorne a posição do elemento para a função que chamou. 
Caso não encontre o elemento, o valor NULL deverá ser retornado. 
Elabore também o programa principal (main) demonstrando como a função é utilizada. 
Segue o protótipo abaixo: Lista *busca(Lista *l, int valor);*/
#include <iostream>

using namespace std;

//DEFININADO A ESTRUTURA
typedef struct Lista{
    int valor;
    Lista* prox;
}Lista;

//INICIALIZANDO A ESTRUTURA
Lista* inicializa() {
    return NULL;
}

Lista* insere(Lista* l, int valor) {
    Lista* novo = new Lista;
    novo->valor = valor;
    novo->prox = l;
    return novo;
}

Lista* busca(Lista* l, int valor) {
    Lista* percorrer = l;
    int contador = 0;
    while(percorrer != NULL && percorrer->valor!= valor) {
        percorrer = percorrer->prox;
        contador++;
    }
    if(percorrer != NULL && percorrer->valor == valor){
        cout << "VALOR ACHADO NA POSICAO " << contador << endl;
        return l;
    } else {
        return NULL;
    }
}

int main(void) {
    Lista* l = new Lista;
    l = inicializa();
    l = insere(l, 1);
    l = insere(l, 2);
    l = insere(l, 3);
    l = insere(l, 4);
    l = insere(l, 5);
    l = insere(l, 6);
    busca(l, 3);

    return 0;
}