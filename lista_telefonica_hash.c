//Estrutura programa Tabela Hash - Professor Lucas.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct contatos{
  char nome[50];
  char numero[15];
};

struct contatos *indice[6100];

void adicionarContato(char nome[50],char numero[15]) {
    int hash = 0;
    for (int i = 0;i<50;i++)
        hash += nome[i];
    struct contatos *novoContato = (struct contatos *)malloc(sizeof(struct contatos));
    strcpy(novoContato->nome,nome);
    strcpy(novoContato->numero,numero);
    
    if (indice[hash] != NULL){
        printf("O nome já esta sendo usado.\nContato não salvo PQP, meu hash é ruim.\n");
        return;
    }

    indice[hash] = novoContato;
  
    printf("Contato adicionado com sucesso.\n");
}

void buscarContato(char nome[50]) {
    int hash = 0;
    for (int i = 0;i<50;i++)
        hash += nome[i];
    if(indice[hash] == NULL){
        printf("Nome não está nos nossos bancos de dados.\n");
        return;
    } else {
        printf("Nome: %s \t Telefone: %s\n",indice[hash]->nome,indice[hash]->numero);
  }     
}

void removerContato(char nome[50]) {
    int hash = 0;
    for (int i = 0;i<50;i++)
        hash += nome[i];
    indice[hash] = NULL;
    printf("Contato removido com success.");
}

void exibirContatos() {
    for (int i=0;i<6100;i++){
        if(indice[i] != NULL)
            printf("Nome: %s \t Telefone: %s\n",indice[i]->nome,indice[i]->numero);
  }
}

int main() {
    int opcao;
    clock_t comeco, fim;
    do {
        char nome[50], numero[15];

        printf("\nEscolha uma opcao:\n");
        printf("1 - Adicionar contato\n");
        printf("2 - Buscar contato por nome\n");
        printf("3 - Remover contato\n");
        printf("4 - Exibir todos os contatos\n");
        printf("0 - Sair\n");
        printf("Digite uma opcao: ");
        
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o primeiro nome do Usuário:");
                scanf("%s",nome);
                printf("Digite o numero do Usuário:");
                scanf("%s", numero);
                comeco = clock();
                adicionarContato(nome,numero);
                fim = clock();
                printf("Demora de %.4f ms",(double)(fim-comeco));
                break;
            case 2:
                printf("Digite o nome que deseja pesquisar:");
                scanf("%s",nome);
                comeco = clock();
                buscarContato(nome);
                fim = clock();
                printf("Demora de %.4f ms",(double)(fim-comeco));
                break;
            case 3:
                printf("Digite o nome do contato a ser removido:");
                scanf("%s",nome);
                removerContato(nome);
                break;
            case 4:
                comeco = clock();
                exibirContatos();
                fim = clock();
                printf("Demora de %.4f ms",(double)(fim-comeco));
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}
