#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *filePtr = NULL;
    
    if((filePtr = fopen("clients.txt", "w")) == NULL){
        printf("Impossibile creare il file ");
    }else{
        printf("File creato\n");
    }

    int numero = 0;
    char testo[50] = "";

    printf("Inserisci i dati  (prima int poi il testo)\n");
    scanf("%d%s",&numero,testo);

    while(!feof(stdin)){
        fprintf(filePtr,"%d %s \n",numero,testo);            //legge da tastiera e scrive nel file finche non si preme Ctrl z
        printf("Inserisci i dati  (prima int poi il testo)\n");
        scanf("%d%s",&numero,testo);
    }                                                                         

    fclose(filePtr);

    filePtr = fopen("clients.txt","r");

    while(!feof(filePtr)){
        fscanf(filePtr,"%d %s ",&numero,testo);
        printf("\n%d %s",numero,testo);
    }
    rewind(filePtr); // riporta il puntatore all'inizio del file (byte 0)

    fclose(filePtr);
}