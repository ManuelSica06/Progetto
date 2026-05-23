/*
 * File: BST.h
 * Autore: [Manuel Sica]
 * Data: [22/05/2026]
 * Descrizione: Implementazione di un albero binario di ricerca per la gestione
 * dell'archivio delle segnalazioni, utile per la visualizzazione di quest'ultime.
 */

#include <stdbool.h>
#include "segnalazione.h"

// Tipo astratto (opaco) che rappresenta l'albero binario di ricerca.
typedef struct bst_node *BST;

/*
 * Funzione: nuovoArchivio 
 * ----------------
 * Crea un nuovo albero binario di ricerca vuoto.
 * 
 * Parametri:
 *  Nessuno.
 * 
 * Pre-condizione:
 *  Nessuna.
 * 
 * Post-condizione:
 *  Nessuna.
 * 
 * Ritorna:
 *  NULL per indicare un albero binario vuoto.
 */
BST nuovoArchivio(void);

/*
 * Funzione: archivioVuoto
 * -----------------------
 * Verifica se l'albero di ricerca binario è vuoto.
 * 
 * Parametri:
 *  T: L'albero binario di ricerca da controllare.
 * 
 * Pre-condizione:
 *  Nessuna.
 * 
 * Post-condizione:
 *  Nessuna modifica all'albero.
 * 
 * Ritorna:
 *  TRUE: Se l'albero è vuoto (NULL);
 *  FALSE: Se l'albero contiene almeno un nodo.
 */
bool archivioVuoto(BST T);

/*
 * Funzione: ricerca
 * -----------------
 * Ricerca una segnalazione nell'albero mediante il suo codice identificativo.
 * 
 * Parametri:
 *  T: L'albero binario di ricerca in cui effettuare la ricerca;
 *  s: La segnalazione da cercare.
 * 
 * Pre-condizione:
 *  Nessuna.
 * 
 * Post-condizione:
 *  Nessuna modifica all'albero.
 * 
 * Ritorna:
 *  TRUE: Se la segnalazione è presente nell'albero;
 *  FALSE: Se la segnalazione non è presente nell'albero.
 */
bool ricerca(BST T, segnalazione s);

/*
 * Funzione inserimento
 * --------------------
 * Inserisce una nuova segnalazione nell'albero binario di ricerca,
 * mantenendo la proprietà d'ordinamento per codice identificativo.
 * 
 * Parametri:
 *  T:    L'albero binario di ricerca in cui inserire la segnalazione;
 *  elem: La segnalazione da inserire.
 * 
 * Pre-condizione:
 *  Nessuna.
 * 
 * Post-condizione:
 *  L'albero binario di ricerca conterrà un nodo in più con la segnalazione inserita,
 *  mantenendo le prioprietà di ordinamento del BST.  
 */
BST inserimento(BST T, segnalazione elem);

/*
 * Funzione: eliminaNodo
 * ---------------------
 * Elimina una segnalazione dall'albero binario di ricerca,
 * mantenendo la proprietà di ordinamento per codice identificativo.
 *
 * Parametri:
 *  T:   L'albero binario di ricerca da cui eliminare la segnalazione.
 *  key: La segnalazione da eliminare (identificata tramite codice).
 *
 * Pre-condizione:
 *  Nessuna.
 *
 * Post-condizione:
 *  Se la segnalazione è presente, il nodo corrispondente viene rimosso
 *  e la memoria del nodo viene liberata, mantenendo la proprietà del BST.
 *
 * Ritorna:
 *  Il puntatore alla radice dell'albero aggiornato.
 *  NULL se l'albero diventa vuoto dopo l'eliminazione.
 */
BST eliminaNodo(BST T, segnalazione key);

/*
 * Funzione: visitaSimmetrica
 * --------------------------
 * Visita l'albero in ordine simmetrico (sinistra, radice, destra) e
 * stampa tutte le segnalazioni in ordine crescente di codice identificativo.
 *
 * Parametri:
 *  T: L'albero binario di ricerca da visitare.
 *
 * Pre-condizione:
 *  Nessuna.
 *
 * Post-condizione:
 *  Nessuna modifica all'albero.
 */
void visitaSimmetrica(BST T);

/*
 * Funzione: eliminaBST
 * --------------------
 * Elimina l'intero albero binario di ricerca liberando tutta la memoria
 * allocata, incluse le segnalazioni contenute in ogni nodo.
 *
 * Parametri:
 *  T: L'albero binario di ricerca da eliminare.
 *
 * Pre-condizione:
 *  Nessuna.
 *
 * Post-condizione:
 *  Tutta la memoria associata all'albero e alle segnalazioni viene liberata.
 */
void eliminaBST(BST T);