#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "constantes.h"

// inicializa lista
Item *criarLista() {
	return NULL;
}

// insere elemento na lista
Item *inserirNoInicio(Item *lista, int valor) {
	Item *novo = malloc(sizeof(Item));
	novo->dado = valor;
	novo->prox = lista;
	return novo;
}

// preenche a lista usando a funcao anterior
void preencherLista(Item **lista) {
	for (int i = 0; i < TAMANHO; i++) {
		*lista = inserirNoInicio(*lista, rand() % (LIMITE + 1));
	}
}

// da printf nos primeiros 20 elementos e ultimos elementos da lista
void imprimirLista(Item *lista) {
	Item *atual = lista;
	int i = 0;

	printf("Primeiros 20: ");
	while (atual != NULL && i < 20) {
		printf("%d ", atual->dado);
		atual = atual->prox;
		i++;
	}
	printf("\n");

	// avanca index para o final da lista
	while (atual != NULL && i < TAMANHO - 20) {
		atual = atual->prox;
		i++;
	}

	printf("Ultimos 20: ");
	while (atual != NULL && i < TAMANHO) {
		printf("%d ", atual->dado);
		atual = atual->prox;
		i++;
	}
	printf("\n");
}

// copia a lista para outra lista
void copiarLista(Item *original, Item **copia) {
	Item *novo = NULL, *ultimo = NULL;
	while (original != NULL) {
		novo = malloc(sizeof(Item));
		novo->dado = original->dado;
		novo->prox = NULL;

		if (ultimo != NULL)
			ultimo->prox = novo;
		else
			*copia = novo;

		ultimo = novo;
		original = original->prox;
	}
}

// libera a memoria ocupada pela lista
void liberarLista(Item *lista) {
	Item *temp;
	while (lista != NULL) {
		temp = lista;
		lista = lista->prox;
		free(temp);
	}
}

// troca dois elementos de posicao
void trocarDados(Item *a, Item *b) {
	int temp = a->dado;
	a->dado = b->dado;
	b->dado = temp;
}