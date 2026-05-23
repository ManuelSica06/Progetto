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
BST eliminaNodo(BST T, segnalazione key);
void visitaSimmetrica(BST T);
void eliminaBST(BST T);