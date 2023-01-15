#include <stdio.h>
#include <stdlib.h>

#include "funcoes.h"
/*
Simulado de uma loja de livros utilizando a linguagem C.
*/
int main(){

    Lista lista;
    inicializarLista(&lista);
    int opcao, und;
    float price;
    char nome[SIZENAME], gen[SIZEGEN];


    printf("=====================\n"
          "|| BIBLIOTECA EM C ||\n"
          "=====================\n");

    do{

          printf("\nEscolha uma opcao:\n"
            "1 - Cadastrar livro\n"
            "2 - Lista de livros\n"
            "3 - Comprar um livro\n"
            "4 - Remover um livro\n"
            "5 - Editar livro\n"
            "6 - Quantidade cadastrada atualmente\n"
            "7 - Sair\n\n--> ");

          scanf("%d", &opcao);
          getchar();

          //system("clear"); //limpa o console...

          switch (opcao){
            case 1:
                printf("\nDigite o nome do livro:\n--> ");
                fgets(nome, SIZENAME, stdin);

                validaNome(nome);

                printf("Qual genero do livro?\n--> ");
                fgets(gen, SIZEGEN, stdin);

                validaNome(gen);

                if(validaGeneroLivro(gen) == 0)
                    break;

                printf("Quantas unidades deseja cadastrar?\n--> ");
                scanf("%d", &und);

                printf("Digite o preco do livro:\n--> ");
                scanf("%f", &price);

                inserirLivroInicio(&lista, nome, gen, und, price);
            break;

            case 2:
                printf("\n1 - Lista geral de livros\n"
                     "2 - Listar por genero\n"
                     "3 - Listar por preco\n"
                     "4 - Voltar\n\n--> ");
                scanf("%d", &opcao);
                getchar();

                if(opcao < 1 || opcao > 4){
                    printf("\nOpcao invalida mano!!\n");
                    break;
                }else if(opcao == 1){
                    listagemGeralDeLivros(lista);
                }else if(opcao == 2){
                    printf("Diga o genero que deseja buscar:\n--> ");
                    fgets(gen, SIZEGEN, stdin);

                    validaNome(gen);

                    if(validaGeneroLivro(gen) == 0)
                        break;

                    listagemPorGenero(lista, gen);

                }else if(opcao == 3){
                    printf("\n1 - Ordem crescente\n"
                           "2 - Ordem decrescente\n\n--> ");
                    scanf("%d", &opcao);
                    getchar();

                    listarPorPreco(&lista, opcao);

                }
                else if(opcao == 4)
                    break;
            break;

            case 3:
                printf("\nDigite o nome do livro que deseja comprar:\n--> ");
                fgets(nome, SIZENAME, stdin);

                validaNome(nome);

                printf("Digite o preco do livro:\n--> ");
                scanf("%f", &price);

                printf("Digite quantas unidades deseja comprar:\n--> ");
                scanf("%d", &und);

                comprarLivro(&lista, nome, price, und);
            break;

            case 4:
                printf("Qual livro deseja remover?\n--> ");
                fgets(nome, SIZENAME, stdin);

                validaNome(nome);

                removerLivro(&lista, nome);
            break;

            case  5:
                printf("\n1 - Editar nome de um livro\n"
                       "2 - Editar genero de um livro\n"
                       "3 - Editar valor de um livro\n"
                       "4 - Voltar\n\n--> ");
                scanf("%d", &opcao);
                getchar();

                if(opcao == 4)
                    break;
                else if(opcao < 1 || opcao > 4)
                    printf("\nOpcao invalida!!\n");
                else if(opcao == 1){
                    char novoNome[SIZENAME];

                    printf("\nDigite o nome do livro que deseja alterar:\n--> ");
                    fgets(nome, SIZENAME, stdin);

                    validaNome(nome);

                    printf("Digite o novo nome do livro:\n--> ");
                    fgets(novoNome, SIZENAME, stdin);

                    validaNome(novoNome);

                    editarNomeLivro(&lista, nome, novoNome);
                }else if(opcao == 2){
                    char novoGenero[SIZEGEN];

                    printf("\nDigite o nome do livro que deseja alterar o genero:\n--> ");
                    fgets(nome, SIZENAME, stdin);

                    validaNome(nome);

                    printf("Digite o novo genero deste livro:\n--> ");
                    fgets(novoGenero, SIZEGEN, stdin);

                    validaNome(novoGenero);

                    validaGeneroLivro(novoGenero);

                    editarGeneroLivro(&lista, nome, novoGenero);
                }else if(opcao == 3){
                    float novoValor;

                    printf("\nDigite o nome do livro que deseja alterar o preco:\n--> ");
                    fgets(nome, SIZENAME, stdin);

                    validaNome(nome);

                    printf("Digite o novo preco do livro:\n--> ");
                    scanf("%f", &novoValor);

                    editarValorLivro(&lista, nome, novoValor);
                }

            break;

            case 6:
                printf("\nAtualmente ha %d livros cadastrados.\n", lista.tam);
            break;

            case 7:
                printf("\nPrograma encerrado!\n");
                exit(0);
            break;
            default:
                printf("\nOpcao invalida!\n");
          }

    }while(1);


return 0;
}
