#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "heap.h"

typedef struct nodo
{
   void *data;
   int priority;
} heapElem;

typedef struct Heap
{
   heapElem *heapArray;
   int size;
   int capac;
} Heap;

void *heap_top(Heap *pq)
{
   if (pq->size == 0)
      return NULL;
   return pq->heapArray->data;
}

void heap_push(Heap *pq, void *data, int priority)
{
   printf("capacidad : %d\n", pq->capac);
   printf("size : %d\n", pq->size);
   if (pq->capac == pq->size)
      pq->heapArray = realloc(pq->heapArray, pq->capac * 2 + 1);
   pq->heapArray[pq->size].data = data;
   pq->heapArray[pq->size].priority = priority;
   pq->size += 1;

   int pos_np = (pq->size - 2) / 2;
   int pos_nh = pq->size - 1;
   while (pq->heapArray[pos_np].priority < pq->heapArray[pos_nh].priority)
   {
      heapElem aux1 = pq->heapArray[pos_np]; // padre
      heapElem aux2 = pq->heapArray[pos_nh]; // hijo
      pq->heapArray[pos_np] = aux2;          // intercanbio
      pq->heapArray[pos_nh] = aux1;

      pos_nh = pos_np;
      if (pos_nh <= 0)
         break;
      pos_np = (pos_nh - 1) / 2;
   }
}

void heap_pop(Heap *pq)
{
}

Heap *createHeap()
{
   Heap *new = (Heap *)malloc(sizeof(Heap));
   new->heapArray = (heapElem *)malloc(sizeof(heapElem) * 3);
   new->size = 0;
   new->capac = 3;

   return new;
}
