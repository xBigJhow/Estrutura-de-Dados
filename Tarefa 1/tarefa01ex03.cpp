/* 3)Se i e j sao variaveis inteiras e p e q ponteiros para int, quais das seguintes expressoes de atribuicao sao ilegais? 
a) p = &i; -> V�lido, pois ao mostrar "*p", retorna o valor inteiro.
b) *q = &j; -> Erro de convers�o entre "*" e "&".
c) p = &*&i; -> V�lido, pois ao mostrar "*p", retorna valor inteiro.
d) i = (*&)j; -> Inv�lido. Express�o incorreta.
e) i = *&j; -> V�lido. Consegue apontar para o endere�o e valor da variavel
f) i = *&*&j; -> V�lido. Consegue apontar para o endere�o e valor da variavel
g) q = *p; -> Caso q e p tenha iniciado com valores, v�lido, caso n�o, inv�lido. Pois por ser ponteiros um pode apontar pro outro mas tem que haver valores.

*/

#include <stdio.h>

int main() {

	int i= 2, j=3;
	int *p, *q;
	
	q = *p;
	
	printf("%d", *q);
}


