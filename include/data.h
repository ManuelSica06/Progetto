/*
 * File: data.h
 * Autore: [Manuel Sica]
 * Data: [19/05/2026]
 * Descrizione: Implementazione di un tipo dato astratto per la gestione 
 * di date successive all'anno 2000.
 */

#include <stdbool.h>

// Tipo astratto (opaco) che rappresenta la data.
typedef struct c_data *data;

/*
 * Funzione: aggiungiData
 * ----------------------
 * Crea una nuova istanza del tipo "Data".
 * 
 * Parametri:
 *  gg: Giorno del mese.
 *  mm: Mese dell'anno (1-12).
 *  aa: Anno.
 * 
 * Pre-condizione:
 *  L'anno deve essere maggiore o uguale al 2000.
 * 
 * Post-condizione:
 *  Restituisce una data valida composta da giorno, mese ed anno.
 * 
 * Ritorna:
 *  Se i dati inseriti sono validi restituisce la data, altrimenti restituisce NULL.
 */
data aggiungiData(int gg, int mm, int aa);

/*
 * Funzione: verificaData
 * ----------------------
 * Verifica che la data inserita sia valida.
 * 
 * Parametri:
 *  gg: Giorno del mese.
 *  mm: Mese dell'anno (1-12).
 *  aa: Anno.
 * 
 * Pre-condizione:
 *   L'anno deve essere maggiore o uguale al 2000.
 * 
 * Post-condizione:
 *  Restituisce un valore di verità (TRUE o FALSE).
 * 
 * Ritorna:
 *  TRUE: Se la data è valida.
 *  FALSE: Se la data non è valida.
 */
bool verificaData(int gg, int mm, int aa);

/*
 * Funzione: eliminaData
 * ---------------------
 * Elimina l'istanza del tipo "Data".
 * 
 * Parametri:
 *  d: Tipo "Data".
 * 
 * Pre-condizione:
 *  Nessuna pre-condizione specifica (Accetta qualsiasi tipo di data).
 * 
 * Post-condizione:
 *  Restituisce un valore di verità (TRUE o FALSE).
 * 
 * Ritorna:
 *  TRUE: Se la data è stata eliminata con successo.
 *  FALSE: Se la data non è stata eliminata.
 */
bool eliminaData(data d);

/*
 * Funzione: stampaData
 * --------------------
 * Stampa l'intera data su singola riga.
 * 
 * Parametri:
 *  d: Tipo "Data".
 * 
 * Pre-condizione:
 *  Nessuna pre-condizione specifica (Accetta qualsiasi tipo di data).
 * 
 * Post-condizione:
 *  Nessuna post-condizione.
 */
void stampaData(data d);