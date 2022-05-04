#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "heap.h"

typedef struct nodo{
   void* data;
   int priority;
}heapElem;

typedef struct Heap{
  heapElem* heapArray;
  int size;
  int capac;
} Heap;


void* heap_top(Heap* pq){
   if (pq->size == 0) return NULL;
   return pq->heapArray->data;
}



void heap_push(Heap* pq, void* data, int priority){
   if (pq->capac == pq->size) pq->heapArray = realloc(pq->heapArray, pq->capac *2 +1);
   pq->heapArray[pq->size].data = data;
   pq->heapArray[pq->size].priority = priority;
   pq->size += 1;

   int i = -2;
   while (pq->heapArray[pq->size +i].priority > pq->heapArray[pq->size +i +1].priority){
      heapElem aux1 = pq->heapArray[pq->size +i +1];
      heapElem aux2 = pq->heapArray[pq->size +i ];
      pq->heapArray[pq->size +i] = aux1;
      pq->heapArray[pq->size +i +1] = aux2;
      i--;
   }



}


void heap_pop(Heap* pq){

}

Heap* createHeap(){
   Heap* new = (Heap*) malloc(sizeof(Heap));
   new->heapArray = (heapElem*)malloc(sizeof(heapElem) * 3);
   new->size = 0;
   new->capac = 3;

   return new;
}
