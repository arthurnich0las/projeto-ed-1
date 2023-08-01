#include <stdio.h>

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

int main(){
    Paciente paciente1;

    cadastrarPaciente(&paciente1);
    printf("Nome do paciente: %s\n", paciente1.nome);
    printf("CPF do paciente: %s\n", paciente1.CPF);
    printf("Doenca do paciente: %s\n", paciente1.doenca);

    return 0;
}