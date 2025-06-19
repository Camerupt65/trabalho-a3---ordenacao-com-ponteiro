#ifndef ORDENACAO_H
#define ORDENACAO_H

// ordenacao quicksort
void quickSort(Item **inicio, int crescente);
void particionar(Item *inicio, Item **menores, Item **maiores, int pivo, int crescente);

#endif