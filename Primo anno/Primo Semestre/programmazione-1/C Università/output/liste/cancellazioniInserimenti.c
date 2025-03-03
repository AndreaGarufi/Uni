/*implementa inserimento in testa, inserimento in mezzo (dentro la funzione inserimentoOrdinato), inserimento ordinato 
cancellazione in testa, cancellazione in mezzo, canzellazione in coda*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

struct lista{
    int numero;
    struct lista *nextPtr;
};
typedef struct lista lista;

lista *inTesta(lista **headPtr,int n,bool flag);
lista *cancInMezzo(lista **headPtr, int dim);
lista *cancInTesta(lista **headPtr);
lista *cancInCoda(lista **headPtr);
lista *inserimentOrdinato(lista **headPtr,bool flag);

int main(){
    srand(time(NULL));

    lista *testaPtr = NULL;
    lista *newPtr = NULL;
    lista dati;

    int operazione = 0;
    int nodi = 0;

    int n = 0;
    bool flag = false;

    printf("\nCreazione random dei nodi...\n");
    int dim = 2 + rand() % 7;

    for(int i = 0; i < dim; i++){

        if(i == 0){
            testaPtr = malloc(sizeof(lista));
            testaPtr->numero = i+1;
        }else if(i == 1){
            newPtr = malloc(sizeof(lista));
            newPtr = testaPtr->nextPtr = malloc(sizeof(lista));
            newPtr->numero = i+1;
        }else{
            newPtr = newPtr->nextPtr = malloc(sizeof(lista));
            newPtr->numero = i+1;
        }
    }
    printf("\n\n\nNodi Creati -> %d\n\n\n",dim);

    newPtr = testaPtr;
    printf("\n-------lista-------\n");
    while(newPtr != NULL){
        printf("\n%d\n",newPtr->numero);
        newPtr = newPtr->nextPtr;
    }
    printf("\n-------lista-------\n");

    do{
        printf("\n1 per inserire in testa\n2 per inserire in mezzo\n3 per l'inserimento ordinato\n4 per la cancellazione in testa\n5 per la cancellazione in mezzo\n6 per la cancellazione in coda\n7 per stampare la lista\n\n");
        scanf("%d",&operazione);
        puts("");

        switch(operazione){
            case 1: inTesta(&testaPtr,n,flag);
            dim++;
            break;
            case 3: inserimentOrdinato(&testaPtr,flag);
            dim++;
            break;
            case 4: cancInTesta(&testaPtr);
            dim--;
            break;
            case 5: cancInMezzo(&testaPtr,dim);
            dim--;
            break;
            case 6: cancInCoda(&testaPtr);
            dim--;
            break;
            case 7:
                printf("\n-------lista------\n");
                newPtr = testaPtr;
                while(newPtr != NULL){
                    printf("\n%d\n",newPtr->numero);
                    newPtr = newPtr->nextPtr;
                }
                printf("\n-------lista-------\n");
            break;

            default: if(operazione != -1){
                printf("\nInserisci il numero giusto\n");
            }
        }

    }while(operazione != -1);

}

lista *inTesta(lista **headPtr,int n,bool flag){            //i secondi 2 parametri servono nel caso in cui inserimento ordinato chiama questa funzione
    puts("\nInserimento in testa\n");   

    lista *newTestaPtr = malloc(sizeof(lista));
    lista *newPtr = NULL;

    newTestaPtr->nextPtr = *headPtr;

    *headPtr = newTestaPtr;
    if(flag == true){               //questo if gestisce il caso in cui venga chiamata inTesta da inserimentOrdinato
        (*headPtr)->numero = n;
        flag = false;
    }else{
        (*headPtr)->numero = 100 + rand() % 110;   //numeri per inserimenti in testa
    }
    

    newPtr = *headPtr;
    printf("\n-------lista-------\n");
    while(newPtr != NULL){
        printf("\n%d\n",newPtr->numero);
        newPtr = newPtr->nextPtr;
    }
    printf("\n-------lista-------\n");
    puts("");

    return *headPtr;
    
}

lista *cancInMezzo(lista **headPtr, int dim){
    puts("\nInserimento in mezzo\n");

    if((*headPtr)->nextPtr == NULL){   //vuol dire che ho un solo nodo
        free(headPtr);
        return 0;
    }

    lista *newPtr = *headPtr;
    lista *lastPtr = NULL;
    int nodo = 1 + (rand() %(dim-1));

    printf("\nSara' cancellato casualmente il nodo numero %d\n",nodo+1);

    int i = 0;
    while(newPtr != NULL){
        if(i == nodo){          //trovato il nodo da cancellare
            break;
        }
        lastPtr = newPtr;
        newPtr = newPtr->nextPtr;
        i++;
    }
    lastPtr->nextPtr = newPtr->nextPtr;    //collegamento al nodo successivo a quello che verra cancellato
    free(newPtr);                           //cancellazione del nodo

    newPtr = *headPtr;
    printf("\n-------lista-------\n");
    while(newPtr != NULL){
        printf("\n%d\n",newPtr->numero);
        newPtr = newPtr->nextPtr;
    }
    printf("\n-------lista-------\n");
    puts("");

    return *headPtr;
}

lista *cancInTesta(lista **headPtr){
    printf("\nCancellazione in testa\n");

    if(*headPtr == NULL){
        printf("\nLista gia vuota\n");
        return 0;
    }
    if((*headPtr)->nextPtr == NULL){        //se ho un solo nodo
        free(*headPtr);
        return 0;
    }

    lista *newTesta = (*headPtr)->nextPtr;
    free(*headPtr);

    *headPtr = newTesta;

    lista *newPtr = newTesta;
    printf("\n-------lista-------\n");
    while(newPtr != NULL){
        printf("\n%d\n",newPtr->numero);
        newPtr = newPtr->nextPtr;
    }
    printf("\n-------lista-------\n");
    puts("");

    return *headPtr;
}

lista *cancInCoda(lista **headPtr){
    printf("\nCancellazione in coda\n");

    if(*headPtr == NULL){
        printf("\nLista vuota\n");
        return NULL;
    }

    if((*headPtr)->nextPtr == NULL){   //ho un solo nodo
        free(*headPtr);
        return NULL;
    }
    lista *newPtr = *headPtr;
    lista *lastPtr = NULL;

    while(newPtr != NULL){
        if(newPtr->nextPtr == NULL){     //mi trovo nell'ultimo nodo
        lastPtr->nextPtr = NULL;
            free(newPtr);
            break;
        }
        lastPtr = newPtr;
        newPtr = newPtr->nextPtr;
    }

    newPtr = *headPtr;
    printf("\n-------lista-------\n");
    while(newPtr != NULL){
        printf("\n%d\n",newPtr->numero);
        newPtr = newPtr->nextPtr;
    }
    printf("\n-------lista-------\n");
    puts("");

    return *headPtr;   

}

lista *inserimentOrdinato(lista **headPtr,bool flag){
    printf("\nInserimento ordinato in base a numero (crescente)\n");

    int numero1 = 0;
    printf("\nInserisci il numero da inserire ordinato\n");
    scanf("%d",&numero1);

    lista *currentPtr = *headPtr;
    lista *lastPtr = NULL;                                       //riferimento al nodo precedente
    

    while(currentPtr != NULL && currentPtr->numero < numero1){  //scorro la lista finché currentPtr è != NULL e 
        lastPtr = currentPtr;                                   //finché il numero del nodo corrente è maggiore del numero da inserire
        currentPtr = currentPtr->nextPtr;
    }

    if(lastPtr == NULL){        //lista vuota oppure la testa è più grande del numero da inserire
        flag = true;                                //questo flag serve a far capire a "inTesta" se inserire un numero a random oppure inserire numero1
        *headPtr = inTesta(headPtr,numero1,flag);
    }else{
        lista *newNodePtr = malloc(sizeof(lista));          //corrisponde ad un inserimento in mezzo
        newNodePtr->numero = numero1;
        newNodePtr->nextPtr = lastPtr->nextPtr;
        lastPtr->nextPtr = newNodePtr;
    }
    printf("\nStampa lista dopo l'inserimento\n");
    
    lista *newPtr = *headPtr;
    printf("\n-------lista-------\n");
    while(newPtr != NULL){
        printf("\n%d\n",newPtr->numero);
        newPtr = newPtr->nextPtr;
    }
    printf("\n-------lista-------\n");
    puts("");

    return *headPtr;

}