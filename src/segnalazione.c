/*
 * File: segnalazione.c
 * Autore: [Manuel Sica] 
 * Data: [19/05/2026]
 * Descrizione: Implementazione delle funzioni per la gestione
 * di una singola segnalazione.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../include/segnalazione.h"
#include "../include/data.h"

#define APERTA 1
#define INLAVORAZIONE 2
#define CHIUSA 3

struct c_segnalazione{
    int codice;
    char *cittadino;
    char *categoria;
    char *descrizione;
    data data_segn;
    int urgenza;
    int stato;
};

segnalazione creaSegnalazione(char *cittadino, char *categoria, char *descrizione, data d, int urgenza){
    segnalazione s = malloc(sizeof(struct c_segnalazione));

    if(s == NULL){
        printf("Errore nella segnalazione.");
        return NULL;
    }

    // Creo un codice identificativo univoco che numeri tutte le segnalazioni.
    static int i=0;
    s->codice = i;
    
    s->cittadino = malloc(strlen(cittadino)+1);
    if(s->cittadino == NULL){
        free(s);
        return NULL;
    }
    else{
        strcpy(s->cittadino, cittadino);
    }

    s->categoria = malloc(strlen(categoria)+1);
    if(s->categoria == NULL){
        free(s->cittadino);
        free(s);
        return NULL;
    }
    else{
        strcpy(s->categoria, categoria);
    }

    s->descrizione = malloc(strlen(descrizione)+1);
    if(s->descrizione == NULL){
        // Libero la memoria già allocata prima del fallimento
        // per evitare memory leak. 
        free(s->cittadino);
        free(s->categoria);
        free(s);
        return NULL;
    }
    else{
        strcpy(s->descrizione, descrizione);
    }

    s->data_segn = d;
    s->urgenza = urgenza;
    s->stato = APERTA;

    // Incremento il contatore statico alla fine per garantire che il codice univoco
    // venga aggiornato solo se la creazione della segnalazione è andata a buon fine.
    i++;

    return s;
}

segnalazione aggiornaStato(segnalazione s){
    if(s == NULL){
        printf("Errore nella segnalazione.");
        return NULL;
    }

    if(s->stato == APERTA){
        s->stato = INLAVORAZIONE;
    }
    else if(s->stato == INLAVORAZIONE){
        s->stato = CHIUSA;
    }

    return s;
}

bool eliminaSegnalazione(segnalazione s){
    if(s == NULL){
        printf("Errore nella segnalazione.");
        return false;
    }
    
    free(s->cittadino);
    free(s->categoria);
    free(s->descrizione);

    // Richiamo la funzione definita in data.h per liberare la memoria della data
    eliminaData(s->data_segn);
    free(s);

    return true;
}

void stampaSegnalazione(segnalazione s){
    if(s==NULL){
        printf("Errore nella segnalazione.");
        return;
    }
    
    printf("Codice: %d\n", s->codice);
    printf("Cittadino %s\n", s->cittadino);
    printf("Categoria %s\n", s->categoria);
    printf("Descrizione: %s\n", s->descrizione);
    stampaData(s->data_segn);

    switch(s->urgenza){
        case 1: printf("Urgenza: Bassa\n"); break;
        case 2: printf("Urgenza: Media\n"); break;
        case 3: printf("Urgenza: Alta\n"); break;
        default: printf("Urgenza: Non definita\n"); break;
    }

    switch(s->stato){
        case APERTA: printf("Stato: Aperta\n"); break;
        case INLAVORAZIONE: printf("Stato: In lavorazione\n"); break;
        case CHIUSA: printf("Stato: Chiusa\n"); break;
        default: printf("Stato: Non definito\n"); break;
    }
}


// Funzioni di confronto tra segnalazioni usate dal BST
// per mantenere la proprietà di ordinamento per codice identificativo.
int minore(segnalazione s1, segnalazione s2){
    if(s1==NULL || s2==NULL){
        printf("Errore in una o entrambe le segnalazioni.");
        return -1;
    }

    if(s1->codice < s2->codice){
        return 1;
    }
    else{
        return 0;
    } 
}

int uguale(segnalazione s1, segnalazione s2){
    if(s1==NULL || s2==NULL){
        printf("Errore in una o entrambe le segnalazioni.");
        return -1;
    }

    if(s1->codice == s2->codice)
    {
        return 1;
    }
    else{
        return 0;
    }
}

// Funzioni utili per la gestione delle funzioni in gestione.c
int ricavaUrgenza(segnalazione s){
    if(s==NULL){
        printf("Errore nella segnalazione.");
        return -1;
    }
    
    return s->urgenza;
}

int ricavaCodice(segnalazione s){
    if(s==NULL){
        printf("Errore nella segnalazione.");
        return -1;
    }
    
    return s->codice;
}

int ricavaStato(segnalazione s){
    if(s==NULL){
        printf("Errore nella segnalazione.");
        return -1;
    }

    return s->stato;
}