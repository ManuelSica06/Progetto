/*
 * File: main.c
 * Autore: [Manuel Sica]
 * Data: [02/06/2026]
 * Descrizione: Gestisce il menu per le operazioni sulle segnalazioni.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/gestione.h"
#include "../include/data.h"
#include "../include/segnalazione.h"

int main(void)
{
    BST archivio = nuovoArchivio();
    queue alta   = nuovaCoda();
    queue media  = nuovaCoda();
    queue bassa  = nuovaCoda();

    int scelta, codice, stato, urgenza;
    int gg, mm, aa;

    char cittadino[100], categoria[100], descrizione[200];
    
    data d;
    segnalazione s;

    do {
        printf("\nInserire una scelta sapendo che:\n");
        printf("1. Registra una nuova segnalazione;\n");
        printf("2. Visualizza tutte le segnalazioni;\n");
        printf("3. Cerca una segnalazione tramite codice;\n");
        printf("4. Aggiorna lo stato di una segnalazione;\n");
        printf("5. Visualizza per stato;\n");
        printf("6. Visualizza segnalazioni urgenti;\n");
        printf("7. Elimina una segnalazione;\n");
        printf("8. Genera report;\n");
        printf("0. Esci.\n");
        printf("Scelta: ");
        scanf("%d", &scelta);

        switch(scelta){
            case 1:
                // %[^\n] utile per leggere gli spazi in una stringa.
                printf("\nNome cittadino: ");
                scanf(" %[^\n]", cittadino);
                printf("Categoria: ");
                scanf(" %[^\n]", categoria);
                printf("Descrizione: ");
                scanf(" %[^\n]", descrizione);
                printf("Data (gg mm aa): ");
                scanf("%d %d %d", &gg, &mm, &aa);
                printf("Urgenza (1=Bassa, 2=Media, 3=Alta): ");
                scanf("%d", &urgenza);

                d = aggiungiData(gg, mm, aa);
                if(d == NULL){
                    printf("\n");
                    break;
                }

                s = creaSegnalazione(cittadino, categoria, descrizione, d, urgenza);
                if(s == NULL){
                    printf("Errore nella creazione della segnalazione.\n");
                    break;
                }

                archivio = registraSegnalazione(archivio, alta, media, bassa, s);
                printf("Segnalazione registrata con successo.\n");
                break;
            case 2:
                printf("\n");
                visualizzaTutte(archivio);
                break;
            case 3:
                printf("\nCodice da cercare: ");
                scanf("%d", &codice);

                cercaSegnalazione(archivio, codice);
                break;
            case 4:
                printf("\nCodice da aggiornare: ");
                scanf("%d", &codice);

                aggiornaStatoSegnalazione(archivio, codice);
                break;
            case 5:
                printf("\nStato (1=Aperta, 2=In lavorazione, 3=Chiusa): ");
                scanf("%d", &stato);

                visualizzaPerStato(archivio, stato);
                break;
            case 6:
                printf("\n");
                visualizzaUrgenti(alta, media, bassa);
                break;
            case 7:
                printf("\nCodice da eliminare: ");
                scanf("%d", &codice);

                archivio = eliminaSegnalazioneDaArchivio(archivio, codice, alta, media, bassa);
                break;
            case 8:
                printf("\n");
                generaReport(archivio);
                break;
            case 0:
                break;
            default:
                printf("Scelta non valida.\n");
                break;
        }
    } while(scelta != 0);

    eliminaCoda(alta);
    eliminaCoda(media);
    eliminaCoda(bassa);
    eliminaBST(archivio);

    return 0;
}