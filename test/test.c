/*
 * File: test_segnalazioni.c
 * Autore: [Manuel Sica]
 * Data: [03/06/2026]
 * Descrizione: Test suite bottom-up per la verifica delle funzionalità
 * del sistema di gestione segnalazioni.
 *
 * Gerarchia testata:
 *  1. data
 *  2. segnalazione
 *  3. queue
 *  4. BST
 *  5. gestione
 */

#include <stdio.h>
#include <assert.h>
#include "../include/data.h"
#include "../include/segnalazione.h"
#include "../include/queue.h"
#include "../include/BST.h"
#include "../include/gestione.h"

// 1 - Test ADT "data"
void testAggiungiDataValida(void)
{
    data d = aggiungiData(1, 1, 2026);

    assert(d != NULL);
    eliminaData(d);
    
    printf("testAggiungiDataValida: OK\n");
}

void testAggiungiDataNonValida(void)
{
    // Anno precedente al 2000
    data d1 = aggiungiData(1, 1, 1999);
    assert(d1 == NULL);

    // Mese non valido
    data d2 = aggiungiData(1, 13, 2026);
    assert(d2 == NULL);

    // Giorno non valido
    data d3 = aggiungiData(32, 1, 2026);
    assert(d3 == NULL);

    printf("testAggiungiDataNonValida: OK\n");
}

void testAnnoBisestile(void)
{
    // 2024 è bisestile, il 29 febbraio deve essere valido
    data d1 = aggiungiData(29, 2, 2024);
    assert(d1 != NULL);
    eliminaData(d1);

    // 2023 non è bisestile, il 29 febbraio non deve essere valido
    data d2 = aggiungiData(29, 2, 2023);
    assert(d2 == NULL);

    printf("testAnnoBisestile: OK\n");
}

void testEliminaData(void)
{
    data d = aggiungiData(1, 1, 2026);
    assert(d != NULL);

    // Eliminazione corretta
    assert(eliminaData(d) == true);

    // Eliminazione di una data NULL
    assert(eliminaData(NULL) == false);

    printf("testEliminaData: OK\n");
}

// 2 - Test ADT "segnalazione"
void testCreaSegnalazione(void)
{
    data d = aggiungiData(1, 1, 2026);
    segnalazione s = creaSegnalazione("A", "Illuminazione", "Lampione guasto", d, 2);

    assert(s != NULL);

    // Lo stato iniziale deve essere Aperta (1)
    assert(ricavaStato(s) == 1);

    // L'urgenza deve essere quella inserita
    assert(ricavaUrgenza(s) == 2);

    // Il codice deve essere un intero >= 0
    assert(ricavaCodice(s) >= 0);

    eliminaSegnalazione(s);
    printf("testCreaSegnalazione: OK\n");
}

void testAggiornaStato(void)
{
    data d = aggiungiData(1, 1, 2026);
    segnalazione s = creaSegnalazione("B", "Buche", "Buca", d, 1);

    // Stato iniziale: Aperta (1)
    assert(ricavaStato(s) == 1);

    // Primo aggiornamento: In lavorazione (2)
    aggiornaStato(s);
    assert(ricavaStato(s) == 2);

    // Secondo aggiornamento: Chiusa (3)
    aggiornaStato(s);
    assert(ricavaStato(s) == 3);

    // Terzo aggiornamento: deve rimanere Chiusa (3)
    aggiornaStato(s);
    assert(ricavaStato(s) == 3);

    eliminaSegnalazione(s);
    printf("testAggiornaStato: OK\n");
}

void testEliminaSegnalazione(void)
{
    data d = aggiungiData(1, 1, 2026);
    segnalazione s = creaSegnalazione("C", "Rifiuti", "Rifiuti abbandonati", d, 3);

    assert(eliminaSegnalazione(s) == true);
    assert(eliminaSegnalazione(NULL) == false);

    printf("testEliminaSegnalazione: OK\n");
}

// 3 - Test ADT "queue"
void testNuovaCoda(void)
{
    queue q = nuovaCoda();

    assert(q != NULL);
    assert(codaVuota(q) == 1);

    eliminaCoda(q);
    printf("testNuovaCoda: OK\n");
}

void testAccodaEstrai(void)
{
    queue q = nuovaCoda();

    data d = aggiungiData(1, 1, 2026);
    segnalazione s = creaSegnalazione("D", "Guasto", "Guasto impianto", d, 1);

    // Inserimento
    assert(accodaSegnalazione(s, q) == 1);
    assert(codaVuota(q) == 0);

    // Estrazione
    segnalazione estratta = estraiSegnalazione(q);
    assert(estratta == s);
    assert(codaVuota(q) == 1);

    eliminaSegnalazione(s);
    eliminaCoda(q);
    printf("testAccodaEstrai: OK\n");
}

void testRimuoviDaCoda(void)
{
    queue q = nuovaCoda();

    data d = aggiungiData(1, 1, 2026);
    segnalazione s = creaSegnalazione("E", "Illuminazione", "Palo della luce rotto", d, 2);

    accodaSegnalazione(s, q);

    // Rimozione elemento presente
    assert(rimuoviDaCoda(q, s) == 1);
    assert(codaVuota(q) == 1);

    // Rimozione da coda vuota
    assert(rimuoviDaCoda(q, s) == 0);

    // Rimozione da coda NULL
    assert(rimuoviDaCoda(NULL, s) == -1);

    eliminaSegnalazione(s);
    eliminaCoda(q);
    printf("testRimuoviDaCoda: OK\n");
}

// 4 - Test ADT "BST"
void testInserimentoRicerca(void)
{
    BST archivio = nuovoArchivio();
    assert(archivioVuoto(archivio) == 1);

    data d = aggiungiData(1, 1, 2026);
    segnalazione s = creaSegnalazione("F", "Buche", "Buca profonda", d, 1);

    archivio = inserimento(archivio, s);
    assert(archivioVuoto(archivio) == 0);

    // Ricerca per codice esistente
    int codice = ricavaCodice(s);
    segnalazione trovata = ricercaPerCodice(archivio, codice);
    assert(trovata != NULL);
    assert(ricavaCodice(trovata) == codice);

    // Ricerca per codice non esistente
    assert(ricercaPerCodice(archivio, 9999) == NULL);

    eliminaBST(archivio);
    printf("testInserimentoRicerca: OK\n");
}

void testEliminaNodo(void)
{
    BST archivio = nuovoArchivio();

    data d = aggiungiData(2, 3, 2026);
    segnalazione s = creaSegnalazione("G", "Rifiuti", "Cassonetto pieno", d, 2);

    archivio = inserimento(archivio, s);
    assert(archivioVuoto(archivio) == 0);

    archivio = eliminaNodo(archivio, s);
    assert(archivioVuoto(archivio) == 1);

    printf("testEliminaNodo: OK\n");
}

// 5 - Test modulo "gestione"
void testRegistrazione(void)
{
    BST archivio = nuovoArchivio();
    queue alta   = nuovaCoda();
    queue media  = nuovaCoda();
    queue bassa  = nuovaCoda();

    data d = aggiungiData(1, 1, 2026);
    segnalazione s = creaSegnalazione("H", "Illuminazione", "Lampione guasto", d, 2);

    archivio = registraSegnalazione(archivio, alta, media, bassa, s);

    assert(archivioVuoto(archivio) == 0);
    assert(codaVuota(media) == 0);
    assert(codaVuota(alta) == 1);
    assert(codaVuota(bassa) == 1);

    eliminaCoda(alta);
    eliminaCoda(media);
    eliminaCoda(bassa);
    eliminaBST(archivio);
    printf("testRegistrazione: OK\n");
}

void testEliminazioneCompleta(void)
{
    BST archivio = nuovoArchivio();
    queue alta   = nuovaCoda();
    queue media  = nuovaCoda();
    queue bassa  = nuovaCoda();

    data d = aggiungiData(1, 6, 2026);
    segnalazione s = creaSegnalazione("I", "Guasto", "Guasto impianto", d, 1);
    archivio = registraSegnalazione(archivio, alta, media, bassa, s);

    int codice = ricavaCodice(s);
    archivio = eliminaSegnalazioneDaArchivio(archivio, codice, alta, media, bassa);

    // Dopo l'eliminazione sia il BST che la coda devono essere vuoti
    assert(archivioVuoto(archivio) == 1);
    assert(codaVuota(bassa) == 1);

    eliminaCoda(alta);
    eliminaCoda(media);
    eliminaCoda(bassa);
    printf("testEliminazioneCompleta: OK\n");
}

void testRicercaPerCategoria(void)
{
    BST archivio = nuovoArchivio();
 
    data d1 = aggiungiData(1, 1, 2026);
    segnalazione s1 = creaSegnalazione("L", "Buche", "Buca", d1, 1);
    archivio = inserimento(archivio, s1);
 
    data d2 = aggiungiData(2, 1, 2026);
    segnalazione s2 = creaSegnalazione("M", "Buche", "Buca", d2, 2);
    archivio = inserimento(archivio, s2);
 
    data d3 = aggiungiData(3, 1, 2026);
    segnalazione s3 = creaSegnalazione("N", "Illuminazione", "Lampione guasto", d3, 3);
    archivio = inserimento(archivio, s3);
 
    // Ricerca categoria presente: deve trovare 2 risultati
    assert(ricercaPerCategoriaBST(archivio, "Buche") == 2);
 
    // Ricerca categoria presente con un solo risultato
    assert(ricercaPerCategoriaBST(archivio, "Illuminazione") == 1);
 
    // Ricerca categoria non presente: deve restituire 0
    assert(ricercaPerCategoriaBST(archivio, "Rifiuti") == 0);
 
    eliminaBST(archivio);
    printf("testRicercaPerCategoria: OK\n");
}
 
void testReportCategorie(void)
{
    BST archivio = nuovoArchivio();
 
    data d1 = aggiungiData(1, 2, 2026);
    segnalazione s1 = creaSegnalazione("O", "Rifiuti", "Cassonetto pieno", d1, 1);
    archivio = inserimento(archivio, s1);
 
    data d2 = aggiungiData(2, 2, 2026);
    segnalazione s2 = creaSegnalazione("P", "Rifiuti", "Rifiuti abbandonati", d2, 2);
    archivio = inserimento(archivio, s2);
 
    data d3 = aggiungiData(3, 2, 2026);
    segnalazione s3 = creaSegnalazione("Q", "Buche", "Buca profonda", d3, 3);
    archivio = inserimento(archivio, s3);
 
    // Verifica che il report venga generato senza crash
    // (l'output è su schermo, non verificabile con assert)
    generaReportCategorieBST(archivio);
 
    eliminaBST(archivio);
    printf("testReportCategorie: OK\n");
}

// Main della test suite
int main(void)
{
    printf("Avvio\n");

    printf("\ndata\n");
    testAggiungiDataValida();
    testAggiungiDataNonValida();
    testAnnoBisestile();
    testEliminaData();

    printf("\nsegnalazione\n");
    testCreaSegnalazione();
    testAggiornaStato();
    testEliminaSegnalazione();

    printf("\nqueue\n");
    testNuovaCoda();
    testAccodaEstrai();
    testRimuoviDaCoda();

    printf("\nBST\n");
    testInserimentoRicerca();
    testEliminaNodo();

    printf("\ngestione\n");
    testRegistrazione();
    testEliminazioneCompleta();

    printf("\nRicerca e report per categoria\n");
    testRicercaPerCategoria();
    testReportCategorie();

    printf("\nTutti i test sono stati superati.");

    return 0;
}