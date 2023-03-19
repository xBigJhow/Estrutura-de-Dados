#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int main() {
	
	// criando variáveis
	float *vetor;
	int tamanho;
	float tamMaiorAluno, tamMenorAluno;
	int posMenorAluno, posMaiorAluno;
	//Lendo tamanho da turma
	cout << "Digite o tamanho da turma: ";
	cin >> tamanho;
	//Ponteiro recebe o endereço de memória que foi alocado ao vetor
	vetor = new float[tamanho];
	
	//Loop para inserir a altura dos alunos
	for(int i=0; i<tamanho; i++) {
		cout << "Tamanho do " << i+1 <<"o estudante: ";
		cin >> vetor[i];
	}
	//Agora verificando quem é o menor ou maior estudante da turma.
	for(int i=0; i<tamanho; i++) {
		if(i==0) {
			tamMaiorAluno = vetor[i];
			tamMenorAluno = vetor[i];
			posMaiorAluno = i;
			posMenorAluno = i;
		} else {
			if(vetor[i] > tamMaiorAluno) {
				tamMaiorAluno = vetor[i];
				posMaiorAluno = i;
			}
			if(vetor[i] < tamMenorAluno) {
				tamMenorAluno = vetor[i];
				posMenorAluno = i;
			}
		}
	}
	//Agora mostrando resultado.
	cout << "Menor aluno na posição " << posMenorAluno + 1 << " com altura de " << tamMenorAluno<< "mts.\n";
	cout << "Maior aluno na posição " << posMaiorAluno + 1 << " com altura de " << tamMaiorAluno<< "mts.\n";
}
