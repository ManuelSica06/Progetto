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
        return NULL;
    }

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

    i++;

    return s;
}

segnalazione aggiornaStato(segnalazione s){
    if(s == NULL){
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
        return false;
    }
    
    free(s->cittadino);
    free(s->categoria);
    free(s->descrizione);

    free(s);

    return true;
}