/*
 * File: gestione.h
 * Autore: [Manuel Sica] 
 * Data: [29/05/2026]
 * Descrizione: Implementazione di un tipo dato astratto per la gestione 
 * delle segnalazioni.
 */

#include <stdbool.h>
#include "segnalazione.h"
#include "BST.h"
#include "queue.h"

/*
 * Funzione: registraSegnalazione
 * ------------------------------
 * Registra una nuova segnalazione inserendola nell'archivio BST
 * e nella coda corrispondente al livello di urgenza.
 *
 * Parametri:
 *  T:     L'albero binario di ricerca.
 *  alta:  Coda delle segnalazioni ad alta urgenza.
 *  media: Coda delle segnalazioni a media urgenza.
 *  bassa: Coda delle segnalazioni a bassa urgenza.
 *  s:     La segnalazione da registrare.
 *
 * Pre-condizione:
 *  Nessuna.
 *
 * Post-condizione:
 *  La segnalazione viene inserita nel BST e nella coda
 *  corrispondente alla sua urgenza.
 *
 * Ritorna:
 *  Il puntatore alla radice dell'albero aggiornato.
 */
BST registraSegnalazione(BST T, queue alta, queue media, queue bassa, segnalazione s);

/*
 * Funzione: visualizzaTutte
 * -------------------------
 * Visualizza tutte le segnalazioni registrate nell'archivio
 * in ordine crescente di codice identificativo.
 *
 * Parametri:
 *  T: L'albero binario di ricerca (archivio).
 *
 * Pre-condizione:
 *  Nessuna.
 *
 * Post-condizione:
 *  Nessuna modifica all'archivio.
 */
void visualizzaTutte(BST T);

/*
 * Funzione: cercaSegnalazione
 * ---------------------------
 * Ricerca e stampa una segnalazione tramite il suo codice identificativo.
 *
 * Parametri:
 *  T:      L'albero binario di ricerca (archivio).
 *  codice: Il codice identificativo della segnalazione da cercare.
 *
 * Pre-condizione:
 *  Nessuna.
 *
 * Post-condizione:
 *  Nessuna modifica all'archivio.
 */
void cercaSegnalazione(BST T, int codice);

/*
 * Funzione: aggiornaStatoSegnalazione
 * ------------------------------------
 * Aggiorna lo stato di una segnalazione tramite il suo codice identificativo.
 *
 * Parametri:
 *  T:      L'albero binario di ricerca (archivio).
 *  codice: Il codice identificativo della segnalazione da aggiornare.
 *
 * Pre-condizione:
 *  Nessuna.
 *
 * Post-condizione:
 *  Se la segnalazione è presente, il suo stato viene aggiornato
 *  al livello successivo.
 */
void aggiornaStatoSegnalazione(BST T, int codice);


/*
 * Funzione: visualizzaPerStato
 * ----------------------------
 * Visualizza tutte le segnalazioni che corrispondono allo stato richiesto.
 *
 * Parametri:
 *  T:     L'albero binario di ricerca (archivio).
 *  stato: Lo stato da filtrare (1 aperta, 2 in lavorazione, 3 chiusa).
 *
 * Pre-condizione:
 *  Nessuna.
 *
 * Post-condizione:
 *  Nessuna modifica all'archivio.
 */
void visualizzaPerStato(BST T, int stato);

/*
 * Funzione: visualizzaUrgenti
 * ---------------------------
 * Visualizza le segnalazioni più urgenti disponibili.
 * Mostra prima quelle ad alta priorità, se assenti quelle
 * a media priorità, altrimenti quelle a bassa priorità.
 *
 * Parametri:
 *  alta:  Coda delle segnalazioni ad alta urgenza.
 *  media: Coda delle segnalazioni a media urgenza.
 *  bassa: Coda delle segnalazioni a bassa urgenza.
 *
 * Pre-condizione:
 *  Nessuna.
 *
 * Post-condizione:
 *  Nessuna modifica alle code.
 */
void visualizzaUrgenti(queue alta, queue media, queue bassa);

/*
 * Funzione: eliminaSegnalazioneDaArchivio
 * ----------------------------------------
 * Elimina una segnalazione dall'archivio tramite il suo codice identificativo,
 * rimuovendola sia dal BST che dalla coda di priorità.
 *
 * Parametri:
 *  T:      L'albero binario di ricerca.
 *  codice: Il codice identificativo della segnalazione da eliminare.
 *  alta:   Coda delle segnalazioni ad alta urgenza.
 *  media:  Coda delle segnalazioni a media urgenza.
 *  bassa:  Coda delle segnalazioni a bassa urgenza.
 *
 * Pre-condizione:
 *  Nessuna.
 *
 * Post-condizione:
 *  Se la segnalazione è presente, viene rimossa dal BST e dalla coda
 *  corrispondente alla sua urgenza.
 *
 * Ritorna:
 *  Il puntatore alla radice dell'albero aggiornato.
 */
BST eliminaSegnalazioneDaArchivio(BST T, int codice, queue alta, queue media, queue bassa);

/*
 * Funzione: generaReport
 * ----------------------
 * Genera un report con il numero totale di segnalazioni
 * suddivise per stato.
 *
 * Parametri:
 *  T: L'albero binario di ricerca (archivio).
 *
 * Pre-condizione:
 *  Nessuna.
 *
 * Post-condizione:
 *  Nessuna modifica all'archivio.
 */
void generaReport(BST T);