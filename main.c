#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char* coming_soon =
"A library system that does something. Coming soon!";

int main(int argc, char *argv[]) {
    printf("%s\n", coming_soon);
    return EXIT_SUCCESS;
}

//Andressa
#define MAX_USUARIOS 100
#define TAM_NOME 50
#define TAM_TELEFONE 15

// estrutura para guardar os dados do usuario 
typedef struct {
    int codigo;
    char nome[TAM_NOME];
    char telefone[TAM_TELEFONE];
} Usuario;

Usuario usuarios[MAX_USUARIOS];
int totalUsuarios = 0;

//limpa o buffer antes de usar o fgets
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

//cadastra um novo usuário
void cadastrarUsuario() {
    if (totalUsuarios >= MAX_USUARIOS) {
        printf("Limites máximo de usuários atingido!\n");
        return;
    }

    Usuario novo;
    novo.codigo = totalUsuarios + 1;

    printf("\n--- Cadastro de Usuário ---\n");
    printf("Nome: ");
    limparBuffer();
    fgets(novo.nome, TAM_NOME, stdin);
    novo.nome[strcspn(novo.nome, "\n")] = '\0';

    printf("Telefone: ");
    fgets(novo.telefone, TAM_TELEFONE, stdin);
    novo.telefone[strcspn(novo.telefone, "\n")] = '\0';

    usuarios[totalUsuarios] = novo;
    totalUsuarios++;

    printf("\nUsuário cadastrado com sucesso! Código: %d\n", novo.codigo);
}
