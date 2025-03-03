//durante la simulazione in classe avrei probabilmente preso 18 preciso
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct parametri{
    char input_fileName[35];
};
typedef struct parametri parametri;

struct dim{
    int n;
    int m;
};
typedef struct dim dim;

parametri decodeParameters(int argc, char **argv);
dim readHeader();
short **readFile(short **x,int n,int m);
short *getArray(short *y,short **x,int n);
short *selectionSort(short *y,int n);
short **processX(short **x, short *y,int n,int m);

int main(int argc, char **argv){

    parametri dati = decodeParameters(argc,argv);
    printf("\nparametri presi in input %d\n",argc);
    printf("Nome file: %s\n",dati.input_fileName);

    dim dato = readHeader();

    short **X = readFile(X,dato.n,dato.m);

    short *Y = getArray(Y,X,dato.n);

    Y = selectionSort(Y,dato.n);

    X = processX(X,Y,dato.n,dato.m);
}

parametri decodeParameters(int argc, char **argv){

    parametri input;
    if(argc != 2){
        fprintf(stderr,"\nErrore\n");
        exit(-1);
    }

    if(strcmp(argv[1],"input.csv")!= 0){
        fprintf(stderr,"\nErrore nell'inserimento del nome del file\n");
        exit(-1);
    }
    
    strcpy(input.input_fileName,argv[1]);

    return input;


}

dim readHeader(){

    FILE *filePtr = NULL;

    if((filePtr = fopen("input.csv","r")) == NULL){
        fprintf(stderr,"\nErrore nell'apertura del file\n");
        exit(-1);
    }

    dim dimensione;

    fscanf(filePtr,"%d,%d",&dimensione.n,&dimensione.m);

    printf("\nDimensione matrice X: %d %d\n",dimensione.n,dimensione.m);

    fclose(filePtr);
    return dimensione;
}

short **readFile(short **x,int n,int m){

    FILE *filePtr = NULL;
    dim dimensione;
    if((filePtr = fopen("input.csv","r")) == NULL){
        fprintf(stderr,"\nErrore nell'apertura del file\n");
        exit(-1);
    }

    x = malloc(sizeof(short*)*n);
    for(int i = 0; i < n;i++){
        x[i] = malloc(sizeof(short)*m);
    }
    
    int h = 0,k = 0;
    //fseek(filePtr,9,SEEK_SET);
    fscanf(filePtr,"%d,%d",&h,&k);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            fscanf(filePtr,"%d,",&x[i][j]);
            if(feof(filePtr)){
                break;
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            printf("%d ",x[i][j]);
        }
        puts("");
    }

    return x;

}

short *getArray(short *y,short **x,int n){

    y = malloc(sizeof(short) * n);

    //trovare il massimo in ogni riga di x e inserirlo nel vettore y

    printf("\nArray Y\n");

    //eseguire una parte del punto C

    /*for(int i = 0; i < n; i++){
        for(int j = 0; j < 1; j++){
            int massimo = x[i][j];
            if(x[i][j] > massimo){
                int temp = massimo;
                massimo = x[i][j];
                y[i] = temp;
                printf("\n%d\n",y[i]);
            }
        }
    }*/

   //{59 82 89 29} {34 15 43 92} {17 67 94 56}

    for(int i = 0; i < n; i++){
        y[i] = 25 + rand() %80;
        printf("%d ",y[i]);
    }
    
    return y;
}

short *selectionSort(short *y,int n){ 

    printf("\n\nBUBBLE SORT\n\n");

    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-1; j++){
            if(y[j] < y[j+1]){
                int temp = y[j+1];
                y[j+1] = y[j];
                y[j] = temp;
            }
        }
    }

    for(int i = 0; i < n; i++){
        printf("%d ",y[i]);
    }   
    puts("");
    return y;

}
short **processX(short **x,short *y,int n,int m){

    //eseguire punto D

    x[2] = NULL;    //esempio di riga a NULL

    printf("\nStampa su standard error\n");
    for(int i = 0; i < n; i++){
        if(x[i] == NULL) {
        for (int k = 0; k < m; k++) {
            fprintf(stderr, "-  ");
        }
    }else{
        for(int j = 0; j < m; j++) {
            fprintf(stderr, "%d ", x[i][j]);
        }
    }
    puts("");
    }
}