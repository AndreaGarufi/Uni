#include <stdio.h>
#include <stdlib.h>

struct listaNumeri {
    int numero;
    struct listaNumeri *nextPtr;
};
typedef struct listaNumeri listaNumeri;

// Funzione per ordinare la lista con insertion sort
listaNumeri *insertionSort(listaNumeri *head) {
    if (head == NULL || head->nextPtr == NULL) {
        return head; // La lista è vuota o ha un solo elemento
    }

    listaNumeri *sorted = NULL; // Nuova lista ordinata
    listaNumeri *current = head;

    while (current != NULL) {
        listaNumeri *next = current->nextPtr; // Salva il prossimo nodo
        if (sorted == NULL || current->numero < sorted->numero) {
            // Inserimento all'inizio della lista ordinata
            current->nextPtr = sorted;
            sorted = current;
        } else {
            // Cerca la posizione corretta
            listaNumeri *temp = sorted;
            while (temp->nextPtr != NULL && temp->nextPtr->numero < current->numero) {
                temp = temp->nextPtr;
            }
            // Inserisci il nodo nella posizione trovata
            current->nextPtr = temp->nextPtr;
            temp->nextPtr = current;
        }
        current = next; // Passa al prossimo nodo
    }
    return sorted;
}

int main() {
    int dimensione = 0;
    int interi = 0;

    listaNumeri *testaPtr = NULL;
    listaNumeri *newPtr = NULL;

    printf("Quanti numeri vuoi inserire?\n");
    scanf("%d", &dimensione);
    printf("\nInserisci una lista di %d numeri interi\n", dimensione);

    for (int i = 0; i < dimensione; i++) {
        if (i == 0) {
            testaPtr = malloc(sizeof(listaNumeri)); // Creazione primo nodo
        } else if (i == 1) {
            newPtr = testaPtr->nextPtr = malloc(sizeof(listaNumeri)); // Secondo nodo
        } else {
            newPtr = newPtr->nextPtr = malloc(sizeof(listaNumeri)); // Altri nodi
        }

        printf("\nInserisci il %d numero-> ", i + 1);
        scanf("%d", &interi);
        if (i == 0) {
            testaPtr->numero = interi;
            testaPtr->nextPtr = NULL;
        } else {
            newPtr->numero = interi;
            newPtr->nextPtr = NULL;
        }
    }

    printf("\nSTAMPA DELLA LISTA NON ORDINATA...\n");
    newPtr = testaPtr;
    int i = 0;
    while (newPtr != NULL) {
        i++;
        printf("NUMERO NODO %d -> %d\n", i, newPtr->numero);
        newPtr = newPtr->nextPtr;
    }

    printf("\nSTAMPA DELLA LISTA ORDINATA TRAMITE INSERTION SORT...\n");
    testaPtr = insertionSort(testaPtr); // Ordina la lista

    newPtr = testaPtr;
    i = 0;
    while (newPtr != NULL) {
        i++;
        printf("NUMERO NODO %d -> %d\n", i, newPtr->numero);
        newPtr = newPtr->nextPtr;
    }

    return 0;
}
