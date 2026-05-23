#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../include/segnalazione.h"
#include "../include/queue.h"

#define NULLITEM NULL

struct coda_node{
     segnalazione value;
     struct coda_node *next;
};

struct c_queue{
     struct coda_node *head,*tail;
     int numel;
};

queue nuovaCoda(void)
{
     struct c_queue *q;
     q = malloc (sizeof(struct c_queue));
     if (q == NULL){
          return NULL;
     }

     q->numel = 0;
     q->head = NULL;
     q->tail = NULL;
     return q;
} 

int codaVuota(queue q)
{
     if (q==NULL){
          return -1;
     }
     
     return q->numel == 0;
}

int accodaSegnalazione(segnalazione s, queue q)
{
     if (q==NULL){
          return -1;
     }

     struct coda_node *nuovo;
     nuovo = malloc (sizeof(struct coda_node));
     if (nuovo == NULL){
          return 0;
     }

     nuovo->value = s;
     nuovo->next= NULL;

     if(q->head==NULL){
          q->head = nuovo;
     }
     else{
          q->tail->next= nuovo;
     }

     q->tail = nuovo;
     (q->numel)++;

     return 1;
}

segnalazione estraiSegnalazione(queue q)
{
     if (q==NULL){
          return NULLITEM;
     }

     if (q->numel == 0){
          return NULLITEM;
     }

     segnalazione result = q->head->value;

     struct coda_node *temp = q->head;

     q->head = q->head->next;

     free(temp);

     if(q->head==NULL){
          q->tail=NULL;
     }

     (q->numel)--;

     return result;
}

bool eliminaCoda(queue q){
     if(q == NULL){
          return false;
     }

     struct coda_node *temp;

     while(q->head != NULL){
          temp = q->head;
          q->head = q->head->next;

          // Libero solo il nodo della coda, non la segnalazione
          // (la memoria della segnalazione è gestita dal BST)
          free(temp);
     }

     free(q);
     
     return true;
}