#include <iostream>

using namespace std;

typedef struct lista {
	int info;
	struct lista *prox;
} Lista;

/* funcao de inicializacao: retorna uma lista vazia */
Lista* inicializa() {
	return NULL;
}

Lista* insere(Lista *l, int num) {
	Lista* novo = new Lista();
	novo->info = num;
	novo->prox = l;
	return novo;
}

/* funcao imprime: imprime valores dos elementos*/
void imprime( Lista* l) {
	Lista* provisorio; /* variavel auxiliar para percorrer a lista*/
	provisorio = l;
	while (provisorio != NULL) {
		cout << "info = " << provisorio->info << endl;
		provisorio = provisorio->prox; /* avança pro proximo elemento*/ 
	}
}

/* funcao vazia: retorna 1 se vazia ou 0 se não vazia*/
int vazia(Lista* l) {
	if(l == NULL){
		return 1;
	} else {
		return 0;
	}
}

Lista* retira(Lista* l, int v) {
	Lista* anterior = NULL; /* ponteiro para elemento anterior */
	Lista* percorrer = l; /* ponteiro para percorrer a lista*/
	/* procura elemento na lista, guardando anterior*/
	while(percorrer != NULL && percorrer->info != v) {
		anterior = percorrer;
		percorrer = percorrer->prox;
	}
	/* verifica se achou elemento */
	if (percorrer == NULL ) {
		/* não achou: retorna a lista original*/
		return l;
	}
	/* retira elemento */
	if(anterior == NULL) {
		/* retira elemento do inicio */
		l = percorrer->prox;
	} else {
		anterior->prox = percorrer->prox;
	}
	delete percorrer;
	return l;
}

void libera(Lista* l) {
	Lista* proximo = l;
	while(proximo != NULL) {
		Lista* temp = proximo->prox; /* guarda referencia para o proximo elemento*/
		delete proximo; /* libera a memoria apontada por proximo*/
		proximo = temp;
	}
	l = NULL; /* evitando que l aponte para memoria desalocada */
}


int main() {
	Lista* l; /* declara uma lista não iniciada*/
	l = inicializa(); /*Inicia uma lista vazia*/
	l = insere(l, 23); /*Insere uma lista o elemento 23*/
	l = insere(l, 45); /*Insere uma lista o elemento 45*/
	l = insere(l, 56); /*Insere uma lista o elemento 56*/
	l = insere(l, 78); /*Insere uma lista o elemento 78*/

	imprime(l); /* imprime os elementos*/
	cout << "Retirando o elemento 78";
	l = retira(l, 78);
	cout << "Retirando o elemento 45";
	l = retira(l, 45);
	imprime(l);
	libera(l);
	return 0;
}
