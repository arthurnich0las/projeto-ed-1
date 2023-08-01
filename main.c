#include <stdio.h>

typedef struct {
    char nomeDoenca[50];
    int numSessoes;
    int diasMinimos;
    int diasMaximos;
    float duracaoSessao;
} Procedimento;

void main() {
    printf("SMC - SISTEMA DE MARCAÇÃO DE CONSULTAS\n\n");

    int op;

    while (op != -1) {
        printf("Escolha sua opção\n");
        printf("--- Procedimentos ---\n");
        
        scanf("%d", &op);
    }

    printf("Obrigado por utilizar o sistema!\n");

}