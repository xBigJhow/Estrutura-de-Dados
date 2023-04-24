/*6) Elabore uma função que percorra a árvore em pré-ordem e dentro de cada nó seja inserido o número daquele nó, segundo as regras de numeração de árvores. Segue o protótipo abaixo. Elabore também o código para testar a função criada na função main.
void arvorenum( Arvvet* a, int p );

Testando com a arvore feita no exercicio anterior
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
    int num;
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

Arv* pai(Arv* a){
    //retorna o endereço do pai
    return a->pai;
}

int edireita(Arv* a){
    Arv* p = pai(a);
    // Retorna 1 se o endereço do filho direito 
    // do pai for igual ao endereço do no atual.
    return(p->dir == a);
}

int eesquerda(Arv* a){
    Arv* p = pai(a);
    // Retorna 1 se o endereço do filho esquera 
    // do pai for igual ao endereço do no atual.
    return(p->esq == a);
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

void imprimeValor(Arv* a) {
    if (a != NULL) {
        cout << a->num << ":" << a->info << "\n";
        imprimeValor(a->esq); 
        imprimeValor(a->dir);
    }
}

void arvoreNum(Arv *a, int p) {
    if (a == NULL) return;

    a->num = p;
    arvoreNum(a->esq , (2 * p) );
    arvoreNum(a->dir , ( (2 * p ) + 1) );
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

    arvoreNum(a, 1);

    imprimeValor (a);

    
    return 0;
}


