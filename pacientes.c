#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct{
    char nome[50];
    char CPF[12];
    char doenca[50];
} Paciente;

void cadastrarPaciente(Paciente *paciente){
    printf("Para comecar o cadastro, digite seu nome: ");
    scanf("%[^\n]", paciente->nome);
    getchar();
    
    printf("Digite seu CPF: ");
    scanf(" %[^\n]", paciente->CPF);

    printf("Agora, digite a doenca que voce deseja tratar: ");
    scanf(" %[^\n]", paciente->doenca);

    printf("\n");
    return;
}

void removerPaciente(Paciente *paciente) {
    // Redefinir os campos da estrutura para valores vazios ou nulos
    strcpy(paciente->nome, "");
    strcpy(paciente->CPF, "");
    strcpy(paciente->doenca, "");
    printf("\n");
}

void atualizarPaciente(Paciente *paciente) {
    char update[10];
    char novoValor[50];
    printf("\nO que voce deseja atualizar?\nDigite: ");
    scanf(" %[^\n]", update);

    if (strcasecmp(update, "nome") == 0 || strcasecmp(update, "cpf") == 0 || strcasecmp(update, "doenca") == 0) {
        char novoValor[50];
        printf("Digite o novo valor para %s: ", update);
        scanf(" %[^\n]", novoValor);

        if (strcasecmp(update, "nome") == 0) {
            strcpy(paciente->nome, novoValor);
        } else if (strcasecmp(update, "cpf") == 0) {
            strcpy(paciente->CPF, novoValor);
        } else if (strcasecmp(update, "doenca") == 0) {
            strcpy(paciente->doenca, novoValor);
        } else {
            printf("Campo inválido.\n");
        }
    } else {
        printf("Campo inválido.\n");
    }

    printf("\n");

    return;
}

int main(){
    Paciente paciente1;
    char update[10];
    int remove;

    cadastrarPaciente(&paciente1);
    printf("Nome do paciente: %s\n", paciente1.nome);
    printf("CPF do paciente: %s\n", paciente1.CPF);
    printf("Doenca do paciente: %s\n", paciente1.doenca);

    atualizarPaciente(&paciente1);

    printf("Nome do paciente: %s\n", paciente1.nome);
    printf("CPF do paciente: %s\n", paciente1.CPF);
    printf("Doenca do paciente: %s\n", paciente1.doenca);

    printf("\nDeseja limpar seus dados?\nDigite 1 para sim, 0 para nao: ");
    scanf("%d", &remove);
    if (remove==1){
        removerPaciente(&paciente1);
        printf("Nome do paciente: %s\n", paciente1.nome);
        printf("CPF do paciente: %s\n", paciente1.CPF);
        printf("Doenca do paciente: %s\n", paciente1.doenca);
    }

    return 0;
}