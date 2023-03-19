#include <iostream>

using namespace std;

int i=0;

void exibe_i(){
	cout << "Valor de i: " << i << endl;
}

int main(void) {
	int i=10;
	{
		int i=20;
		cout << "valor de i: " << i << endl;	
	}	
	exibe_i();
	cout << "valor de i: " << i << endl;
	
}
