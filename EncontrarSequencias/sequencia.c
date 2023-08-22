#include <stdio.h>

/*
Desafio:
	Dada uma matriz, diga quantas sequências de 4 letras iguais
	existem em qualquer direção

Entrada:
	n m (int): tamanho da matriz
	n*m caracteres: itens da matriz

Saída:
	q (int): quantidade de sequências de 4 letras 

Ex. 1:
	4 5
	A A C D E
	A A D E F
	C D A A B
	B B F A F

	Resposta: 1

Ex. 2:
	10 10
	A A A A B C D E F G
	H Z Z Z Z A L M F O
	P Q R I A I S T F V
	W X Y A B A V X F Z
	L M A B C D L I O P
	Q I Z Z Z Z E L G H
	I J I L M I J K L M
	X Y Z I Q P X Y Z L
	F F F F I D C B A G
	D D D D H I J K L M

	Resposta: 10

Ex. 3:
	2 5
	A A A A A
	A A D E F

	Resposta: 2
*/

int main() {
	int n, m;
	scanf("%d %d ", &n, &m);

	char matriz[n][m];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%c ", &matriz[i][j]);
		}
	}

	int qtdSequencias = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			// Posições temporárias para serem manipuladas
			// qtdRepete começa em 1 para incluir o 1º elemento na soma
			int posI = i, posJ = j+1, qtdRepete = 1;
			
			// Conferir para leste
			if (m-j >= 4) {
				while (posJ < m) {
					if (matriz[i][posJ] == matriz[i][posJ-1]) {
						posJ++;
						qtdRepete++;

						if (qtdRepete == 4) {
							qtdSequencias++;
							break;
						}
					} else {
						break;
					}
				} // while
			} // if

			posI = i+1, qtdRepete = 1;

			// Conferir para sul
			if (n-i >= 4) {
				while (posI < n) {
					if (matriz[posI][j] == matriz[posI-1][j]) {
						posI++;
						qtdRepete++;

						if (qtdRepete == 4) {
							qtdSequencias++;
							break;
						}
					} else {
						break;
					}
				}	
			}

			posI = i+1, posJ = j+1, qtdRepete = 1;

			// Conferir para sudeste
			if (n-i >= 4 && m-j >= 4) {
				while (posI < n && posJ < m) {
					if (matriz[posI][posJ] == matriz[posI-1][posJ-1]) {
						posI++, posJ++;
						qtdRepete++;
						
						if (qtdRepete == 4) {
							qtdSequencias++;
							break;
						}
					} else {
						break;
					}
				}	
			}
			
			posI = i+1, posJ = j-1, qtdRepete = 1;

			// Conferir para sudoeste
			if (n-i >= 4 && j >= 3) {
				while (posI < n && posJ >= 0) {
					if (matriz[posI][posJ] == matriz[posI-1][posJ+1]) {
						posI++, posJ--;
						qtdRepete++;
						
						if (qtdRepete == 4) {
							qtdSequencias++;
							break;
						}
					} else {
						break;
					}
				} // while
			} // if
		} // for j
	} // for i

	printf("%d\n", qtdSequencias);

	return 0;
}