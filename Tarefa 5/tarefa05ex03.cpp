/* Elabore uma função que verifique se o uso dos parênteses em uma expressão matemática está correto utilizando uma pilha. O número de ( tem que ser igual ao número de ), utilizando somente as funções de pilha existentes, ou seja, push, pop e vazia. retorna 1 se for valida e 0 se não for. Elabore também o programa principal (main) demonstrando como a função é utilizada.*/
#include <iostream>
#include <cstring>

using namespace std;

typedef struct No {
    char valor;
    No* prox;
} No;

typedef struct Pilha {
    No* topo;
} Pilha;

Pilha* cria() {
    Pilha* p = new Pilha;
    p->topo = NULL;
    return p;
}

void push(Pilha* p, char v) {
    No* aux = new No;
    aux->valor = v;
    aux->prox = p->topo;
    p->topo = aux;
}

char pop(Pilha* p) {
    if (p->topo == NULL) {
        return ' ';
    }
    char v = p->topo->valor;
    No* aux = p->topo;
    p->topo = p->topo->prox;
    delete aux;
    return v;
}

int vazia(Pilha* p) {
    return (p->topo == NULL);
}

int validaExpressao(char expressao[]) {
    Pilha* p = cria();
    int tamanho = strlen(expressao);
    for (int i = 0; i < tamanho; i++) {
        if (expressao[i] == '(') {
            push(p, expressao[i]);
        } else if (expressao[i] == ')') {
            if (vazia(p)) {
                return 0;
            } else {
                pop(p);
            }
        }
    }
    int valida = vazia(p);
    delete p;
    return valida;
}

int main() {
    char expressao1[] = "((2+3)*4)";
    char expressao2[] = "(2+3)*4)";
    char expressao3[] = "((2+3)*4";
    cout << "Expressao 1: " << validaExpressao(expressao1) << endl;
    cout << "Expressao 2: " << validaExpressao(expressao2) << endl;
    cout << "Expressao 3: " << validaExpressao(expressao3) << endl;
    return 0;
}