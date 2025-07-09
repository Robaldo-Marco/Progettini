#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    GENNAIO = 1,
    FEBBRAIO,
    MARZO,
    APRILE,
    MAGGIO,
    GIUGNO,
    LUGLIO,
    AGOSTO,
    SETTEMBRE,
    OTTOBRE,
    NOVEMBRE,
    DICEMBRE
} Mese;

typedef struct node {
    int anno; // anno della data di nascita
    int data; // giorno della data di nascita
    Mese mese; // mese della data di nascita 
    char nome[20];
    char cognome[20];
    struct node *next; // puntatore al nodo successivo
} Node;

// Prototipi delle funzioni
void ricercaPersona();
void inserimentoPersona();
void stampaLista();
void eliminaPersona();     // ora esiste
void modificaPersona();    // ora esiste

Node *head = NULL; // inizializza la testa della lista a NULL

int main() {
    int choise;
    do {
        printf("\n____MENU PRINCIPALE____\n");
        printf("\nDigita 1 per inserire una persona");
        printf("\nDigita 2 per cercare una persona");
        printf("\nDigita 3 per stampare la lista delle persone");
        printf("\nDigita 4 per eliminare una persona");
        printf("\nDigita 5 per modificare una persona");
        printf("\nDigita 0 per uscire dal programma");

        printf("\n\nInserisci la tua scelta: ");
        scanf("%d", &choise);
        if(choise < 0 || choise > 5){
            printf("Scelta non valida! riprova.\n");
        } else {
            switch(choise){
                case 1:
                    inserimentoPersona();
                    break;
                case 2:
                    ricercaPersona();
                    break;
                case 3:
                    stampaLista();
                    break;
                case 4:
                    eliminaPersona();
                    break;
                case 5:
                    modificaPersona();
                    break;
                case 0:
                    printf("Uscita dal programma...\n");
                    break;
            }
        }
    } while(choise != 0);

    return 0;
}

void inserimentoPersona() {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memoria insufficiente!\n");
        return;
    }

    printf("Inserisci il giorno di nascita: ");
    scanf("%d", &newNode->data);

    printf("Inserisci il mese (1-12): ");
    int meseInput;
    scanf("%d", &meseInput);
    newNode->mese = (Mese)meseInput;

    printf("Inserisci l'anno di nascita: ");
    scanf("%d", &newNode->anno);

    printf("Inserisci il nome: ");
    scanf("%s", newNode->nome);

    printf("Inserisci il cognome: ");
    scanf("%s", newNode->cognome);

    newNode->next = head;
    head = newNode;

    printf("Persona inserita con successo!\n");
}

void ricercaPersona(){
    char nome[20], cognome[20];
    printf("Inserisci il nome da cercare: ");
    scanf("%s", nome);
    printf("Inserisci il cognome da cercare: ");
    scanf("%s", cognome);
    Node *current = head;
    int found = 0;
    while (current != NULL){
        if(strcmp(current->nome, nome) == 0 && strcmp(current->cognome, cognome) == 0){
            printf("Persona trovata: %s %s, Data di nascita: %02d/%02d/%04d\n", 
                   current->nome, current->cognome, current->data, current->mese, current->anno);
            found = 1;
            break;
        }
        current = current->next;
    }

    if (!found)
        printf("Persona non trovata.\n");
}

void stampaLista() {
    Node *current = head;
    if (current == NULL) {
        printf("La lista è vuota.\n");
        return;
    }

    printf("Elenco delle persone:\n");
    while (current != NULL) {
        printf("%s %s, Nato il: %02d/%02d/%04d\n",
               current->nome, current->cognome,
               current->data, current->mese, current->anno);
        current = current->next;
    }
}

void eliminaPersona() {
    char nome[20], cognome[20];
    printf("Inserisci il nome della persona da eliminare: ");
    scanf("%s", nome);
    printf("Inserisci il cognome della persona da eliminare: ");
    scanf("%s", cognome);

    Node *current = head;
    Node *prev = NULL;
    int found = 0;

    while (current != NULL) {
        if (strcmp(current->nome, nome) == 0 && strcmp(current->cognome, cognome) == 0) {
            if (prev == NULL) {
                // La persona da eliminare è in testa
                head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            printf("Persona eliminata con successo.\n");
            found = 1;
            break;
        }
        prev = current;
        current = current->next;
    }

    if (!found) {
        printf("Persona non trovata.\n");
    }
}

void modificaPersona() {
    char nome[20], cognome[20];
    printf("Inserisci il nome della persona da modificare: ");
    scanf("%s", nome);
    printf("Inserisci il cognome della persona da modificare: ");
    scanf("%s", cognome);

    Node *current = head;
    int found = 0;

    // Cerca la persona nella lista
    while (current != NULL) {
        if (strcmp(current->nome, nome) == 0 && strcmp(current->cognome, cognome) == 0) {
            found = 1;
            printf("Persona trovata. Inserisci i nuovi dati:\n");

            printf("Nuovo giorno di nascita: ");
            scanf("%d", &current->data);

            printf("Nuovo mese di nascita (1-12): ");
            int meseInput;
            scanf("%d", &meseInput);
            current->mese = (Mese)meseInput;

            printf("Nuovo anno di nascita: ");
            scanf("%d", &current->anno);

            printf("Nuovo nome: ");
            scanf("%s", current->nome);

            printf("Nuovo cognome: ");
            scanf("%s", current->cognome);

            printf("Dati modificati con successo.\n");
            break;
        }
        current = current->next;
    }

    if (!found) {
        printf("Persona non trovata.\n");
    }
}
