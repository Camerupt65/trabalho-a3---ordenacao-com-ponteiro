#ifndef LISTA_H
#define LISTA_H

// Estrutura de um item da lista
typedef struct Item {
	int dado;
	struct Item *prox;
} Item;

// Funcoes principais
Item *criarLista();                             // Cria lista vazia
Item *adicionar(Item *lista, int dado);         // Adiciona novo item
void preencherLista(Item **lista);              // Preenche lista com dados
void imprimirLista(Item *lista);                // Mostra primeiros 20 e ultimos 20 itens
void copiarLista(Item *origem, Item **copia);   // Copia lista para outra lista
void liberarLista(Item *lista);                 // Libera memoria da lista
void trocarDados(Item *a, Item *b);             // Troca dados entre dois itens

#endif
