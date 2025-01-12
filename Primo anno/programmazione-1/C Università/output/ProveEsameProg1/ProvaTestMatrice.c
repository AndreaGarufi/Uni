#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct parametri{
    int k;
    char w;
    int N;
    int M;
};
typedef struct parametri parametri;

parametri readInput(int argc,char **argv);

char ***allocateS(char ***s,int k, int N, int M);

char *genString(char string[],int k,int N,int M);

char ***fillS(char ***s,int k,int N,int M);

int main(int argc,char **argv){

    parametri input = readInput(argc,argv);

    printf("\nParametri: \nK = %d\nW = %c \nN = %d\nM = %d\n",input.k,input.w,input.N,input.M);

    char ***S = allocateS(S,input.k,input.N,input.M);

    S = fillS(S,input.k,input.N,input.M);


}  

parametri readInput(int argc,char **argv){


    parametri variabile;

    printf("\nparametri passati -> %d\n",argc);

    if(argc != 5){
        fprintf(stderr,"errore -1");
        exit(-1);
    }

    if(atoi(argv[1]) < 10 || atoi(argv[1]) > 15 || strlen(argv[2]) != 1 || atoi(argv[3]) < 4 || atoi(argv[3]) > 8 || atoi(argv[4]) < 4 || atoi(argv[4]) > 8){
        fprintf(stderr,"errore -1");
        exit(-1);
    }

    int k = atoi(argv[1]);
    char w = argv[2][0];
    int N = atoi(argv[3]);
    int M = atoi(argv[4]);

    variabile.k = k;
    variabile.w = w;
    variabile.N = N;
    variabile.M = M;

    return variabile;

}

char ***allocateS(char ***s,int k, int N, int M){

    printf("\nAllocazione matrice 3D\n");

    s = malloc(sizeof(char **)* M);
    for(int i = 0; i < M; i++){
        s[i] = malloc(sizeof(char *)* N);

        for(int j = 0; j < N;j++){
            s[i][j] = malloc(sizeof(char)*k);
        }
    }

    /*for(int i = 0; i < M; i++){
        for(int j = 0; j < N;j++){
            for(int h = 0; h < k;h++){
                s[i][j][h] = 'c';
                printf("%c ",s[i][j][h]);
            }
        }
    }*/

   return s;


}

char *genString(char string[],int k,int N,int M){

    //printf("\nGenerazione stringhe\n");

    for(int i = 0; i < k; i++){
        string[i] = 'a' + rand() % 26;
    }
    string[k] = '\0';
    return string;
}

char ***fillS(char ***s,int k,int N,int M){

        char string[k];

        for(int i = 0; i < M; i++){
        for(int j = 0; j < N;j++){
            for(int h = 0; h < k;h++){
                s[i][j] = genString(string,k,N,M);
                //printf("%s ",s[i][j]);
            }
        }
    }
}

//fare punto D