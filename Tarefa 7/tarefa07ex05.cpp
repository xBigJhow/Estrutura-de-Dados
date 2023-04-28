#include <iostream>
using namespace std;

// Função para fazer a troca de elementos
void trocar(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Função para transformar um sub-árvore em heap
void transforma(int vetor[], int n, int i) {
    int menor = i; // Inicializa o menor como raiz
    int esquerda = 2*i + 1; // índice do filho esquerdo
    int direita = 2*i + 2; // índice do filho direito

    // Se o filho esquerdo for menor que a raiz
    if (esquerda < n && vetor[esquerda] < vetor[menor]) {
        menor = esquerda;
    }

    // Se o filho direito for menor que a raiz
    if (direita < n && vetor[direita] < vetor[menor]) {
        menor = direita;
    }

    // Se o menor não é a raiz
    if (menor != i) {
        trocar(vetor[i], vetor[menor]);

        // Transforma a sub-árvore afetada em heap
        transforma(vetor, n, menor);
    }
}

// Função principal do HeapSort
void heapSort(int vetor[], int n) {
    // Constroi o heap (revetoranja o vetoray)
    for (int i = n/2 - 1; i >= 0; i--) {
        transforma(vetor, n, i);
    }

    // Extrai um por um os elementos do heap
    for (int i=n-1; i>0; i--) {
        // Move a raiz para o fim
        trocar(vetor[0], vetor[i]);

        // Chama transforma na sub-árvore reduzida
        transforma(vetor, i, 0);
    }
}

// Função para imprimir o vetor
void imprimirVetor(int vetor[], int n) {
    for (int i=0; i<n; ++i) {
        cout << vetor[i] << " ";
    }
    cout << "\n";
}

int main() {
    int vetor[] = {10, 9, 8,7,6,5,4,3,2,1};
    int n = sizeof(vetor)/sizeof(vetor[0]);

    heapSort(vetor, n);

    cout << "Vetor ordenado: \n";
    imprimirVetor(vetor, n);
}
