/* 3)Se i e j sao variaveis inteiras e p e q ponteiros para int, quais das seguintes expressoes de atribuicao sao ilegais? 
a) p = &i; -> Válido, pois ao mostrar "*p", retorna o valor inteiro.
b) *q = &j; -> Erro de conversão entre "*" e "&".
c) p = &*&i; -> Válido, pois ao mostrar "*p", retorna valor inteiro.
d) i = (*&)j; -> Inválido. Expressão incorreta.
e) i = *&j; -> Válido. Consegue apontar para o endereço e valor da variavel
f) i = *&*&j; -> Válido. Consegue apontar para o endereço e valor da variavel
g) q = *p; -> Caso q e p tenha iniciado com valores, válido, caso não, inválido. Pois por ser ponteiros um pode apontar pro outro mas tem que haver valores.

*/

#include <stdio.h>

int main() {

	int i= 2, j=3;
	int *p, *q;
	
	q = *p;
	
	printf("%d", *q);
}


