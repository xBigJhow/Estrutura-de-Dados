/*  1)O programa abaixo possui um erro. Corrija-o para que funcionem conforme o esperado.
void main() {
	int x, *p;
	x = 100; 
	p = x; 
	printf("Valor de p: %d.\n", *p);
} 
*/
#include <stdio.h>
#include <iostream>

int main(){	
	int x, *p;
	p = new int;
	x = 100;
	*p = x;
	printf("Valor de p: %d.\n", *p);
}

