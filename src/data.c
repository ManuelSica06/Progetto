/*
 * File: data.c
 * Autore: [Manuel Sica] 
 * Data: [19/05/2026]
 * Descrizione: Implementazione delle funzioni per la gestione del tipo dato astratto
 * "Data". Esso permette di gestire solo le date successive all'anno 2000.
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "../include/data.h"

struct c_data{
    int giorno;
    int mese;
    int anno;
};

data aggiungiData(int gg, int mm, int aa){
    if(!verificaData(gg, mm, aa)){
        printf("La data non è valida.");
        return NULL;
    }
    
    data nuovaData = malloc(sizeof(struct c_data));
    if(nuovaData == NULL){
        return NULL;
    }

    nuovaData->giorno = gg;
    nuovaData->mese = mm;
    nuovaData->anno = aa;

    return nuovaData;
}

bool verificaData(int gg, int mm, int aa){
    // Controllo dei limiti base per anno, mesi e giorni negativi.
    if(aa<2000 || (mm <1 || mm>12) || gg<1){
        return false;
    }
    
    int giorniMese[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Verifica dell'anno bisestile secondo il calendario Gregoriano.
    bool bisestile = ((aa %4 == 0) && ((aa %100 != 0) || (aa %400 == 0)));

    if(mm==2 && bisestile){
        // Adattamento per l'anno bisestile.
        giorniMese[1] = 29;
    }

    return gg <= giorniMese[mm-1];
}

bool eliminaData(data d){
    if(d == NULL){
        printf("Errore nella data.");
        return false;
    }

    free(d);
    return true;
}

void stampaData(data d){
    if(d==NULL){
        printf("Errore nella data.");
        return;
    }

    printf("Data: %d/%d/%d\n", d->giorno, d->mese, d->anno);
}