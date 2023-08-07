#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct{
    char nome[50];
    char CPF[12];
    char doenca[50];
} Paciente;

void listarPacientes() {
    FILE *arquivo = fopen("pacientes.txt", "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    Paciente paciente;

    printf("\n NOME         CPF          DOENCA\n\n");

    while (fscanf(arquivo, "%[^;];%[^;];%[^\n]\n", paciente.nome, paciente.CPF, paciente.doenca) == 3) {
        printf("%s | %s | %s\n", paciente.nome, paciente.CPF, paciente.doenca);
    }

    fclose(arquivo);
    return;
}

void cadastrarPaciente(Paciente *paciente) {
    printf("\nPara começar o cadastro, digite seu nome: ");
    scanf(" %[^\n]", paciente->nome);
    
    printf("Digite seu CPF: ");
    scanf(" %[^\n]", paciente->CPF);

    printf("Agora, digite a doença que você deseja tratar: ");
    scanf(" %[^\n]", paciente->doenca);

    FILE *arquivo = fopen("pacientes.txt", "a"); 

    if (arquivo != NULL) {
        fprintf(arquivo, "%s;%s;%s\n", paciente->nome, paciente->CPF, paciente->doenca);

        fclose(arquivo); 
        printf("\nCadastro do paciente realizado com sucesso!\n");
    } else {
        printf("Erro ao abrir o arquivo!\n");
    }

    printf("\n");
}

int encontrarPacientePorCPF(const char *cpf, FILE *arquivo) {
    Paciente paciente;
    int encontrado = 0;

    while (fscanf(arquivo, "%[^;];%[^;];%[^\n]\n", paciente.nome, paciente.CPF, paciente.doenca) == 3) {
        if (strcmp(paciente.CPF, cpf) == 0) {
            encontrado = 1;
            break;
        }
    }

    rewind(arquivo); // Voltar ao início do arquivo para futuras leituras

    return encontrado;
}

void removerPaciente() {
    FILE *arquivo = fopen("pacientes.txt", "r+");
    
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    char cpf[15];
    printf("\nDigite o CPF do paciente que deseja remover: ");
    scanf(" %[^\n]", cpf);

    if (encontrarPacientePorCPF(cpf, arquivo)) {
        FILE *temp = fopen("temp.txt", "w"); // Arquivo temporário para armazenar os pacientes

        if (temp != NULL) {
            Paciente tempPaciente;

            // Copiar todos os pacientes, exceto o que queremos remover, para o arquivo temporário
            while (fscanf(arquivo, "%[^;];%[^;];%[^\n]\n", tempPaciente.nome, tempPaciente.CPF, tempPaciente.doenca) == 3) {
                if (strcmp(tempPaciente.CPF, cpf) != 0) {
                    fprintf(temp, "%s;%s;%s\n", tempPaciente.nome, tempPaciente.CPF, tempPaciente.doenca);
                }
            }

            fclose(temp);
            remove("pacientes.txt");    // Remover o arquivo original
            rename("temp.txt", "pacientes.txt"); // Renomear o arquivo temporário
            printf("Paciente removido com sucesso!\n");
        } else {
            printf("Erro ao criar arquivo temporário!\n");
        }
    } else {
        printf("Paciente não encontrado.\n");
    }

    fclose(arquivo);
}

void atualizarPaciente() {
    // Abre o arquivo em modo de leitura e escrita
    FILE *arquivo = fopen("pacientes.txt", "r+");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    char cpf[15];
    printf("\nDigite o CPF do paciente que deseja atualizar: ");
    scanf(" %[^\n]", cpf);

    if (encontrarPacientePorCPF(cpf, arquivo)) {
        int atualizado = 0;
        Paciente tempPaciente;

        // Criar um arquivo temporário para armazenar os pacientes atualizados
        FILE *temp = fopen("temp.txt", "w");

        if (temp != NULL) {
            // Copiar todos os pacientes, atualizando o desejado, para o arquivo temporário
            while (fscanf(arquivo, "%[^;];%[^;];%[^\n]\n", tempPaciente.nome, tempPaciente.CPF, tempPaciente.doenca) == 3) {
                if (strcmp(tempPaciente.CPF, cpf) == 0) {
                    printf("\nO que você deseja atualizar?\nDigite (Nome, CPF ou doenca): ");
                    char update[50];
                    scanf(" %[^\n]", update);

                    if (strcasecmp(update, "nome") == 0 || strcasecmp(update, "cpf") == 0 || strcasecmp(update, "doenca") == 0) {
                        char novoValor[50];
                        printf("Digite o novo valor para %s: ", update);
                        scanf(" %[^\n]", novoValor);

                        if (strcasecmp(update, "nome") == 0) {
                            strcpy(tempPaciente.nome, novoValor);
                        } else if (strcasecmp(update, "cpf") == 0) {
                            strcpy(tempPaciente.CPF, novoValor);
                        } else if (strcasecmp(update, "doenca") == 0) {
                            strcpy(tempPaciente.doenca, novoValor);
                        }

                        atualizado = 1;
                    } else {
                        printf("Campo inválido.\n");
                    }
                }
                fprintf(temp, "%s;%s;%s\n", tempPaciente.nome, tempPaciente.CPF, tempPaciente.doenca);
            }

            fclose(temp);
            remove("pacientes.txt");    // Remover o arquivo original
            rename("temp.txt", "pacientes.txt"); // Renomear o arquivo temporário
            printf("Paciente atualizado com sucesso!\n");
        } else {
            printf("Erro ao criar arquivo temporário!\n");
        }
    } else {
        printf("Paciente não encontrado.\n");
    }

    fclose(arquivo);
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
                listarPacientes();
                printf("\n\n");
                break;
            case 3:
                system("clear");
                listarPacientes();
                removerPaciente();
                printf("\n\n");
                break;
            case 4:
                system("clear");
                listarPacientes();
                atualizarPaciente();
                printf("\n\n");
                break;
            case 5:
                printf("Encerrando o programa...\n");
                return;
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
    printf("\nPara começar o cadastro, digite seu nome: ");
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
                break;
            case 3:
                system("clear");
                printf("Selecione o medico que deseja remover:\n");
                break;
            case 4:
                system("clear");
                printf("Selecione o medico que deseja alterar os dados:\n");
                break;
            case 5:
                printf("Encerrando o programa...\n");
                return;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }

}

int main() {
    int opcao;

    while (1) {
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
                break;
            case 3:
                system("clear");
                printf("Você selecionou o menu de agendamentos.\n");
                break;
            case 4:
                system("clear");
                printf("Encerrando o programa...\n");
                return 0;
            default:
                system("clear");
                printf("Opção inválida. Tente novamente.\n");
        }
    }

    return 0;
}