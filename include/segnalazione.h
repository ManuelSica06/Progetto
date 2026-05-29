/*
 * File: segnalazione.h
 * Autore: [Manuel Sica]
 * Data: [19/05/2026]
 * Descrizione: Implementazione di un tipo dato astratto per la gestione 
 * di una singola segnalazione.
 */

#include <stdbool.h>
#include "data.h"

// Tipo astratto (opaco) che rappresenta la segnalazione.
typedef struct c_segnalazione *segnalazione;

/*
 * Funzione: creaSegnalazione
 * --------------------------
 * Crea una nuova segnalazione con un codice identificativo univoco automatico.
 * 
 * Parametri:
 *  cittadino:      Nome e cognome del cittadino.
 *  categoria:      Categoria del problema.
 *  descrizione:    Testo descrittivo del problema.
 *  data:           Oggetto data (tipo ADT data) associato alla segnalazione.
 *  urgenza:        Livello di priorità.
 * 
 * Pre-condizione:
 *  Le stringhe non devono essere NULL e l'oggetto data deve essere valido.
 * 
 * Post-condizione:
 *  Crea un’istanza di segnalazione valida.
 * 
 * Ritorna:
 *  Restituisce una nuova segnalazione inizializzata nello stato iniziale (Aperta: 1)
 */
segnalazione creaSegnalazione(char *cittadino, char *categoria, char *descrizione, data data, int urgenza);

/*
 * Funzione: aggiornaStato
 * -----------------------
 * Aggiorna lo stato di una segnalazione da "Aperta" a "In lavorazione" o da "In lavorazione" a "Chiusa".
 * 
 * Parametri:
 *  s: Segnalazione.
 * 
 * Pre-condizione:
 *  Nessuna pre-condizione specifica.
 * 
 * Post-condizione:
 *  Aggiorna il campo stato all'interno della segnalazione (o in lavorazione o chiuso).
 *  Se lo stato è già "Chiusa", la segnalazione non viene modificata.
 * 
 * Ritorna:
 *  Restituisce la segnalazione allo stato successivo.
 */
segnalazione aggiornaStato(segnalazione s);

/*
 * Funzione: eliminaSegnalazione
 * -----------------------------
 * Elimina l'istanza segnalazione liberando la memoria allocata.
 * 
 * Parametri:
 *  s: Segnalazione.
 * 
 * Pre-condizione:
 *  Nessuna pre-condizione specifica.
 * 
 * Post-condizione:
 *  L’istanza “s” viene eliminata, la memoria precedentemente occupata viene liberata 
 *  e il riferimento non è più utilizzabile.
 * 
 * Ritorna:
 *  TRUE: Se l'istanza della segnalazione è stata eliminata correttamente.
 *  FALSE: Se l'istanza della segnalazione non è stata inizializzata.
 */
bool eliminaSegnalazione(segnalazione s);

/*
 * Funzione: stampaSegnalazione
 * ----------------------------
 * Stampa il contenuto dell'intera segnalazione.
 * 
 * Parametri:
 *  s: La segnalazione da stampare.
 * 
 * Pre-condizione:
 *  Nessuna;
 * 
 * Post-condizione:
 *  Nessuna modifica sulla segnalazione.
 */
void stampaSegnalazione(segnalazione s);

/*
 * Funzione: minore
 * ----------------
 * Confronta il codice di due segnalazioni per determinare qual è il minore.
 * 
 * Parametri:
 *  s1: Prima segnalazione;
 *  s2: Seconda segnalazione.
 * 
 * Pre-condizione:
 *  Nessuna.
 * 
 * Post-condizione:
 *  Nessuna modifica delle segnalazioni.
 * 
 * Ritorna:
 * -1: Se una delle due segnalazioni non è valida (NULL);
 *  1: Se il codice di s1 è minore del codice di s2;
 *  0: Altrimenti.
 */
int minore(segnalazione s1, segnalazione s2);

/*
 * Funzione: uguale
 * ----------------
 * Confronta il codice di due segnalazioni per determinare se sono uguali.
 * 
 * Parametri:
 *  s1: Prima segnalazione;
 *  s2: Seconda segnalazione.
 * 
 * Pre-condizione:
 *  Nessuna.
 * 
 * Post-condizione:
 *  Nessuna modifica delle segnalazioni.
 * 
 * Ritorna:
 * -1: Se una delle due segnalazioni non è valida (NULL);
 *  1: Se il codice di s1 è uguale al codice di s2;
 *  0: Se il codice di s1 è diverso al codice di s2.
 */
int uguale(segnalazione s1, segnalazione s2);

/*
 * Funzione: ricavaUrgenza
 * -----------------------
 * Restituisce il livello di urgenza di una segnalazione.
 *
 * Parametri:
 *  s: La segnalazione da cui ricavare l'urgenza.
 *
 * Pre-condizione:
 *  Nessuna.
 *
 * Post-condizione:
 *  Nessuna modifica alla segnalazione.
 *
 * Ritorna:
 *  Il livello di urgenza della segnalazione (1=Bassa, 2=Media, 3=Alta).
 *  -1 se la segnalazione non è valida (NULL).
 */
int ricavaUrgenza(segnalazione s);

/*
 * Funzione: ricavaCodice
 * ----------------------
 * Restituisce il codice identificativo della segnalazione.
 *
 * Parametri:
 *  s: La segnalazione da cui ricavare il codice.
 *
 * Pre-condizione:
 *  Nessuna.
 *
 * Post-condizione:
 *  Nessuna modifica alla segnalazione.
 *
 * Ritorna:
 *  Il codice identificativo della segnalazione (se valida).
 * -1: Se la segnalazione è NULL.
 */
int ricavaCodice(segnalazione s);

/*
 * Funzione: ricavaStato
 * ---------------------
 * Restituisce lo stato corrente della segnalazione.
 *
 * Parametri:
 *  s: La segnalazione da cui ricavare lo stato.
 *
 * Pre-condizione:
 *  Nessuna.
 *
 * Post-condizione:
 *  Nessuna modifica alla segnalazione.
 *
 * Ritorna:
 *  1: Se la segnalazione è aperta.
 *  2: Se la segnalazione è in lavorazione.
 *  3: Se la segnalazione è chiusa.
 * -1: Se la segnalazione è NULL.
 */
int ricavaStato(segnalazione s);