#include <iostream>

using namespace std;

typedef struct No{
    float info;
    struct No* prox;
} No;

typedef struct Fila{
    No *inicio;
    No *fim;
} Fila;


Fila* cria(void){
    //cria a fila, inicialmente
    Fila* f = new Fila;
    // e os 2 parametros da fila, inicio e fim são nulos.
    f->inicio = f->fim = NULL;
    //retorna a fila criada apotando nulo
    return f;
}

void insere(Fila* f, float v){ // O NOVO NÓ SEMPRE SERÁ COLOCADO NO FIM DA FILA
    No* auxiliar = new No; //Cria-se um nó
    auxiliar->info = v;    //a informação do nó é guardada do valor passado
    auxiliar->prox = NULL;  //fim da fila.

    //Se tiver algum elemento no fim ou seja se meu argumento f-> não estiver no NULO.
    if(f->fim != NULL) {
        //entao o ultimo elemento se torna o penultimo, ou seja, meu f->fim->prox = auxiliar;
        f->fim->prox = auxiliar;
    }
    // o novo nó se torna o ultimo da fila
    f->fim = auxiliar;
    //Se a fila estava vazia
    if(f->inicio == NULL){
        f->inicio = f->fim;
    }

}

int vazia(Fila* f){
    //Retorna verdade (1) se a fila estiver vazia
    //senão retorna falso (0)
    if(f->inicio == NULL) {
        return 1;
    } else{
        return 0;
    }
}

float retira(Fila* f){
    float v;
    //se estiver vazia
    if(vazia(f)) {
        cout << "Fila Vazia" << endl;
        exit(1); //aborta programa
    }
    v = f->inicio->info; // salva valor do primeiro nó na variavel que acabamos de criar
    // salva referencia para o segundo nó
    No* segundo = f->inicio->prox;
    delete f->inicio; //remove o primeiro no

    f->inicio = segundo; // segundo se torna o primeiro
    if(f->inicio == NULL) {
        // se a fila ficou vazia o fim recebe NULO
        f->fim = NULL;
    }
    return v;
}

void libera(Fila* f){
    //ponteiro auxiliar percorre lista
    No* aux = f->inicio;
    // ponteiro temporário para liberação
    No* temp;
    while(aux != NULL) {
        temp = aux-> prox;
        delete aux;
        aux = temp;
    }
    delete f;
}

void imprime(Fila* f){
    //crio um nó auxiliar, esse nó vai receber o inicio
    No* aux;
    aux = f->inicio;
    while(aux != NULL){
        // e enquanto esse nó for diferente de nulo, ele vai sendo impresso e recebendo o proximo
        cout << aux->info << " ";
        aux = aux->prox;
    }
    cout << endl;
}


int main(void){

    Fila* f = cria();
    insere(f, 20.1);
    insere(f, 41.3);
    insere(f, 6.2);
    cout << "# Fila Antes:    ";
    imprime(f);
    float elemento1 = retira(f);
    float elemento2 = retira(f);
    cout << "Primeiro elemento: " << elemento1 << endl;
    cout << "Segundo elemento: " << elemento2 << endl;
    cout << "# Fila Depois:    ";
    imprime(f);
    libera(f);

    return 0;
}