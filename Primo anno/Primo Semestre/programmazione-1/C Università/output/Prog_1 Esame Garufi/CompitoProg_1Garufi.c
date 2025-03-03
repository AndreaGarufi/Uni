
//====================== main.c ======================
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//inserire nomi file persone.txt e output.txt
//gcc .\CompitoProg_1Garufi.c   
//.\a.exe persone.txt output.txt -> per avviarlo correttamemte copia e incolla nel terminale
struct parametri{
    char input_fileName[35];
    char output_filename[35];
};
typedef struct parametri parametri;

struct persona{
    char nome[50];
    char cognome[50];
    int eta;
    float altezza;
};
typedef struct persona persona;

parametri decodeParameters(int argc,char **argv);
int readHeader(int dim);
persona *readFile(persona *array,int dim);
int *extractAges(int *z,persona *array,int dim);
int sortArray(int *z,int dim);
void writeOutput(persona *array,int dim);
float calculateAverageHeight(persona *array,int dim,int mediano);


int main(int argc,char **argv){
    parametri dati = decodeParameters(argc,argv);

    printf("\n%s",dati.input_fileName);
    printf("\n%s\n",dati.output_filename);

    int dimensione = readHeader(dimensione);
    printf("dimensione -> %d \n",dimensione);

    persona *array = readFile(array,dimensione);

    int *Z = extractAges(Z,array,dimensione);

    int mediano = sortArray(Z,dimensione);

    float altezzaM = calculateAverageHeight(array,dimensione,mediano);

    writeOutput(array,dimensione);
}

parametri decodeParameters(int argc,char **argv){
    printf("\nPARAMETRI");

    parametri input;

    if(argc != 3){
        fprintf(stderr,"\nErrore nel numero dei parametri\n");
        exit(-1);
    }

    if(strcmp(argv[1],"persone.txt") != 0){
        fprintf(stderr,"\nErrore nell parametro persone.txt\n");
        exit(-1);
    }

    if(strcmp(argv[2],"output.txt") != 0){
        fprintf(stderr,"\nErrore nell parametro output.txt\n");
        exit(-1);
    }

    strcpy(input.input_fileName,argv[1]);
    strcpy(input.output_filename,argv[2]);
    //printf("\n%s",input.input_fileName);
    //printf("\n%s",input.output_filename);

    return input;
}

int readHeader(int dim){

    FILE *filePtr = NULL;

    if((filePtr = fopen("persone.txt","r")) == NULL){
        fprintf(stderr,"\nErrore nel l'apertura del file\n");
        exit(-1);
    }else{
        printf("\nFile aperto correttamente\n");
    }

    fscanf(filePtr,"%d",&dim);
    fclose(filePtr);

    return dim;
}

persona *readFile(persona *array,int dim){

    FILE *filePtr = NULL;

    persona input;

    if((filePtr = fopen("persone.txt","r")) == NULL){
        fprintf(stderr,"\nErrore nel l'apertura del file\n");
        exit(-1);
    }else{
        printf("\nFile aperto correttamente\n");
    }

    array = malloc(sizeof(persona)*dim);

    int m = 0;
    fscanf(filePtr,"%d",&m);    //scendo di una riga

    for(int i = 0; i < dim; i++){
        fscanf(filePtr,"%s %s %d %f",input.nome,input.cognome,&input.eta,&input.altezza);
        array[i] = input;
    }
    printf("\nStampa delle strutture\n");
    for(int i = 0; i < dim; i++){
        printf("\n%s %s %d %.2f",array[i].nome,array[i].cognome,array[i].eta,array[i].altezza);
    }


    fclose(filePtr);
    return array;
}

int *extractAges(int *z,persona *array,int dim){
    printf("\n\n\ncreazione array z");

    z = malloc(sizeof(int)* dim);

    printf("\nStampa array non ordinato\n");
    for(int i = 0; i < dim; i++){
        z[i] = array[i].eta;
        printf("%d ",z[i]);
    }

    return z;
}

int sortArray(int *z,int dim){

    printf("\nStampa array ordinato\n");
    //BUBBLE SORT
    for(int i = 0; i < dim-1; i++){
        for(int j = 0; j < dim-1; j++){
            if(z[j] > z[j+1]){
                int temp = z[j];
                z[j] = z[j+1];
                z[j+1] = temp; 
            }
        }
    }

    for(int i = 0; i < dim; i++){
        printf("%d ",z[i]);
    }

    int m;
    for(int i = 0; i < (dim /2)+1;i++){
        m = i;
    }
    int mediana = z[m];
    printf("\nmediana ->%d\n",mediana);

    return mediana;
}

float calculateAverageHeight(persona *array,int dim,int mediano){
    printf("\nCalcolo altezza media\n");

    float altezzaMedia = 0;
    float somma = 0;
    for(int i = 0; i < dim;i++){
        if(array[i].eta > mediano){
            somma = somma + array[i].altezza;
        }
    }
    altezzaMedia = somma / (dim/2);
    printf("\nAltezza media sopra la mediana -> %.2f\n",altezzaMedia);

    return altezzaMedia;
}

void writeOutput(persona *array,int dim){

    FILE *filePtr = NULL;

    persona input;

    if((filePtr = fopen("output.txt","w")) == NULL){
        fprintf(stderr,"\nErrore nel l'apertura del file\n");
        exit(-1);
    }else{
        printf("\nFile di output aperto correttamente\n");
    }

    for(int i = (dim/2)+1; i < dim; i++){
        fprintf(filePtr,"%s %s %d %.2f\n",array[i].nome,array[i].cognome,array[i].eta,array[i].altezza);
    }
    
    fclose(filePtr);

}

