/*
 * File: gestione.c
 * Autore: [Manuel Sica] 
 * Data: [29/05/2026]
 * Descrizione: Implementazione delle funzioni per la gestione delle operazioni
 * principali del sistema di segnalazioni. Coordina le interazioni tra il BST
 * e le code di priorità per la registrazione, ricerca, aggiornamento,
 * visualizzazione ed eliminazione delle segnalazioni.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../include/segnalazione.h"
#include "../include/queue.h"
#include "../include/BST.h"
#include "../include/gestione.h"

#define APERTA 1
#define INLAVORAZIONE 2
#define CHIUSA 3

#define URGENZA_BASSA 1
#define URGENZA_MEDIA 2
#define URGENZA_ALTA 3

BST registraSegnalazione(BST T, queue alta, queue media, queue bassa, segnalazione s){
    if(s==NULL){
        printf("Errore della registrazione nel BST.");
        return T;
    }

    // Richiamo la funzione d'inserimento definita in BST.h per inserire
    // la segnalazione nell'archivio.
    T = inserimento(T, s);

    // Richiamo la funzione definita in segnalazione.h per ricavare l'urgenza
    // della segnalazione specifica.
    switch(ricavaUrgenza(s)){
        // Richiamo la funzione definita in queue.h per inserire la
        // segnalazione in una coda in base all'urgenza.
        case URGENZA_BASSA: accodaSegnalazione(s, bassa); break;
        case URGENZA_MEDIA: accodaSegnalazione(s, media); break;
        case URGENZA_ALTA: accodaSegnalazione(s, alta); break;
    }

    return T;
}

void visualizzaTutte(BST T)
{
    if(archivioVuoto(T)){
        printf("Nessuna segnalazione registrata.\n");
        return;
    }

    printf("Tutte le segnalazioni:\n");

    // Richiamo la visita simmetrica definita in BST.h per stampare
    // tutte le segnalazioni in ordine crescente di codice.
    visitaSimmetrica(T);
}

void cercaSegnalazione(BST T, int codice)
{
    if(archivioVuoto(T)){
        printf("Archivio vuoto.\n");
        return;
    }

    // Richiamo la funzione definita in BST.h per cercare
    // la segnalazione tramite codice.
    segnalazione s = ricercaPerCodice(T, codice);

    if(s == NULL){
        printf("Segnalazione con codice %d non trovata.\n", codice);
        return;
    }

    stampaSegnalazione(s);
}

void aggiornaStatoSegnalazione(BST T, int codice)
{
    if(archivioVuoto(T)){
        printf("Archivio vuoto.\n");
        return;
    }

    // Richiamo la funzione definita in BST.h per cercare
    // la segnalazione tramite codice.
    segnalazione s = ricercaPerCodice(T, codice);

    if(s == NULL){
        printf("Segnalazione con codice %d non trovata.\n", codice);
        return;
    }

    // Richiamo la funzione definita in segnalazione.h per
    // aggiornare lo stato della segnalazione trovata.
    if(ricavaStato(s) == 3){
        printf("La segnalazione è già chiusa, non può essere aggiornata.\n");
        return;
    }

    aggiornaStato(s);
    printf("Stato aggiornato con successo.\n");
    stampaSegnalazione(s);
}

void visualizzaPerStato(BST T, int stato)
{
    if(archivioVuoto(T)){
        printf("Archivio vuoto.\n");
        return;
    }

    switch(stato){
        case 1: printf("Segnalazioni aperte:\n"); break;
        case 2: printf("Segnalazioni in lavorazione:\n"); break;
        case 3: printf("Segnalazioni chiuse:\n"); break;
        default:
            printf("Stato non valido.\n");
            return;
    }

    // Richiamo la funzione definita in BST.h per visualizzare
    // le segnalazioni filtrate per stato.
    visualizzaPerStatoBST(T, stato);
}

void visualizzaUrgenti(queue alta, queue media, queue bassa){
    printf("Segnalazioni più urgenti: \n");

    if(codaVuota(alta) == 0){
        printf("Urgenza Alta\n");

        // Richiamo la funzione definita in queue.h
        // per creare una nuova coda.
        queue temp = nuovaCoda();
        while(codaVuota(alta) == 0){

            // Richiamo la funzione definita in queue.h
            // per estrarre un elemento dalla coda.
            segnalazione s = estraiSegnalazione(alta);

            // Richiamo la funzione definita in segnalazione.h
            // per stampare una segnalazione.
            stampaSegnalazione(s);

            // Richiamo la funzione definita in queue.h
            // per accodare la segnalazione.
            accodaSegnalazione(s, temp);
        }

        while(codaVuota(temp) == 0){
            // Richiamo la funzione definita in queue.h
            // per riaccodare la segnalazione.
            accodaSegnalazione(estraiSegnalazione(temp), alta);
        }
        eliminaCoda(temp);
    }
    else if(codaVuota(media) == 0){
        printf("Urgenza Media\n");
        queue temp = nuovaCoda();
        while(codaVuota(media) == 0){
            segnalazione s = estraiSegnalazione(media);
            stampaSegnalazione(s);
            accodaSegnalazione(s, temp);
        }
        while(codaVuota(temp) == 0){
            accodaSegnalazione(estraiSegnalazione(temp), media);
        }
        eliminaCoda(temp);
    }
    else if(codaVuota(bassa) == 0){
        printf("Urgenza Bassa\n");
        queue temp = nuovaCoda();
        while(codaVuota(bassa) == 0){
            segnalazione s = estraiSegnalazione(bassa);
            stampaSegnalazione(s);
            accodaSegnalazione(s, temp);
        }
        while(codaVuota(temp) == 0){
            accodaSegnalazione(estraiSegnalazione(temp), bassa);
        }
        eliminaCoda(temp);
    }
    else{
        printf("Nessuna segnalazione presente.\n");
    }
}

BST eliminaSegnalazioneDaArchivio(BST T, int codice, queue alta, queue media, queue bassa)
{
    if(archivioVuoto(T)){
        printf("Archivio vuoto.\n");
        return T;
    }

    segnalazione s = ricercaPerCodice(T, codice);

    if(s == NULL){
        printf("Segnalazione con codice %d non trovata.\n", codice);
        return T;
    }

    // Rimuovo la segnalazione dalla coda corrispondente
    // prima di eliminarla dal BST.
    switch(ricavaUrgenza(s)){
        case 1: rimuoviDaCoda(bassa, s); break;
        case 2: rimuoviDaCoda(media, s); break;
        case 3: rimuoviDaCoda(alta, s);  break;
    }

    T = eliminaNodo(T, s);
    printf("Segnalazione con codice %d eliminata con successo.\n", codice);

    return T;
}

void generaReport(BST T)
{
    if(archivioVuoto(T)){
        printf("Archivio vuoto, nessun report da generare.\n");
        return;
    }

    // Richiamo la funzione definita in BST.h per generare il report.
    generaReportBST(T);
    generaReportCategorieBST(T);
}

void cercaPerCategoria(BST T, char *categoria){
    if(archivioVuoto(T)){
        printf("Archivio vuoto.\n");
        return;
    }
    else{
        printf("Segnalazioni con categoria %s:\n", categoria);
        if(ricercaPerCategoriaBST(T, categoria) == 0){
            printf("Nessuna segnalazione trovata con categoria %s.\n", categoria);
        }
    }
}