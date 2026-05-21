/*
 * File: queue.h
 * Autore: [Manuel Sica]
 * Data: [20/05/2026]
 * Descrizione: Implementazione di un tipo dato astratto per la gestione di una coda (QUEUE).
 * Gestisce una sequenza di elementi basata sulla politica di tipo FIFO (First-In-First-Out).
 */

#include <stdbool.h>
#include "segnalazione.h"

// Tipo astratto (opaco) che rappresenta la coda.
typedef struct c_queue *queue;

/*
 * Funzione: newQueue
 * ------------------
 * Permette di allocare lo spazio necessario per la creazione di una nuova coda.
 * 
 * Parametri:
 *  Nessun parametro.
 * 
 * Pre-condizione:
 *  Nessuna.
 * 
 * Post-condizione:
 *  Restituisce una coda inizializzata con zero elementi (vuota).
 * 
 * Ritorna:
 *  Il puntatore alla nuova coda se l'allocazione ha successo, altrimenti NULL.
 */
queue newQueue(void);

/*
 * Funzione: emptyQueue
 * --------------------
 * Verifica se la coda non ha elementi (vuota).
 * 
 * Parametri:
 *  q: La coda da controllare.
 * 
 * Pre-condizione:
 *  Nessuna precondizione.
 * 
 * Post-condizione:
 *  Nessuna modifica alla coda.
 * 
 * Ritorna:
 * -1: Se la coda non è valida (NULL).
 *  1: Se la coda è vuota.
 *  0: Se la coda contiene almeno un elemento.
 */
int emptyQueue(queue q);

/*
 * Funzione: enqueue
 * -----------------
 * Inserisce un nuovo elemento alla fine della coda.
 * 
 * Parametri:
 *  s: L'elemento di tipo segnalazione da inserire.
 *  q: La coda in cui inserire l'elemento.
 * 
 * Pre-condizione:
 *  Nessuna precondizione.
 * 
 * Post-condizione:
 *  La coda conterrà un elemento in più, l'elemento inserito andrà in ultima posizione.
 * 
 * Ritorna:
 * -1: Se la coda non è valida (NULL).
 *  0: Se l'allocazione di memoria del nuovo nodo fallisce.
 *  1: Se l'inserimento è avvenuto con successo
 */
int enqueue(segnalazione s, queue q);

/*
 * Funzione: dequeue
 * -----------------
 * Rimuove un elemento dalla coda e lo restituisce.
 *
 * Parametri:
 *  q: La coda da cui estrarre l'elemento.
 *
 * Pre-condizione:
 *  La coda "q" non deve essere vuota.
 *
 * Post-condizione:
 *  L'elemento in testa viene rimosso e la memoria del nodo viene liberata.
 *
 * Ritorna:
 *  Se la coda è valida: L'elemento estratto dalla testa della coda. 
 *  Se la coda è vuota o NULL: NULLITEM.
 */
segnalazione dequeue(queue q);

/*
 * Funzione: deleteQueue
 * ---------------------
 * Elimina l'istanza di tipo coda.
 * 
 * Parametri:
 *  q: La coda da eliminare.
 * 
 * Pre-condizione:
 *  Nessuna.
 * 
 * Post-condizione:
 *  Tutta la memoria associata alla coda viene liberata.
 * 
 * Ritorna:
 *  TRUE: Se la memoria è stata liberata correttamente.
 *  FALSE: Se la coda era già NULL.
 */
bool deleteQueue(queue q);