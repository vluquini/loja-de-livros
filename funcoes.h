#ifndef TRABALHO_1_H
#define TRABALHO_1_H

#define SIZENAME 15
#define SIZEGEN 10

#define bool _Bool

typedef struct Livros{
  char nome[SIZENAME];
  char gen[SIZEGEN]; //genero
  //int pages;
  int und; //unidade, quantidade
  float price; //valor
  struct Livros *next;
}livro;

typedef struct{
  int tam;
  struct Livros *start;
}Lista;


void inicializarLista(Lista *lista);

//funcoes para validar as strings dos livros
void validaNome(char nome[]);//utiliza as funcoes abaixo de validacao
void removerEspacoString(char *string);//remove \n no final da string
void padronizaNome(char nome[]);//deixa caracteres minusculos
bool validaGeneroLivro(char gen[]);//valida o nome dos generos

//FUNCOES CRUD
void inserirLivroInicio(Lista *lista, char nome[], char gen[], int und, float price);
bool verificarLista(Lista *lista); //verifica se há elementos na lista
void listagemGeralDeLivros(Lista lista);
void listagemPorGenero(Lista lista, char *gen);
void removerLivro(Lista *lista, char nome[]);
void editarNomeLivro(Lista *lista, char nome[], char novoNome[]);
void editarGeneroLivro(Lista *lista, char nome[], char novoGenero[]);
void editarValorLivro(Lista *lista, char nome[], float novoValor);

void listarPorPreco(Lista *lista, int opcao);
void ordenacaoCrescente(float vet[], int tam);
void ordenacaoDecrescente(float vet[], int tam);

void comprarLivro(Lista *lista, char  nome[],  float valor, int und);
//void listagemPorQtdPages(Lista lista);


#endif  // TRABALHO_1_H
