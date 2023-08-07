#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

typedef struct{
    char nome[50];
    char CPF[12];
    char doenca[50];
} Paciente;

void cadastrarPaciente(Paciente *paciente){
    printf("Para comecar o cadastro, digite seu nome: ");
    scanf(" %[^\n]", paciente->nome);
    
    printf("Digite seu CPF: ");
    scanf(" %[^\n]", paciente->CPF);

    printf("Agora, digite a doenca que voce deseja tratar: ");
    scanf(" %[^\n]", paciente->doenca);

    printf("\n");
    return;
}

void menuPacientes(){
    int opcao;

    printf("------ MENU PACIENTES ------\n");
    printf("1. Cadastrar paciente\n");
    printf("2. Listar pacientes\n");
    printf("3. Remover pacientes\n");
    printf("4. Atualizar pacientes\n");
    printf("5. Sair\n");
    printf("----------------------------\n");
    printf("Digite a opção desejada: ");

    scanf("%d", &opcao);

    switch (opcao) {
            case 1:
                system("clear");
                printf("Iniciando cadastro de paciente.\n");
                Paciente paciente1;
                cadastrarPaciente(&paciente1);
                break;
            case 2:
                system("clear");
                printf("Listando todos os pacientes...\n");
                // Faça o que deseja para a opção 2
                break;
            case 3:
                system("clear");
                printf("Selecione o paciente que deseja remover:.\n");
                // Faça o que deseja para a opção 3
                break;
            case 4:
                system("clear");
                printf("Selecione o paciente que deseja alterar os dados:\n");
                // Faça o que deseja para a opção 3
                break;
            case 5:
                printf("Encerrando o programa...\n");
                return; // Sai do loop e encerra o programa
            default:
                printf("Opção inválida. Tente novamente.\n");
        }

}

typedef struct{
    char nome[50];
    char crm[20];
    char especialidade[50];
    char procedimentos[70];
} Medico;

void listarEspecialidades(){
    printf("\n1 - Aftas\n2 - Hipersensibilidade\n3 - Lesoes\n4 - Pos-cirurgia\n5 - Nevralgia\n6 - Consulta\n");
    return;
}

void dadosMedico(Medico *medico){
    printf("\nNome do medico: %s\n", medico->nome);
    printf("CRM do medico: %s\n", medico->crm);
    printf("Especialidade do medico: %s\n", medico->especialidade);
}

void cadastrarMedico(Medico *medico){
    int especialidade;
    printf("Para começar o cadastro, digite seu nome: ");
    scanf(" %[^\n]", medico->nome);
    
    printf("Digite seu CRM: ");
    scanf(" %[^\n]", medico->crm);

    printf("\nAgora, qual a especialidade do médico?\n");
    listarEspecialidades();
    printf("\nEscolha de acordo: ");
    scanf(" %d", &especialidade);

    switch (especialidade) {
        case 1:
            strcpy(medico->especialidade, "Aftas");
            break;
        case 2:
            strcpy(medico->especialidade, "Hipersensibilidade");
            break;
        case 3:
            strcpy(medico->especialidade, "Lesões");
            break;
        case 4:
            strcpy(medico->especialidade, "Pós-cirurgia");
            break;
        case 5:
            strcpy(medico->especialidade, "Nevralgia");
            break;
        case 6:
            strcpy(medico->especialidade, "Consulta");
            break;
        default:
            printf("Especialidade inválida!\n");
            return;
    }

    printf("\n");
}

void removerMedico(Medico *medico){

}

void menuMedicos(){
    int opcao;

    system("clear");

    printf("------ MENU MEDICOS ------\n");
    printf("1. Cadastrar medico\n");
    printf("2. Listar medico\n");
    printf("3. Remover medico\n");
    printf("4. Atualizar medico\n");
    printf("5. Sair\n");
    printf("--------------------------\n");
    printf("Digite a opção desejada: ");

    scanf("%d", &opcao);

    switch (opcao) {
            case 1:
                system("clear");
                printf("Iniciando cadastro de medico.\n");
                Paciente paciente1;
                cadastrarPaciente(&paciente1);
                break;
            case 2:
                system("clear");
                printf("Listando todos os medicos...\n");
                // Faça o que deseja para a opção 2
                break;
            case 3:
                system("clear");
                printf("Selecione o medico que deseja remover:\n");
                // Faça o que deseja para a opção 3
                break;
            case 4:
                system("clear");
                printf("Selecione o medico que deseja alterar os dados:\n");
                // Faça o que deseja para a opção 3
                break;
            case 5:
                printf("Encerrando o programa...\n");
                return; // Sai do loop e encerra o programa
            default:
                printf("Opção inválida. Tente novamente.\n");
        }

}

int main() {
    int opcao;

    while (1) {
        system("clear");
        printf("------ MENU ------\n");
        printf("1. Menu Pacientes\n");
        printf("2. Menu Medicos\n");
        printf("3. Menu Agendamentos\n");
        printf("4. Sair\n");
        printf("-------------------\n");
        printf("Digite a opção desejada: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                system("clear");
                printf("Você selecionou o menu de pacientes.\n\n");
                getchar();
                menuPacientes();
                break;
            case 2:
                system("clear");
                printf("Você selecionou o menu de medicos.\n");
                getchar();
                menuMedicos();
                // Faça o que deseja para a opção 2
                break;
            case 3:
                system("clear");
                printf("Você selecionou o menu de agendamentos.\n");
                // Faça o que deseja para a opção 3
                break;
            case 4:
                system("clear");
                printf("Encerrando o programa...\n");
                return 0; // Sai do loop e encerra o programa
            default:
                system("clear");
                printf("Opção inválida. Tente novamente.\n");
        }
    }

    return 0;
}