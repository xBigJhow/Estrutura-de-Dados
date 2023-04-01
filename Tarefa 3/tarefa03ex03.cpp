/* Elabore uma função chamada média que calcule a média dos 
valores armazenados em uma lista encadeada e retorne para 
a função que chamou. Elabore também o programa principal 
(main) demonstrando como a função é utilizada. 
Segue o protótipo abaixo: float media(Lista *l);
*/

#include <iostream>

using namespace std;

typedef struct Notas {
    int nota;
    Notas* prox;
} Notas;

Notas* inicializa(){
    return NULL;
}
Notas* insere(Notas* nota, int v) {
    Notas* novo = new Notas;
    novo->nota = v;
    novo->prox = nota;
    return novo;
}
void imprime(Notas* nota) {
    Notas* percorrer = nota;
    cout << "--- COMECO DA LISTA ---" << endl;
    while(percorrer != NULL) {
        cout << "Nota: " << percorrer->nota << endl;
        percorrer = percorrer->prox;
    }
    cout << "--- FIM DA LISTA ---" << endl;
}
float media(Notas* nota) {
    Notas* percorrer = nota;
    int contador = 0;
    int total = 0;
    float media = 0;
    if(percorrer == NULL) {
        cout << "LISTA VAZIA" << endl;
    } else {
        while(percorrer != NULL){
            total += percorrer->nota;
            contador++;
            percorrer = percorrer->prox;
        }
    }
    media = total / contador;
    return media;
    
}

int main(void) {
    Notas* nota = new Notas;
    nota = inicializa();
    nota = insere(nota, 2);
    nota = insere(nota, 4);
    nota = insere(nota, 8);
    nota = insere(nota, 6);
    imprime(nota);
    float m = media(nota);
    cout << "A media eh " << m;
    return 0;
}