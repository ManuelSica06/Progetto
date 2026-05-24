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

segnalazione estraiSegnalazione(struct bst_node *N);
void inserisciSegnalazione(struct bst_node *N, segnalazione s);
static BST creaFoglia(segnalazione elem);
static struct bst_node* valoreMinore(struct bst_node* node);

segnalazione estraiSegnalazione(struct bst_node *N)
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
        printf("Errore nel BST.");
        return 0;
    }

    // Richiamo la funzione definita in segnalazione.h per verificare se
    // il codice delle due segnalazioni sia uguale.
    if(uguale(s, estraiSegnalazione(T))==1){
        return 1;
    }

    // Richiamo la funzione definita in segnalazione.h per verificare se
    // il codice della prima segnalazione sia minore o meno.
    if(minore(s, estraiSegnalazione(T))==1){
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
    else if(minore(elem, estraiSegnalazione(T))==1){
        T->left = inserimento(T->left, elem);
    }
    else if(minore(estraiSegnalazione(T), elem)==1){
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
        printf("Errore nel BST.");
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
        printf("Errore nel BST.");
        return;
    }

    visitaSimmetrica(T->left);
    
    segnalazione s = estraiSegnalazione(T);
    
    // Richiamo la funzione definita in segnalazione.h per stampare
    // l'intera segnalazione.
    stampaSegnalazione(s); 
    
    visitaSimmetrica(T->right);
}

void eliminaBST(BST T) {
    if (T == NULL){
        printf("Errore nel BST.");
        return;
    }

    eliminaBST(T->left);
    eliminaBST(T->right);

    eliminaSegnalazione(T->value);
    
    free(T);
}