/*5) Ilustre como ocorre a impressão dos nós da árvore abaixo usando os três algoritmos de percurso: Pré-ordem, Ordem Simétrica e Pós-ordem.:
           A
       /      \
     C         Y
   /   \     /   \
  D     R   F    X

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

void imprime_pre(Arv* a){
    if( a != NULL){
        //VISITA O nó
        cout << info(a) << "";
        //Percorre sub-arvore esquerda
        imprime_pre(a->esq);

        //Percorre sub-arvore direita
        imprime_pre(a->dir);
    }
}

void imprime_sim(Arv* a){
    if( a != NULL){
        //Percorre sub-arvore esquerda
        imprime_sim(a->esq);

        //VISITA O nó
        cout << info(a) << "";

        //Percorre sub-arvore direita
        imprime_sim(a->dir);
    }
}

void imprime_pos(Arv* a){
    if( a != NULL){
        //Percorre sub-arvore esquerda
        imprime_pos(a->esq);

        //Percorre sub-arvore direita
        imprime_pos(a->dir);
        
        //VISITA O nó
        cout << info(a) << "";

    }
}



int main(void) {
    Arv *a, *tmp;
    //Raiz da Arvore A
    a = cria('A');
    // Criamos 2 filhos, C na esquerda, Y na direita
    poedireita(a, 'Y');
    poeesquerda(a, 'C');
    // façamos o tmp ser uma subarvore sendo "C" (esquerda da raiz A)
    tmp = esquerda(a);
    //Na esquerda de C tem D e na direita tem R
    poeesquerda(tmp, 'D');
    poedireita(tmp, 'R');
    // façamos o tmp ser uma subarvore sendo "Y" (direita da raiz A)
    tmp = direita(a);
    //Na esquerda de Y tem F e na direita tem X
    poeesquerda(tmp, 'F');
    poedireita(tmp, 'X');

    cout << "Impressao Pre Ordem: ";
    imprime_pre(a);
    cout << "\nImpressao Pos Ordem: ";
    imprime_pos(a);
    cout << "\nImpressao Simetrica: ";
    imprime_sim(a);

    
    return 0;
}


