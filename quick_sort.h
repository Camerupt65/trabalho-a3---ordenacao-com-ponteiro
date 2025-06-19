#ifndef QUICK_SORT_H
#define QUICK_SORT_H

// ordenacao quicksort
void quickSort(Item **inicio, int crescente);
void particionar(Item *inicio, Item **menores, Item **maiores, int pivo, int crescente);

#endif
