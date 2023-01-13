#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define precedencia_parenteses 1
#define precedencia_maisMenos 2
#define precedencia_vezesDivisao 3
#define precedencia_exponenciacao 4

/* Criar pilha */
typedef struct campo {
	char simbolo;
	int precedencia;
	struct campo* proximo;
	struct campo* anterior;
} Campo;

typedef struct {
	Campo* base;
	Campo* topo;
	int tamanho;
} Pilha;
/***************/

Pilha* criarPilha() {
	Pilha* p = (Pilha*) calloc(1, sizeof(Pilha));

	if (p == NULL) {
		exit(1);
	}

	p->base = NULL;
	p->topo = NULL;
	p->tamanho = 0;
	
	return p;
}

Campo* criarCampo(char simbolo) {
	Campo* c = (Campo*) calloc(1, sizeof(Campo));

	if (c == NULL) {
		exit(1);
	}

	c->proximo = NULL;
	c->anterior = NULL;
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

	// Na 1ª vez a base será o primeiro campo c, nas próximas a base não muda
	if (p->base == NULL) {
		p->base = c;
	}

	if (p->topo != NULL) {
		// O campo atual é o próximo do campo que estava no topo anteriormente
		p->topo->proximo = c;
		// O campo anterior ao atual é o que estava no topo anteriormente
		c->anterior = p->topo;	
	}

	/**
	 * Exemplificando as duas atribuições atrás:
	 * Vai adicionar 'c':	
	 * 
	 * y (topo) => y->c && y<-c => c
	 * z		=> z			=> y
	 * 							   z
	*/

	// Sempre o novo a ser adicionado ficará no topo
	p->topo = c;

	p->tamanho++;
}

char removeDaPilha(Pilha *p) {
	if (p == NULL || p->tamanho <= 0) {
		exit(1);
	}

	char simbolo = p->topo->simbolo;

	// aux é o campo abaixo do topo (a penúltima posição)
	Campo* aux = p->topo->anterior;
	// Se existir algum campo anterior ao topo agora ele não tem mais próximo, ...
	// ... então se desaloca o campo que estava no topo e se referencia o novo
	if (aux != NULL) {
		aux->proximo = NULL;
		// free(p->topo);
		p->topo = NULL;
		p->topo = aux;
	}
	// Caso o topo e a base sejam o mesmo campo só se desaloca o campo
	else {
		// free(p->topo);
		p->topo = NULL;
		p->base = NULL;
	}
	
	p->tamanho--;

	return simbolo;
}

/**
 * Compara a precedência do que está no topo da pilha com a do 'operador'.
 * Caso a precedência seja maior (ou pilha estiver vazia), adiciona à pilha.
 * Caso seja menor ou igual, desempilha o que está no topo e adiciona à pilha.
 * @return 1: operador tem precedência maior | 0: precedência menor
*/
int verificarPrecedencia(Pilha *p, int precedencia) {
	if (p->tamanho <= 0) {
		return 1;
	}
	if (precedencia > p->topo->precedencia) {
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
		scanf("%*c%[^\n]", expressao);

		for (int i = 0; i < strlen(expressao); i++) {
			char caracter = expressao[i];
			char noTopo;
			int precedencia;

			// Caso seja espaço em branco ignore
			if (caracter == ' ') {
				continue;
			}

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

			// Quando achar um ')' desempilhe até o primeiro '(' sem mostrar ele
			if (caracter == ')') {
				while (1) {
					noTopo = removeDaPilha(pilha);

					if (noTopo != '(') {
						printf("%c ", noTopo);
					} else {
						break;
					}
				}
				
				continue;
			}
			
			/* Se for um operador, vamos verificar a precedência */
			if (caracter == '+' || caracter == '-' || caracter == '*' || caracter == '/' || caracter == '^') {
				if (caracter == '+' || caracter == '-') {
					precedencia = precedencia_maisMenos;
				} else if (caracter == '*' || caracter == '/') {
					precedencia = precedencia_vezesDivisao;
				} else if (caracter == '^') {
					precedencia = precedencia_exponenciacao;
				}
				
				// Se tiver precedência maior é adicionado ao topo da pilha
				if (verificarPrecedencia(pilha, precedencia)) {
					addPilha(pilha, caracter);
				}
				// Se tiver precedência <= se desempilha o topo, imprime e se empilha o atual
				else {
					noTopo = removeDaPilha(pilha);
					printf("%c ", noTopo);
					addPilha(pilha, caracter);
				}

				continue;
			}
			/*****************************************************/
		}

		while (pilha->tamanho > 0) {
			printf("%c ", removeDaPilha(pilha));
		}

		printf("\n");
	}

	free(pilha);

	return 0;
}
