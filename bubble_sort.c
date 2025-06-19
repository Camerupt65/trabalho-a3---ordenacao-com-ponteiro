#include <stdlib.h>
#include "lista.h"
#include "bubble_sort.h"
#include "constantes.h"

// se crescente = 1 entao sera organizado de forma crescente, caso contrario de forma decrescente
void bubbleSort(Item *inicio, int crescente) {
	int houveTroca;         // variavel para verificar se houve troca de elementos na execucao atual
	Item *atual;            // ponteiro para percorrer a lista
	Item *limite = NULL;    // variavel para identificar ate onde precisa realizar a ordenacao

	do {
		houveTroca = 0;     // no comeco de cada execucao, assume que nao houve troca de elementos
		atual = inicio;     // comeca a varredura a partir do inicio da lista

		// percorre a lista ate o final da lista
		while (atual->prox != limite) {
			// verifica se sera necessario trocar os elementos
			// se for crescente, troca se o dado atual e maior que o proximo
			// e se for decrescente, troca se o dado atual e menor que o proximo
			int precisaTrocar = (crescente && atual->dado > atual->prox->dado) ||
			                    (!crescente && atual->dado < atual->prox->dado);

			if (precisaTrocar) {
				trocarDados(atual, atual->prox);    // troca os dados pela funcao presente no lista.c
				houveTroca = 1;                     // indica que houve troca nesta execucao
			}

			atual = atual->prox;    // avanca para a proxima posicao posicao da lista
		}

		limite = atual; // apos cada passada, ultimo elemento a ser posto no final da lista se torna o limite
                        // fazendo com que o loop nao precise passar por onde ja esta organizado de novo

	} while (houveTroca);   // vai continuar executando enquanto houver trocas
}
