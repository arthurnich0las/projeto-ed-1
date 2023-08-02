#include <stdio.h>
#include <string.h>
#include <ctype.h>

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
    printf("Para comecar o cadastro, digite seu nome: ");
    scanf(" %[^\n]", medico->nome);
    
    printf("Digite seu CRM: ");
    scanf(" %[^\n]", medico->crm);

    printf("\nAgora, qual a especialidade do medico?");
    listarEspecialidades();
    printf("\nEscolha de acordo: ");
    scanf(" %d", &especialidade);
    if (especialidade == 1){
        strcpy(medico->especialidade, "Aftas");
    } else if (especialidade == 2){
        strcpy(medico->especialidade, "Hipersensibilidade");
    } else if (especialidade == 3){
        strcpy(medico->especialidade, "Lesoes");
    } else if (especialidade == 4){
        strcpy(medico->especialidade, "Pos-cirurgia");
    } else if (especialidade == 5){
        strcpy(medico->especialidade, "Nevralgia");
    } else if (especialidade == 6){
        strcpy(medico->especialidade, "Consulta");
    }

    printf("\n");
    return;
}

int main(){
    int option;
    printf("1 - Cadastrar medico\n2 - Listar medicos\n3 - Atualizar dados de medicos\n4 - Deletar medicos\n");
    printf("\nEscolha a opcao desejada: ");
    scanf("%d", &option);

    Medico medico1;

    if (option == 1){
        int option2;
        printf("Iniciando cadastro do medico...\n\n");
        cadastrarMedico(&medico1);
        dadosMedico(&medico1);
        printf("\nSeus dados estao corretos?\n\n1 - Sim\n2 - Nao\n\nEscolha: ");
        scanf("%d", &option2);
    } else if (option == 2){
        printf("Listando medicos disponiveis...");
    } else if (option == 3){
        printf("Selecione o medico para atualizador dados: ");
    } else if (option == 4){
        printf("Selecione o medico que deseja deletar: ");
    }

}

