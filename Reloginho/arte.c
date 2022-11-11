#include <stdio.h>
#include <unistd.h> // sleep()
#include <stdlib.h> // system()
#include <time.h>   // seed para srand()


// Tempo total de funcionamento do reloǵio
// Como será chamado ao começo da execução,
// é inicializado com -1 para começar em 0
int tempo = -1;

void pos1(int s, int cor) {
	printf("\033[1;3%dm---------\n", cor);
	printf("\033[1;3%dm|   ↑   |\n", cor);
	printf("\033[1;3%dm|       |\n", cor);
	printf("\033[1;3%dm|       |\n", cor);
	printf("\033[1;3%dm---------\n", cor);
	printf("\033[1;37m%ds\n", tempo);
	sleep(s);
	system("clear");
}

void pos2(int s, int cor) {
	printf("\033[1;3%dm---------\n", cor);
	printf("\033[1;3%dm|     ⬈ |\n", cor);
	printf("\033[1;3%dm|       |\n", cor);
	printf("\033[1;3%dm|       |\n", cor);
	printf("\033[1;3%dm---------\n", cor);
	printf("\033[1;37m%ds\n", tempo);
	sleep(s);
	system("clear");
}

void pos3(int s, int cor) {
	printf("\033[1;3%dm---------\n", cor);
	printf("\033[1;3%dm|       |\n", cor);
	printf("\033[1;3%dm|     → |\n", cor);
	printf("\033[1;3%dm|       |\n", cor);
	printf("\033[1;3%dm---------\n", cor);
	printf("\033[1;37m%ds\n", tempo);
	sleep(s);
	system("clear");
}

void pos4(int s, int cor) {
	printf("\033[1;3%dm---------\n", cor);
	printf("\033[1;3%dm|       |\n", cor);
	printf("\033[1;3%dm|       |\n", cor);
	printf("\033[1;3%dm|     ⬊ |\n", cor);
	printf("\033[1;3%dm---------\n", cor);
	printf("\033[1;37m%ds\n", tempo);
	sleep(s);
	system("clear");
}

void pos5(int s, int cor) {
	printf("\033[1;3%dm---------\n", cor);
	printf("\033[1;3%dm|       |\n", cor);
	printf("\033[1;3%dm|       |\n", cor);
	printf("\033[1;3%dm|   ↓   |\n", cor);
	printf("\033[1;3%dm---------\n", cor);
	printf("\033[1;37m%ds\n", tempo);
	sleep(s);
	system("clear");
}

void pos6(int s, int cor) {
	printf("\033[1;3%dm---------\n", cor);
	printf("\033[1;3%dm|       |\n", cor);
	printf("\033[1;3%dm|       |\n", cor);
	printf("\033[1;3%dm| ⬋     |\n", cor);
	printf("\033[1;3%dm---------\n", cor);
	printf("\033[1;37m%ds\n", tempo);
	sleep(s);
	system("clear");
}

void pos7(int s, int cor) {
	printf("\033[1;3%dm---------\n", cor);
	printf("\033[1;3%dm|       |\n", cor);
	printf("\033[1;3%dm| ←     |\n", cor);
	printf("\033[1;3%dm|       |\n", cor);
	printf("\033[1;3%dm---------\n", cor);
	printf("\033[1;37m%ds\n", tempo);
	sleep(s);
	system("clear");
}

void pos8(int s, int cor) {
	printf("\033[1;3%dm---------\n", cor);
	printf("\033[1;3%dm| ⬉     |\n", cor);
	printf("\033[1;3%dm|       |\n", cor);
	printf("\033[1;3%dm|       |\n", cor);
	printf("\033[1;3%dm---------\n", cor);
	printf("\033[1;37m%ds\n", tempo);
	sleep(s);
	system("clear");
}

// Declaração global para facilidade de uso nas funções
int cor, ultimaCor;

void corAleatoria() {
	while (cor == ultimaCor) {
		cor = rand() % 8;
	}
	ultimaCor = cor;

	// Aproveitando que essa função é sempre chamada,
	// aumente o tempo ao final dela
	tempo++;
}

void todasPosicoes(int s) {
	// Posição 1
	corAleatoria();
	pos1(s, cor);

	// Posição 2
	corAleatoria();
	pos2(s, cor);
	
	// Posição 3
	corAleatoria();
	pos3(s, cor);
	
	// Posição 4
	corAleatoria();
	pos4(s, cor);

	// Posição 5
	corAleatoria();
	pos5(s, cor);

	// Posição 6
	corAleatoria();
	pos6(s, cor);

	// Posição 7
	corAleatoria();
	pos7(s, cor);

	// Posição 8
	corAleatoria();
	pos8(s, cor);
}


int main() {
	int segundos;
	printf("Tempo em segundos para o relógio mexer: ");
	scanf("%d", &segundos);

	// Inicialização
	cor = rand() % 8;
	ultimaCor = cor;

	// Seed aleatória para aleatoriedade
	srand((unsigned) time(NULL));

	// Limpa o terminal logo no começo
	system("clear");

	while (1) {
		// Função que chama as outras funções de posição
		todasPosicoes(segundos);
	}
	
	return 0;
}