/*
 * File: BST.c
 * Autore: [Manuel Sica]
 * Data: [24/05/2026]
 * Descrizione: Implementazione delle funzioni di un albero binario di ricerca 
 * per la gestione dell'archivio delle segnalazioni.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../include/segnalazione.h"
#include "../include/BST.h"

#define NULLITEM NULL

struct bst_node{
    segnalazione value;
    struct bst_node *left;
    struct bst_node *right;
};

/*
 * Funzione: estraiDaNodo
 * ----------------------------
 * Estrae la segnalazione contenuta in un nodo del BST.
 *
 * Parametri:
 *  N: Il nodo da cui estrarre la segnalazione.
 *
 * Pre-condizione:
 *  Nessuna.
 *
 * Post-condizione:
 *  Nessuna modifica al nodo.
 *
 * Ritorna:
 *  La segnalazione contenuta nel nodo.
 *  NULL se il nodo è NULL.
 */
static segnalazione estraiDaNodo(struct bst_node *N);

/*
 * Funzione: inserisciSegnalazione
 * --------------------------------
 * Inserisce una segnalazione in un nodo del BST.
 *
 * Parametri:
 *  N: Il nodo in cui inserire la segnalazione.
 *  s: La segnalazione da inserire.
 *
 * Pre-condizione:
 *  Nessuna.
 *
 * Post-condizione:
 *  Il nodo conterrà la segnalazione specificata.
 *  Se il nodo è NULL non viene eseguita nessuna operazione.
 */
void inserisciSegnalazione(struct bst_node *N, segnalazione s);

/*
 * Funzione: creaFoglia
 * --------------------
 * Crea un nuovo nodo foglia contenente la segnalazione specificata.
 *
 * Parametri:
 *  elem: La segnalazione da inserire nel nuovo nodo.
 *
 * Pre-condizione:
 *  Nessuna.
 *
 * Post-condizione:
 *  Viene creato un nuovo nodo con i figli sinistro e destro a NULL.
 *
 * Ritorna:
 *  Il puntatore al nuovo nodo creato.
 *  NULL se l'allocazione di memoria fallisce.
 */
static BST creaFoglia(segnalazione elem);

/*
 * Funzione: valoreMinore
 * ----------------------
 * Trova il nodo con il valore minore nel sottoalbero specificato,
 * scendendo sempre nel figlio sinistro.
 *
 * Parametri:
 *  node: La radice del sottoalbero in cui cercare il minimo.
 *
 * Pre-condizione:
 *  Il nodo non deve essere NULL.
 *
 * Post-condizione:
 *  Nessuna modifica all'albero.
 *
 * Ritorna:
 *  Il puntatore al nodo con il valore minore.
 */
static struct bst_node* valoreMinore(struct bst_node* node);

/*
 * Funzione: contaReport
 * ---------------------
 * Funzione ausiliaria ricorsiva per generaReport.
 * Visita l'albero e aggiorna i contatori per stato.
 *
 * Parametri:
 *  T:             L'albero binario di ricerca da visitare.
 *  totale:        Contatore del numero totale di segnalazioni.
 *  aperte:        Contatore delle segnalazioni aperte.
 *  inLavorazione: Contatore delle segnalazioni in lavorazione.
 *  chiuse:        Contatore delle segnalazioni chiuse.
 *
 * Pre-condizione:
 *  I puntatori ai contatori non devono essere NULL.
 *
 * Post-condizione:
 *  I contatori vengono aggiornati con i valori corretti.
 *  Nessuna modifica all'albero.
 */
static void contaReport(BST T, int *totale, int *aperte, int *inLavorazione, int *chiuse);

segnalazione estraiDaNodo(struct bst_node *N)
{
    if (N == NULL){
        return NULLITEM;
    }

    return N->value;
}

void inserisciSegnalazione(struct bst_node *N, segnalazione s)
{
    if (N==NULL){
        return;
    }

    N->value = s;
}

BST nuovoArchivio(void)
{
    return NULL;
}
 
bool archivioVuoto(BST T)
{
    return T == NULL;
}

bool ricerca(BST T, segnalazione s)
{
    if(T == NULL){
        return 0;
    }

    // Richiamo la funzione definita in segnalazione.h per verificare se
    // il codice delle due segnalazioni sia uguale.
    if(uguale(s, estraiDaNodo(T))==1){
        return 1;
    }

    // Richiamo la funzione definita in segnalazione.h per verificare se
    // il codice della prima segnalazione sia minore o meno.
    if(minore(s, estraiDaNodo(T))==1){
        return ricerca(T->left, s);
    }
    else{
        return ricerca(T->right, s);
    }
}

BST inserimento(BST T, segnalazione elem)
{
    if(T==NULL){
        return creaFoglia(elem);
    }
    // Se il codice è già presente nel BST, non viene inserito (nessun duplicato).
    else if(minore(elem, estraiDaNodo(T))==1){
        T->left = inserimento(T->left, elem);
    }
    else if(minore(estraiDaNodo(T), elem)==1){
        T->right = inserimento(T->right, elem);
    }

    return T;
}

static BST creaFoglia(segnalazione elem)
{
    struct bst_node *N;
    N = malloc(sizeof(struct bst_node));

    if(N == NULL){
        return NULL;
    }

    inserisciSegnalazione(N, elem);
    N->left = NULL;
    N->right = NULL;
    
    return N;
}

BST eliminaNodo(BST T, segnalazione key)
{
    if(T == NULL){
        return T;
    }
    
    if(minore(key, T->value)==1){
        T->left = eliminaNodo(T->left, key);
    }

    else if(minore(T->value, key)==1){
        T->right = eliminaNodo(T->right, key);
    }
    else
    {
        // Caso 1: il nodo ha solo il figlio destro, lo sostituisce direttamente.
        if(T->left == NULL)
        {
            struct bst_node *temp = T->right;
            free(T);

            return temp;
        }
        // Caso 2: il nodo ha solo il figlio sinistro, lo sostituisce direttamente.
        else if(T->right == NULL)
        {
            struct bst_node *temp = T->left;
            free(T);

            return temp;
        }
        
        // Caso 3: il nodo ha due figli. Trovo il successore (minimo del sottoalbero
        // destro), copio il suo valore nel nodo corrente ed elimino il successore.
        struct bst_node* temp = valoreMinore(T->right);
        T->value = temp->value;
        T->right = eliminaNodo(T->right, temp->value);
    }

    return T;
}

static struct bst_node *valoreMinore(struct bst_node* bst_node)
{
    struct bst_node* current = bst_node;

    // Il minimo di un BST si trova scendendo sempre nel figlio sinistro
    // fino a raggiungere un nodo senza figlio sinistro.
    while(current->left != NULL){
        current = current->left;
    }

    return current;
}

void visitaSimmetrica(BST T) {
    if(T == NULL){
        return;
    }

    visitaSimmetrica(T->left);
    
    segnalazione s = estraiDaNodo(T);
    
    // Richiamo la funzione definita in segnalazione.h per stampare
    // l'intera segnalazione.
    stampaSegnalazione(s); 
    
    visitaSimmetrica(T->right);
}

void eliminaBST(BST T) {
    if (T == NULL){
        return;
    }

    eliminaBST(T->left);
    eliminaBST(T->right);

    eliminaSegnalazione(T->value);
    
    free(T);
}

segnalazione ricercaPerCodice(BST T, int codice){
    if(T == NULL){
        return NULL;
    }

    segnalazione s = estraiDaNodo(T);

    // Richiamo la funzione definita in segnalazione.h per ricavare
    // il codice della segnalazione.
    int codiceAttuale = ricavaCodice(s);

    if(codiceAttuale == codice){
        return s;
    }

    if(codice < codiceAttuale){
        return ricercaPerCodice(T->left, codice);
    }
    else{
        return ricercaPerCodice(T->right, codice);
    }
}

void visualizzaPerStatoBST(BST T, int stato)
{
    if(T == NULL){
        return;
    }

    visualizzaPerStatoBST(T->left, stato);

    segnalazione s = estraiDaNodo(T);
    if(ricavaStato(s) == stato){
        // Richiamo la funzione definita in segnalazione.h per stampare
        // l'intera segnalazione.
        stampaSegnalazione(s);
    }

    visualizzaPerStatoBST(T->right, stato);
}

void generaReportBST(BST T)
{
    if(archivioVuoto(T)){
        printf("Archivio vuoto, nessun report da generare.\n");
        return;
    }

    int totale = 0, aperte = 0, inLavorazione = 0, chiuse = 0;

    // uso una funzione ausiliaria ricorsiva
    contaReport(T, &totale, &aperte, &inLavorazione, &chiuse);

    printf("REPORT:\n");
    printf("Totale segnalazioni: %d\n", totale);
    printf("Aperte: %d\n", aperte);
    printf("In lavorazione: %d\n", inLavorazione);
    printf("Chiuse: %d\n", chiuse);
}

static void contaReport(BST T, int *totale, int *aperte, int *inLavorazione, int *chiuse)
{
    if(T == NULL){
        return;
    }

    contaReport(T->left, totale, aperte, inLavorazione, chiuse);

    segnalazione s = estraiDaNodo(T);
    (*totale)++;

    switch(ricavaStato(s)){
        case 1: (*aperte)++; break;
        case 2: (*inLavorazione)++; break;
        case 3: (*chiuse)++; break;
    }

    contaReport(T->right, totale, aperte, inLavorazione, chiuse);
}