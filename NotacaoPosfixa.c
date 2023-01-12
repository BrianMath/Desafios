#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define precedencia_parenteses 1
#define precedencia_vezesDivisao 2
#define precedencia_exponenciacao 3
#define precedencia_maisMenos 4

/* Criar pilha */
typedef struct campo {
	char simbolo;
	int precedencia;
	struct campo* proximo;
} Campo;

typedef struct {
	Campo* base;
	Campo* topo;
} Pilha;
/***************/

Pilha* criarPilha() {
	Pilha* p = (Pilha*) calloc(1, sizeof(Pilha));

	if (p == NULL) {
		exit(1);
	}

	p->base = NULL;
	p->topo = NULL;
	
	return p;
}

Campo* criarCampo(char simbolo) {
	Campo* c = (Campo*) calloc(1, sizeof(Campo));

	if (c == NULL) {
		exit(1);
	}

	c->proximo = NULL;
	c->simbolo = simbolo;

	if (simbolo == '(') {
		c->precedencia = precedencia_parenteses;
	} else if (simbolo == '+' || simbolo == '-') {
		c->precedencia = precedencia_maisMenos;
	} else if (simbolo == '^') {
		c->precedencia = precedencia_exponenciacao;
	} else if (simbolo == '*' || simbolo == '/') {
		c->precedencia = precedencia_vezesDivisao;
	}	
	
	return c;
}

void addPilha(Pilha* p, char simbolo) {
	if (p == NULL) {
		exit(1);
	}
	
	Campo* c = criarCampo(simbolo);

	if (p->base == NULL) {
		p->base = c;
	} else {
		Campo* aux = p->base;

		while (aux->proximo != NULL) {
			aux = aux->proximo;
		}
		
		aux->proximo = c;
	}

	// Sempre o novo a ser adicionado ficará no topo
	p->topo = c;
}

char removePilha(Pilha *p) {
	if (p == NULL) {
		exit(1);
	}

	Campo* aux = p->topo;
	Campo* anterior = NULL;
	char simbolo;

	while (aux->proximo != NULL) {
		
	}
	
	return simbolo;
}

/**
 * Compara a precedência do que está no topo da pilha com a do 'operador'.
 * Caso a precedência seja maior (ou pilha está vazia), adiciona à pilha.
 * Caso seja menor ou igual, desempilha o que está no topo e adiciona à pilha.
 * @return 1: operador tem precedência maior | 0: precedência menor
*/
int verificarPrecedencia(Pilha *p, int precedencia) {
	if (precedencia > p->topo->precedencia || p->topo == NULL) {
		return 1;
	} else {
		return 0;
	}
}


int main() {
	int qtdTestes;
	char expressao[1000];

	Pilha* pilha = criarPilha();

	scanf("%d", &qtdTestes);

	while (qtdTestes--) {
		scanf("%*c%s", expressao);

		for (int i = 0; i < strlen(expressao); i++) {
			char caracter = expressao[i];
			char noTopo = "";

			// Caso seja um número simplesmente imprima
			if (isdigit(caracter)) {
				printf("%c ", caracter);
				continue;
			}
			
			// Sempre adicione '(' à pilha
			if (caracter == '(') {
				addPilha(pilha, '(');
				continue;
			}
			
			/* Se for um operador, vamos verificar a precedencia */
			if (caracter == '+' || caracter == '-') {
				if (verificarPrecedencia(pilha, precedencia_maisMenos)) {
					addPilha(pilha, caracter);
				} else {
					noTopo = removePilha(pilha);
				}
			}
			
			/*****************************************************/
		}
	}

	return 0;
}
