#include <stdio.h>

double somaHarmonica(int n) {
    if (n == 1) {
        return 1.0;
    } else {
        return 1.0 / n + somaHarmonica(n - 1);
    }
}

int main() {
    int n;
    printf("Digite um número inteiro n: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("O número deve ser positivo.\n");
    } else {
        double resultado = somaHarmonica(n);
        printf("A soma da série harmônica até %d termos é: %lf\n", n, resultado);
    }

    return 0;
}
