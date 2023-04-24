/*3) Faça uma função main criar a árvore abaixo, usando as funções ensinadas em aula. 
        R
      /   \
     T     O
   /   \
  H     K

*/

#include <iostream>

using namespace std;

typedef struct arv {
    char info;
    struct arv* esq;
    struct arv* dir;
    struct arv* pai;
} Arv;


char info(Arv* a){
    return a->info;
}

Arv* cria(char raiz){
    //Aloca memoria para o nó/arvore
    Arv* aux = new Arv;
    //Armazena a informação
    aux->info = raiz;

    //Garante que os ponteiros estejam sem lixo
    aux->dir = NULL;
    aux->esq = NULL;
    aux->pai = NULL;

    //Retorna o ponteiro para este nó/arvore.
    return aux;
}

Arv* esquerda(Arv* a){
    //retorna o endereço do filho esquerdo;
    return a->esq;
}

Arv* direita(Arv* a){
    //retorna o endereço do filho direito
    return a->dir;
}


void poeesquerda(Arv* a, char valor){
    //cria sub-arvore
    Arv* tmp = cria(valor);

    //Coloca sub-arvore como filho
    //esquerdo da arvore atual
    a->esq = tmp;

    //Novo filho aponta para seu pai
    tmp->pai = a;
}

void poedireita(Arv* a, char valor){
    //cria uma sub-arvore
    Arv* tmp = cria(valor);

    //coloca sub arvore como filho
    //direito da arvore atual
    a->dir = tmp;

    //Novo filho aponta para seu pai;
    tmp->pai = a;
}

void imprime(Arv* a){
    if(a != NULL){
        //Percorre sub-arvore esquerda
        imprime(a->esq);
        //Percorre sub-arvore direita
        imprime(a->dir);

        //Visita o nó
        cout << info(a) << " ";
    }
}

int main(void) {
    Arv *a, *tmp;
    //Raiz da Arvore R
    a = cria('R');
    // Direita de R tem O e na esquerda tem T
    poedireita(a, 'O');
    poeesquerda(a, 'T');
    // façamos o tmp ser uma subarvore sendo "T" (esquerda da raiz R)
    tmp = esquerda(a);
    //Na esquerda de T tem H e na direita tem K
    poeesquerda(tmp, 'H');
    poedireita(tmp, 'K');

    imprime(a);
    
    return 0;
}


