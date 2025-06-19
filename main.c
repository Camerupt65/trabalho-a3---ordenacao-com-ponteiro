#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "constantes.h"
#include "lista.h"
#include "bubble_sort.h"
#include "quick_sort.h"

int main() {
	srand(time(NULL));      // gera a semente do gerador de numeros aleatorios que usa como base o numero de segundos que se passaram desde 01/01/1970,
	// garantindo que cada execucao do codigo gere valores diferentes


	Item *original = criarLista();
	preencherLista(&original);

	// copias para teste de ordenacoes
	Item *bubCresc = criarLista();
	Item *bubDecr  = criarLista();
	Item *qkCresc  = criarLista();
	Item *qkDecr   = criarLista();

	copiarLista(original, &bubCresc);
	copiarLista(original, &bubDecr);
	copiarLista(original, &qkCresc);
	copiarLista(original, &qkDecr);



	// lista original
	printf("=== LISTA ORIGINAL ===\n");
	imprimirLista(original);
	printf("\n\n");
	liberarLista(original);


	// ordenacao com bubble sort (crescente)
	bubbleSort(bubCresc, CRESCENTE);
	printf("=== BUBBLE SORT - CRESCENTE ===\n");
	imprimirLista(bubCresc);
	printf("\n\n");
	liberarLista(bubCresc);


	// ordenacao com bubble sort (decrescente)
	bubbleSort(bubDecr, DECRESCENTE);
	printf("=== BUBBLE SORT - DECRESCENTE ===\n");
	imprimirLista(bubDecr);
	printf("\n\n");
	liberarLista(bubDecr);


	// ordenacao com quick sort (crescente)
	quickSort(&qkCresc, CRESCENTE);
	printf("=== QUICK SORT - CRESCENTE ===\n");
	imprimirLista(qkCresc);
	printf("\n\n");
	liberarLista(qkCresc);


	// ordenacao com quick sort (decrescente)
	quickSort(&qkDecr, DECRESCENTE);
	printf("=== QUICK SORT - DECRESCENTE ===\n");
	imprimirLista(qkDecr);
	printf("\n\n");
	liberarLista(qkDecr);





	return 0;
}