// PILHAS

// Uma pilha só pode acessar o topo dela, e remover o topo, e inserir no topo
// Por isso vamos criar o primeiro nó, com quais informações vamos querer, depois uma Pilha que só informa o topo

#include <iostream>

using namespace std;

typedef struct No{
    char info;
    struct No* prox;
} No;

typedef struct Pilha{
    No* topo;
} Pilha;

//FUNCOES

//cria uma lista
Pilha* cria(void){
    Pilha* p = new Pilha; //cria a pilha na memória
    p->topo = NULL; // o topo recebe nulo
    return p; // e retorno a pilha criada
}

//inserção de valores
void push(Pilha* p, char c){
    No* aux = new No; //crio um nó auxiliar
    aux->info = c; //coloca o valor dentro do nó
    aux->prox = p->topo; // o meu nó criado agora vai apontar pro topo,
    p->topo = aux;// porque o topo vai virar meu auxiliar, ou seja o topo vai virar segundo item, e meu nó primeiro item
}


//retorna 1 se estiver vazia, e 0 se tiver elementos.
int vazia(Pilha* p){
    return(p->topo == NULL); // se a condicao for verdadeira, "TOPO NULO", retorna true(ou 1 no caso).
}

//deleta o primeiro elemento da pilha
char pop(Pilha* p){
    char v; // crio este valor só para retornar o valor que sera retirado da pilha
    if(vazia(p)){ // chamo a funcao vazia, se ela retornar 1, significa q a pilha esta vazia
        cout << "PILHA VAZIA" << endl;
        exit(1);
    }
    //caso a pilha nao esteja vazia, armazeno o valor do topo da pilha na variavel só para visualizar depois ou para atribuicao posterior
    v = p->topo->info;
    No* segundoElemento = p->topo->prox; //crio um nó que vai armazenar meu segundo elemento, ou seja, o elemento depois do topo, localizaco no p->topo->prox;
    delete p->topo; // deleto lógicamente o topo,
    p->topo = segundoElemento; // e meu segundo elemento armazenado (p->topo->prox) vira meu topo atualmente
    return v; // lembrando, retorno somente para motivo de visualizacao ou atribuicao
}

//apaga todos elementos e libera a memoria,
void libera(Pilha* p){
    No* aux = p->topo; //crio uma variavel q ficará sendo deletada
    No* temp; // e uma variavel temporaria para armazenar o proximo valor antes de ser deletado
    while(aux != NULL){
        temp = aux->prox; // o temporario vai receber o proximo valor 
        delete aux; // deleto o valor atual que esta guardado na variavel "auxiliar"
        aux = temp; // e a variavel "auxiliar" recebe a variavel que estava guardada o proximo valor
    }
    delete p; // apos finalizar a deleção de todos os nós, finalizo deletando a pilha

}

//imprime todos os elementos contidos na pilha
//Porém viola condição de pilha, somente para fins de debugging
//ja q pilha só é acessivel sempre o primeiro item, e nao todos
void imprime(Pilha *p){
    No* aux; // crio um nó auxiliar
    cout << "=== IMPRESSAO ===" << endl;
    aux = p->topo; // esse nó auxiliar recebe meu topo
    while(aux != NULL) {
        cout << aux->info << " ";
        aux = aux->prox;
    }
}

int main(void){

    char t;  // só para armazenar o ultimo elemento que daremos "pop" para fins de visualização
    Pilha* p = cria(); // cria uma pilha,
    push(p, 'a'); // insere os valores
    push(p, 'b'); // "A", "B"  e "C"
    push(p, 'c'); // para ficar "ABC" a pilha
    t = pop(p); // atribuimos a ultima letra inserida na pilha para a variavel T
    cout << "elemento retirado do topo: " << t << endl; // depois imprimos essa letra só para visualização
    imprime(p); // depois imprimimos toda a pilha
    libera(p); // por final liberamos a pilha toda

    return 0;
}

