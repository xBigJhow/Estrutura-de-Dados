#include <iostream>

using namespace std;

//STRUCT
typedef struct Notas{
    int valor;
    Notas* prox;
} Notas;

//
Notas* inicializa(){
    return NULL;
}

// ela cria uma nova estrutura, essa estrutura aponta pra estrutura anterior, e retorna a nova estrutura.
Notas* insere(Notas* nota, int valor) {
    // aqui ele inicializa colocando valor null em "NOVO"
    Notas* novo = new Notas;
    //ESSE NOVO RECEBE O VALOR QUE ADICIONEI
    novo->valor = valor;
    /// E APONTO pro ULTIMO VALOR PASSADO. 
    novo->prox = nota;
    return novo;
}

void imprime(Notas* nota) {
    //Como estou inicializando uma estrutura, ela tem q apontar para a primeira nota... depois vai percorrendo a estrutura
    Notas* percorrer = nota;
    // aqui ele inicializa uma estrutura com a lista, e logo apos começa percorrer ate que o valor seja NULL ou seja, chegou no fim da lista.
    while(percorrer != NULL) {
        cout << "NOTA = " << percorrer->valor << endl;
        percorrer = percorrer->prox;
    }
    cout << "--------- FIM DA LISTA --------------" << endl;
}

Notas* remove(Notas* nota, int valor) {
    Notas* percorrer = nota;
    Notas* anterior = NULL;
    // aqui eu vou percorrer, ate meu percorrer for diferente de NULL e meu valor for diferente do valor. Ou seja, ele tem que percorrer ate o final da lista encadeada
    // e ao memso tempo tem que parar no valor que pedi para achar, caso ele acha tambem para
    while(percorrer != NULL && percorrer->valor != valor){
        //aqui eles vao trocando, o anterior recebe a estrutura do percorrer e o percorrer recebe o proximo
        anterior = percorrer;
        percorrer = percorrer->prox;
    }
    // se meu percorrer foi NULL significa que nao tinha o valor dentro da lista e por isso, eu retorno a lista normal
    if(percorrer == NULL) {
        return nota;
    }
    // aqui se meu anterior for igual a null significa que o valor achado era o primeiro da lista, ja que o anterior nem apontou pra nenhum percorrer
    if(anterior == NULL) {
        // a minha lista encadeada recebe o proprio percorrer no proximo, ou seja, o meu percorrer começou no primeiro elemento da lista, 
        // como ele é o primeiro é só apontar pro proximo e boa...
        nota = percorrer->prox;
    } else {
        //aqui é caso o meu elemento já achado nao seja o primeiro da lista
        // eu simplesmente pulo uma lacuna, do anterior apontando pro proximo eu pulo pro meu proximo do percorrer
        anterior->prox = percorrer->prox;
    }
    //aqui eu deleto o meu percorrer, que é justo o valor que meu percorrer achou, e que passei pra ser achado.
    delete percorrer;
    //e depois eu tenho que retornar a lista, pois minha funcao é do tipo "retorno de lista"
    return nota;
}

void libera(Notas* nota) {
    //inicializo um ponteiro auxiliar para ir excluindo um por um
    Notas* percorrer = nota;
    //enquanto meu ponteiro não apontar pro fim da lista, que é o valor NULL
    while(percorrer != NULL) {
        Notas* auxiliar = percorrer->prox;
        delete percorrer;
        percorrer = auxiliar;
    }
}



int main(void){
    Notas* nota = new Notas;

    nota = inicializa();
    nota = insere(nota, 10);
    nota = insere(nota, 8);
    nota = insere(nota, 5);
    nota = insere(nota, 3);
    nota = insere(nota, 7);
    nota = insere(nota, 6);
    imprime(nota);

    nota = remove(nota, 5);

    imprime(nota);
    


    return 0;
}