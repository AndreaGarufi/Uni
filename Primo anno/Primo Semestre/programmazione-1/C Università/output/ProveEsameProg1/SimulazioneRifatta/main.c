#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct parametri{
    char input_fileName[35];
};
typedef struct parametri parametri;

struct dim{
    int N;
    int M;
};
typedef struct dim dim;

parametri decodeParameters(int argc,char **argv);
dim readHeader();
short ***readFile(short ***x,int n,int m);
short *getArray(short ***x,short *y,int n,int m);
short *selectionSort(short *y, int n);
short ***processX(short ***x, short *y, int n,int m);


int main(int argc, char **argv){

    parametri dati = decodeParameters(argc,argv);

    printf("\nParametro passato: %s\n",dati.input_fileName);

    dim dato = readHeader();
    printf("\nN = %d M = %d\n",dato.N,dato.M);

    short ***X = readFile(X,dato.N,dato.M);

    for(int i = 0; i < dato.N;i++){
        for(int j = 0; j < dato.M; j++){
            for(int k = 0; k < 1; k++){
                printf("%hd ",X[i][j][k]);
            }   
        }
        puts("");
    }
    puts("");
    short*Y = getArray(X,Y,dato.N,dato.M);

    Y = selectionSort(Y,dato.N);

    X = processX(X,Y,dato.N,dato.M);

    printf("\n\nStampa X dopo gli elementi posti a NULL con '-'\n");
    for(int i = 0; i < dato.N;i++){
        for(int j = 0; j < dato.M; j++){
            for(int k = 0; k < 1; k++){
                if(X[i][j] == NULL){
                    fprintf(stderr,"- ");
                }else{
                    fprintf(stderr,"%hd ",X[i][j][k]);
                }   
            }   
        }
        puts("");
    }
}

parametri decodeParameters(int argc,char **argv){
    parametri input;

    if(argc != 2){
        fprintf(stderr,"\nErrore nel numero dei parametri\n");
        exit(-1);
    }

    if(strcmp(argv[1],"input.csv") != 0){
        fprintf(stderr,"\nErrore nel parametro 'file'\n");
        exit(-1);
    }

    strcpy(input.input_fileName,argv[1]);

    return input;

}

dim readHeader(){

    FILE *filePtr = NULL;
    dim dimensione;

    if((filePtr = fopen("input.csv","r")) == NULL){
        fprintf(stderr,"\nErrore nell'apertura del file\n");
        exit(-1);
    }

    fscanf(filePtr,"%d,%d",&dimensione.N,&dimensione.M);
    //printf("\nN = %d M = %d\n",dimensione.N,dimensione.M);
    fclose(filePtr);

    return dimensione;
}

short ***readFile(short ***x,int n,int m){

    x = malloc(sizeof(short**)*n);
    for(int i = 0; i < n;i++){
        x[i] = malloc(sizeof(short*)*m);
        for(int j = 0; j < m; j++){
            x[i][j] = malloc(sizeof(short));
        }
    }

    FILE *filePtr = NULL;
    dim dimensione;

    if((filePtr = fopen("input.csv","r")) == NULL){
        fprintf(stderr,"\nErrore nell'apertura del file\n");
        exit(-1);
    }
    int nullo,mullo;
    fscanf(filePtr,"%d,%d",&nullo,&mullo);
        for(int i = 0; i < n;i++){
            for(int j = 0; j < m; j++){
                for(int k = 0; k < 1; k++){
                    fscanf(filePtr,"%hd,",&x[i][j][k]);
                }
            }
        }
    
    

    return x;
}

short *getArray(short ***x,short *y, int n,int m){

    y = malloc(sizeof(short)*n);
    
    for(int i = 0; i < n; i++){
        short massimo = x[i][0][0];
        for(int j = 0; j < m-1;j++){
            if(massimo < *x[i][j + 1]){
                massimo = *x[i][j + 1];
                y[i] = massimo;
            }else{
                y[i] = massimo;
            }
        }
    }
    printf("\nARRAY PRIMA DEL BUBBLE SORT\n");
    for(int i = 0; i < n; i++){
        printf("%hd ",y[i]);
    }

    return y;
}

short *selectionSort(short *y, int n){
    printf("\nARRAY DOPO BUBBLE SORT\n");

    for(int i = 0; i < n;i++){
        for(int j = 0; j < n-1;j++){
            if(y[j] < y[j+1]){
                short temp = y[j];
                y[j] = y[j+1];
                y[j+1] = temp;
            }
        }
    }

    for(int i = 0; i < n; i++){
        printf("%hd ",y[i]);
    }

    return y;
}

short ***processX(short ***x, short *y, int n,int m){
    
    for(int i = 0; i < n;i++){
        for(int j = 0; j < m; j++){
            if(*x[i][j] > ((y[i]/2) + 1)){
                x[i][j] = NULL;
            }
        }
    }
    printf("\n\nStampa X dopo gli elementi posti a NULL\n");
    for(int i = 0; i < n;i++){
        for(int j = 0; j < m; j++){
            for(int k = 0; k < 1; k++){
                if(x[i][j] == NULL){
                    printf("* ");
                }else{
                    printf("%hd ",x[i][j][k]);
                }   
            }   
        }
        puts("");
    }
    return x;
}