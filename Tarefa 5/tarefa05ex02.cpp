/* Elaborar uma função com o protótipo abaixo que, dada uma pilha, retorne uma nova pilha que é uma cópia exata da anterior, utilizando somente as funções de pilha existentes, ou seja, push, pop e vazia. Elabore também o programa principal (main) demonstrando como a função é utilizada*/

#include <iostream>

using namespace std;

typedef struct No{
    int valor;
    No* prox;   
} No;

typedef struct Pilha {
    No* topo;
} Pilha;

Pilha* cria(){
    Pilha* p = new Pilha;
    p->topo = NULL;
    return p;
}

void push(Pilha* p, int v){
    No* aux = new No;
    aux-> valor = v;
    aux->prox = p->topo;
    p->topo = aux;
}

int pop(Pilha* p){
    int valor = p->topo->valor;
    No* aux = p->topo;
    p->topo = aux->prox;
    delete aux;
    return valor;
}

void imprime(Pilha *p){
    No* percorre = p->topo;
    while(percorre != NULL){
        cout << percorre->valor << "  ";
        percorre = percorre->prox;
    }
    cout << endl;
}

bool vazia(Pilha* p){
    return (p->topo == NULL);
}

Pilha* copia(Pilha* p){
    Pilha* copia = cria();
    Pilha* aux = cria();
    while(!vazia(p)){
        push(aux, pop(p));
    }
    while(!vazia(aux)){
        int v = pop(aux);
        push(copia, v);
        push(p, v);
    }
    imprime(copia);
    return copia;
}


int main(){
    Pilha* p = cria();
    push(p, 1);
    push(p, 2);
    push(p, 3);
    push(p, 4);
    imprime(p);
    copia(p);
    return 0;
}