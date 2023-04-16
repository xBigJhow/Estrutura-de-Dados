/* Elabore uma função que verifique se uma palavra é um palíndromo. Palíndromos são palavras iguais se faladas de frente para trás ou de trás para frente ex: ovo, arara, osso, radar, socos, sopapos) utilizando uma pilha), utilizando somente as funções de pilha existentes, ou seja, push, pop e vazia. retorna 1 se for valida e 0 se não for. Elabore também o programa principal (main) demonstrando como a função é utilizada*/
#include <iostream>
#include <string.h>

using namespace std;

typedef struct No{
    char letra;
    No* prox;
} No;

typedef struct Pilha{
    No* topo;
} Pilha;

Pilha* cria(){
    Pilha* p = new Pilha;
    p->topo = NULL;
    return p;
}

void push(Pilha* p, char v){
    No* aux = new No;
    aux-> letra = v;
    aux->prox = p->topo;
    p->topo = aux;
}

char pop(Pilha* p){
    if(p->topo == NULL){
        cout << "Pilha vazia." << endl;
        return ' ';
    }
    No* aux = p->topo;
    char valor = aux->letra;
    p->topo = p->topo->prox;
    delete aux;
    return valor;
}

bool vazia(Pilha* p){
    return (p->topo == NULL);
}

bool palindromo(char* palavra){
    Pilha* p = cria();
    int tam = strlen(palavra);
    int i;
    for(i = 0; i < tam; i++){
        push(p, palavra[i]);
    }
    for(i = 0; i < tam; i++){
        if(palavra[i] != pop(p)){
            return false;
        }
    }
    return true;
}

int main(){

    char palavra[100];
    cout << "Digite a palavra: ";
    cin >> palavra;

    if(palindromo(palavra)){
        cout << "Palindromo" << endl;
    }else{
        cout << "Nao palindromo" << endl;
    }

    return 0;
}
