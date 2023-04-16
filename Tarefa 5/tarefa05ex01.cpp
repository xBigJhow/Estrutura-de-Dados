/* Desenvolva uma função para algoritmo para inverter a posição dos elementos de uma pilha P. Você pode criar pilhas auxiliares, se necessário. Mas o resultado precisa ser dado na pilha P que foi passada como argumento. Elabore também o programa principal (main) demonstrando como a função é utilizada*/

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

void inverter(Pilha* p){
    Pilha* aux = cria();
    while (p->topo != NULL) {
        push(aux, p->topo->valor);
        No* removido = p->topo;
        p->topo = p->topo->prox;
        delete removido;
    }
    p->topo = aux->topo;
    delete aux;
}

int main(){
    Pilha* p = cria();
    push(p, 1);
    push(p, 2);
    push(p, 3);
    push(p, 4);
    push(p, 5);
    push(p, 6);
    push(p, 7);
    push(p, 8);
    imprime(p);
    inverter(p);
    imprime(p);
    return 0;
}