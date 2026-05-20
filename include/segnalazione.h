/*
 * File: segnalazione.h
 * Autore: [Manuel Sica]
 * Data: [19/05/2026]
 * Descrizione: Implementazione di un tipo dato astratto per la gestione 
 * di una singola segnalazione.
 */

#include <stdbool.h>

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
 *  Restituisce una nuova segnalazione inizializzata.
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
 *  Restituisce la segnalazione con il campo stato aggiornato (o in lavorazione o chiuso).
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
 *  Restituisce un valore di verità (TRUE o FALSE).
 * 
 * Ritorna:
 *  TRUE: Se l'istanza della segnalazione è stata eliminata correttamente.
 *  FALSE: Se l'istanza della segnalazione non è stata inizializzata.
 */
bool eliminaSegnalazione(segnalazione s);