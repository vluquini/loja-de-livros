#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#include "funcoes.h"

//a lista aponta para o primeiro elemento,
//e os elementos apontam para os próximos elementos da estrutura...
void inicializarLista(Lista *lista){

    lista->start = NULL;
    lista->tam = 0;
}


void validaNome(char nome[]){

    removerEspacoString(nome);//remove \n
    padronizaNome(nome);//deixa minusculo

}

//remover \n das strings
void removerEspacoString(char *string){

    for(int i = 0; string[i] != '\0'; i++){
      if(string[i+1] == '\0'){
        string[i] = '\0';
      }
    }

}


void padronizaNome(char nome[]){

    int i = 0;
    while(nome[i] != '\0'){
        nome[i] = tolower(nome[i]);
        i++;
    }

}


bool validaGeneroLivro(char gen[]){

    int i = 0;
    while(gen[i] != '\0'){
        if((gen[i] < 'A' || gen[i] > 'Z') && (gen[i] < 'a' || gen[i] > 'z')){
           printf("\nGenero invalido!! Deve conter apenas letras.\n");
           return false;
        }
        i++;
    }
return true;
}

//inserção de elementos *no inicio*
void inserirLivroInicio(Lista *lista, char nome[], char gen[], int und, float price){

    livro *novo = malloc(sizeof(livro));

    if(novo){ // != null
        strcpy(novo->nome, nome);
        strcpy(novo->gen, gen);
        //novo->pages = pages;//(*novo).pages = pages...
        novo->und = und;
        novo->price = price;

        novo->next = lista->start;
        lista->start = novo;
        lista->tam++;
        printf("\nLivro cadastrado com sucesso!\n");
    }else
      printf("Erro ao alocar memoria!");

}

//verifica se a lista esta vazia ou nao
bool verificarLista(Lista *lista){

    if(lista->start == NULL){
        printf("\nNao ha livros cadastrados!!\n");
        return false;
    }
    else
        return true;
}


void listagemGeralDeLivros(Lista lista){

    livro *livros = lista.start;

    if(verificarLista(&lista) == true){
        printf("=================================================\n"
               "   Nome     ||   Genero   || Unidades || Preco ||\n"
               "=================================================\n");

        while(livros){
            printf("%s\t\t%s\t\t%d\t %.2f\n", livros->nome, livros->gen, livros->und, livros->price);
            printf("=================================================\n");
            livros = livros->next;
        }
    }

}


void listagemPorGenero(Lista lista, char *gen){

   livro *novo = malloc(sizeof(livro));
   novo = lista.start;

   if(verificarLista(&lista) == true){
       printf("\n==============================\n"
              "     Nome     ||   Genero   ||\n"
              "==============================\n");
       while(novo){
           if(strcmp(gen, novo->gen) == 0){
               printf("%s\t\t%s\t\t\n", novo->nome, novo->gen);
               printf("==============================\n");
           }
           novo = novo->next;
       }
   }

}


void removerLivro(Lista *lista, char nome[]){
//a variavel ''cont'' serve para informar quando nao for encontrado o livro
//a ser removido na lista.
    livro *remover = NULL;
    int cont = 2;
    //aqui eu passo a lista, e nao o endereço da lista, pq eu já recebo
    //o endereço desta lista na função
    if(verificarLista(lista) == true){
        cont--;
        if(strcmp(nome, lista->start->nome) == 0){//remove no inicio
            remover = lista->start;
            lista->start = remover->next;
            free(remover);
            lista->tam--;
            cont--;
            printf("\nLivro removido familha!!\n");
        }else{
            livro *aux = lista->start;
            remover = aux->next;
            while(remover != NULL){
                if(strcmp(nome, remover->nome) == 0){
                    aux->next = remover->next;
                    lista->tam--;
                    free(remover);
                    cont--;
                    printf("\nLivro removido familha!!\n");
                }
            remover = remover->next;
            aux = aux->next;
            }
        }
        if(cont == 1)
            printf("\nLivro nao encontrado!!\n");
    }

}

void editarNomeLivro(Lista *lista, char nome[], char novoNome[]){

    livro *novo = lista->start;
    int aux = 2;

    if(verificarLista(lista) == true){

        while(novo != NULL){
            if(strcmp(nome, novo->nome) == 0){
                strcpy(novo->nome, novoNome);
                aux--;
                printf("\nLivro alterado com sucesso!!\n");
                break;
            }
            novo = novo->next;
        }
        if(aux == 2)
            printf("\nNenhum livro com este nome encontrado!!\n");

    }

}


void editarGeneroLivro(Lista *lista, char nome[], char novoGenero[]){

    livro *novo = lista->start;
    int aux = 2;

    if(verificarLista(lista) == true){

        while(novo != NULL){
            if(strcmp(nome, novo->nome) == 0){
                strcpy(novo->gen, novoGenero);
                aux--;
                printf("\nGenero alterado com sucesso!!\n");
                break;
            }
            novo = novo->next;
        }
        if(aux == 2)
            printf("\nNenhum livro com este nome encontrado!!\n");

    }

}


void editarValorLivro(Lista *lista, char nome[], float novoValor){

    livro *novo = lista->start;
    int aux = 2;

    if(verificarLista(lista) == true){

        while(novo != NULL){
            if(strcmp(nome, novo->nome) == 0){
                novo->price = novoValor;
                aux--;
                printf("\nValor alterado com sucesso!!\n");
                break;
            }
            novo = novo->next;
        }
        if(aux == 2)
            printf("\nNenhum livro com este nome encontrado!!\n");

    }

}


void listarPorPreco(Lista *lista, int opcao){

    livro *novo = lista->start;
    int i = 0;
    float precos[lista->tam];

    //armazeno os valores no vetor
    if(verificarLista(lista) == true){

        for(i = 0; novo != NULL; i++){
            precos[i] = novo->price;
            novo = novo->next;
        }

        if(opcao == 1)
            ordenacaoCrescente(precos, lista->tam);
        else
            ordenacaoDecrescente(precos, lista->tam);

        novo = lista->start;//reseto a variavel

        printf("\n======================================\n"
               "   Nome     ||   Genero   ||  Preco  ||"
               "\n======================================\n");

        //printa os elementos da lista se o valor delas
        //for igual no array precos[]
        for(int k = 0; k < lista->tam; k++){
            for( ; novo != NULL; ){
                if(precos[k] == novo->price){
                    printf("%s\t      %s\t     %.2f\n", novo->nome, novo->gen, novo->price);
                    break;
                }else
                    novo = novo->next;
            }
            novo = lista->start;//reseto novamente
        }
    }


}


void ordenacaoCrescente(float vet[], int tamVet){

    int aux = 0;
    //bubble sort em crescente
    for(int i = 0; i < tamVet; i++){
        for(int j = 0; j < (tamVet - i - 1); j++){
            if(vet[j] > vet[j + 1]){
                aux = vet[j];
                vet[j] = vet[j+1];
                vet[j+1] = aux;
            }
        }
    }


}


void ordenacaoDecrescente(float vet[], int tamVet){

    int aux = 0;
    //bubble sort em decrescente
    for(int i = 0; i < tamVet; i++){
        for(int j = 0; j < (tamVet - i - 1); j++){
            if(vet[j] < vet[j + 1]){
                aux = vet[j];
                vet[j] = vet[j+1];
                vet[j+1] = aux;
            }
        }
    }


}


void comprarLivro(Lista *lista, char  nome[],  float valor, int und){

    livro *novo = lista->start;

    while(novo != NULL){
       if(strcmp(nome, novo->nome) == 0){
          if(valor >= novo->price){
              if(und <= novo->und){
                  novo->und -= und;
                  printf("Voce comprou %d unidades deste livro!!\n", und);
              }else
                  printf("Unidades deste livro insuficientes!!\n");
          }else
              printf("Valor insuficiente!!\n");
       }else
            printf("Livro nao encontrado!!\n");

        novo = novo->next;
    }

  }

