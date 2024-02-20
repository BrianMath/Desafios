#include <iostream>


typedef struct {
	char* nome;
	double potencia;
	double tempo_ativo;
} Eletro;


int main() {
	/*
	Faça um programa que controla o consumo de energia dos eletrodomésticos de uma casa e:
	* Crie e leia 5 eletrodomésticos que contém nome (máximo 15 letras), potência (real, em kW) e tempo ativo por dia (real, em horas).
	* Leia um tempo t (em dias), calcule e mostre o consumo total na casa e o consumo relativo de cada eletrodoméstico (consumo/consumo total) nesse período de tempo.
	* Apresente este ultimo dado em porcentagem.
	*/

	Eletro eletros[5];

	for (int i = 0; i < 5; i++) {
		char nome[15];

		scanf(" %14s", nome);
		eletros[i].nome = nome;
		scanf("%lf", &eletros[i].potencia);
		scanf("%lf", &eletros[i].tempo_ativo);
	}

	int dias;
	scanf("%d", &dias);

	for (int i = 0; i < 5; i++) {
		
	}
	
	
	return 0;
}