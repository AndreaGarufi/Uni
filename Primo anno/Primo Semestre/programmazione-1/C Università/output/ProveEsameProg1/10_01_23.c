#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct parametri{
    size_t n;
    char c;
    char s1[255];
    char s2[255];
};
typedef struct parametri parametri;

parametri readInput();
char *replaceChar(char s1[], char s2[], char c);
char *invertString(char s2[], size_t n);
char *sort(char s3[], char s4[], size_t n);
void printResult(char s5[],size_t n);

int main(){

    parametri dati = readInput();

    char *s3 = replaceChar(dati.s1,dati.s2,dati.c);
    printf("\nLa stringa s3 e' %s\n",s3);

    char *s4 = invertString(dati.s2,dati.n);

    char *s5 = sort(s3,s4,dati.n);
    printResult(s5,dati.n);
}

parametri readInput(){

    parametri input;

    printf("\nInserisci un intero < 256, una stringa s1, una s2 e un carattera c, (s1,s2 lunghezza n)\n");
    puts("\ninserisci n\n");
    scanf("%zu",&input.n);

    puts("\ninserisci s1\n");
    scanf("%s",&input.s1);

    puts("\ninserisci s2\n");
    scanf("%s",&input.s2);

    puts("\ninserisci c\n");
    scanf(" %c",&input.c);

    
    if(strlen(input.s1) != input.n){
        fprintf(stderr,"\nerrore nell'input di s1\n");
        exit(-1);
    }else{
        printf("\ns1 ok...\n");
    }
    

    if(strlen(input.s2) != input.n){
        fprintf(stderr,"\nerrore nell'input di s2\n");
        exit(-1);
    }else{
        printf("\ns2 ok...\n");
    }


    return input;
}

char *replaceChar(char s1[], char s2[], char c){

    puts("");
    parametri input;
    char *s3 = (char*)malloc(sizeof(char)*input.n);
    char *sAppoggio = (char*)malloc(sizeof(char)*input.n);

    sAppoggio = s1;
    for(int i = 0; i < input.n; i++){
        if(s1[i] == c){
            sAppoggio[i] = s2[i];
        }
    }
    s3 = sAppoggio;

    return s3;
}

char *invertString(char s2[], size_t n){
    puts("");

    parametri input;
    char *s4 = (char*)malloc(sizeof(char)*input.n);

    int j = 0;
    for(int i = n-1; i >= 0; i--){
        s4[j] = s2[i];
        j++;
    }

    s4[n] = '\0';
    printf("\nla stringa s4 e' %s\n",s4);

    return s4;
}

char *sort(char s3[], char s4[], size_t n){

    puts("");
    size_t N = n*2;
    char *s5 = (char*)malloc(sizeof(char)*N);

    for(int i = 0; i < n; i++){
        s5[i] = s3[i];
    }
    for(int i = 0; i < n; i++){
        s5[n+i] = s4[i];
    }
    s5[N] = '\0';

    //bubble sort
    for(int i = 0; i < N-1; i++){
        for(int j = 0; j < N-1;j++){
            if(s5[j] > s5[j+1]){
                char temp = s5[j];
                s5[j] = s5[j+1];
                s5[j+1] = temp;
            }
        }
    }

    return s5;
}

void printResult(char s5[],size_t n){

    puts("");

    int N = n*2;
    for(int i = 0; i < N; i++){
        if((int)s5[i] %2 == 1){
            printf("*");
        }else{
            printf("%c",s5[i]);
        }
        
    }
    

}

