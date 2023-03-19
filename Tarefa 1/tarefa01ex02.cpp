/* 2)Dado o seguinte trecho de programa:
	
int i=6,j=2;
int *p, *q;
p = &i;
q = &j;

Qual e o valor das seguintes expressoes ?

a) p == &i;   true;
b) *p - *q = 4              
c) **&p = 6  
d) 3 * *p/(*q)+7 = 16
*/

#include <stdio.h>

int main() {
	int i=6, j=2;
	int *p, *q;
	p = &i;
	q = &j;
	int expression;
	expression = 3 * *p / (*q) + 7;
	printf("%d", expression);
}

