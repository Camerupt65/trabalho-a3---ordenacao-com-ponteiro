#include <stdlib.h>
#include "lista.h"
#include "constantes.h"
#include "quick_sort.h"

//  funcao principal para a ordenacao
// se crescente = 1 entao sera organizado de forma crescente, caso contrario de forma decrescente
void quickSort(Item **inicio, int crescente) {
	// se a lista estiver vazia ou tiver apenas um elemento ela ja esta ordenada entao ela para a funcao
	if (*inicio == NULL || (*inicio)->prox == NULL) return;

	Item *menores = NULL, *maiores = NULL;  // lista de elementos menores e maiores ou iguais ao pivo
	Item *pivo = *inicio;       // deixa o primeiro elemento como pivo
	Item *resto = pivo->prox;   // o resto da lista apos o pivo
	pivo->prox = NULL;          // isolando o pivo temporariamente

	// particiona o resto da lista em menos
	particionar(resto, &menores, &maiores, pivo->dado, crescente);

	// ordena de forma recursiva as sublistas maiores e menores em relacao ao pivo
	quickSort(&menores, crescente);
	quickSort(&maiores, crescente);

	// concatena as listas de menores + pivo + maiores
	Item *fimMenores = menores;
	if (fimMenores != NULL) {
		// se existirem elementos menores, encontra o final da sublista menores
		while (fimMenores->prox != NULL)
			fimMenores = fimMenores->prox;
		fimMenores->prox = pivo; // liga o pivo ao final da sublista menores
	} else {
		// se nao houver menores, o pivo sera o primeiro elemento
		menores = pivo;
	}

	pivo->prox = maiores;   // liga a lista de maiores ao pivo


	*inicio = menores;      // atualiza o inicio da lista para o novo inicio ordenado
}

//  funcao auxiliar para dividir a lista em duas partes, uma antes do pivo e outra depois
void particionar(Item *inicio, Item **menores, Item **maiores, int pivo, int crescente) {
	Item *atual = inicio;   // ponteiro para percorrer a lsita

	// percorre pela lista
	while (atual != NULL) {
		Item *proximo = atual->prox;  // salva o proximo no antes de alterar os ponteiros

		// se for ordenacao crescente: coloca em 'menores' os nos com valor menor que o pivo
		// se for decrescente: coloca em 'menores' os nos com valor maior que o pivo
		if ((crescente && atual->dado < pivo) ||
		        (!crescente && atual->dado > pivo)) {
			atual->prox = *menores;  // insere o no no inicio da lista 'menores'
			*menores = atual;
		} else {
			atual->prox = *maiores;  // caso contrario, insere o no no inicio da lista 'maiores'
			*maiores = atual;
		}

		atual = proximo;  // avanca para o proximo no da lista original
	}
}
