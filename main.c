#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char tituloLivro[63];  
    int codigoLivro;  
    char autorLivro[63];   
    int quantidadeLivro;      
} Livro;

typedef struct {
    int codigoUsuario;
    char nomeUsuario[63];
    int telefone;
} Usuario;


Livro *livro = NULL;  //ponteiro de livros no escopo global para todas funcoes terem acesso a ela
Usuario *usuario = NULL; //ponteiro de usuario no escopo global para todas funcoes terem acesso a ela

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
            // evitando problemas de buffer de entrada do teclado
}

void emprestimoLivro(int quantidadeLivros) {
    if (quantidadeLivros == 0) {
        printf("\nNenhum livro cadastrado no sistema.\n");
        return;
    }

    int codigo;
    printf("\nDigite o codigo do livro que deseja pegar emprestado: "); //com o codigo a busca fica mais facil de achar o livro
    scanf("%d", &codigo);
    limparBuffer();

    for (int i = 0; i < quantidadeLivros; i++) {
        if (livro[i].codigoLivro == codigo) {
            if (livro[i].quantidadeLivro > 0) {
                livro[i].quantidadeLivro--;
                printf("Emprestimo realizado com sucesso! Restam %d exemplares.\n", livro[i].quantidadeLivro);
            } else {
                printf("Desculpe, este livro esta esgotado no momento.\n");
            }
            return;
        }
    }
    printf("Livro com o codigo %d nao foi encontrado.\n", codigo);
}
const char* coming_soon =
"A library system that does something. Coming soon!";

int main(int argc, char *argv[]) {
    int quantidadeLivros = 0; //essa variavel guarda quantos livros tem no ponteiro livro
    int quantidadeUsuarios = 0;//essa varaivel guarda quantos livros tem no ponteiro usuario
    printf("%s\n", coming_soon);
    return EXIT_SUCCESS;
}
